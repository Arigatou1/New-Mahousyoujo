//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjSword.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"


//使用するネームスペース
using namespace GameL;

CObjHero::~CObjHero()
{

}

//イニシャライズ
void CObjHero::Init()
{
	m_px = 0;
	m_py = 0;
	m_vx = 0;
	m_vy = 0;
	m_posture = 1;
	m_anime = 0;
	m_anitime = 0;
	atk_anime = 0;
	atk_anitime = 0;
	atk_time = 0;
	m_f = true;
	isJump = true;
	//最大HP
	max_hp = 20.0f;
	m_hp = max_hp;
	//無敵時間調整用
	mtk_max = 130-((UserData*)Save::GetData())->Diffculty * 30;
	mtk_jkn = mtk_max;
	m_mtk = false;
	
	//blockとの衝突状態確認用
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;


	//あたり判定用Hitboxを作成
	Hits::SetHitBox(this, m_px+8, m_py+8, 56, 56, ELEMENT_PLAYER, OBJ_HERO, 1);

	Weapon = ((UserData*)Save::GetData())->weapon;
	damage = ((UserData*)Save::GetData())->Diffculty * 0.5;
	AllDamage = 0;
}

//アクション
void CObjHero::Action()
{
	
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_mp = obj_magicalgirl->GetMP();
		m_Skill = obj_magicalgirl->GetSkill();
	}

		//Spaceキーを押すとジャンプする処理
		if (Input::GetVKey(' ') == true && m_hit_down == true && isJump == true)
		{
			//jump
			Audio::Start(6);
			m_vy = -15;
			isJump = false;
		}
		else if (Input::GetVKey(' ') == false)
		{
			isJump = true;
		}

		//自由落下運動
		m_vy += 9.8 / (16.0f);

		CObjBlock* obj_block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		obj_block->BlockHit(&m_px, &m_py,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);

		//キーを押すと移動
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx -= 0.1;
			m_posture = -1;

			m_anitime += 1;

		}
		else if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx += 0.1;
			m_posture = 1;

			m_anitime += 1;


		}
		//どちらも押していない場合は減速させる。
		else
		{

			m_anime = 1;
			m_anitime = 0;
			m_vx = m_vx * 0.9;
		}

		//歩く時のアニメーション anitimeが10になったとき、コマを1つ進める
		if (m_anitime >= 8)
		{
			m_anime++;

			m_anitime = 0;
		}

		if (m_anime >= 4)
			m_anime = 0;

		//最高速度決定
		if (m_vx >= 6)
			m_vx = 6;
		if (m_vx <= -6)
			m_vx = -6;

		//ベクトルから座標に変換
		m_px += m_vx;
		m_py += m_vy;

		
		//攻撃用
		if (Input::GetVKey('F') == true && m_f == true)
		{
			
		
			if (Weapon == 1)
			{
				m_f = false;
				atk_anime = 2;
				//銃声
				Audio::Start(5);

				CObjBullet* obj_bullet = new CObjBullet(m_px+(m_posture*48), m_py, m_posture, m_f);
				Objs::InsertObj(obj_bullet, OBJ_BULLET, 51);
			}

			else
			{
				m_f = false;
				atk_anime = 1;


				//剣を振る音
				Audio::Start(0);

				CObjSword* obj_b = new CObjSword(m_px, m_py, m_posture, m_f);
				Objs::InsertObj(obj_b, OBJ_SWORD, 1);
			}
			

		}

		if (m_f == false)
			atk_time++;

		//攻撃してからしばらく、攻撃判定が作れないようにしている。
		//一定時間たつと、作れるようにしている。
		if (atk_time >= 8)
		{
			atk_anime = 0;
			if (Input::GetVKey('F') == false)
			{
				m_f = true;
				atk_time = 0;

			}
		}





		//画面外に行かないように
		if (m_px > 744)
		{
			m_px = 744;
			m_vx = 0;
		}
		else if (m_px < 0)
		{
			m_px = 0;
			m_vx = 0;
		}


		//敵に当たった時に行うようにする。

		//無敵時間が無効になった時
		if (m_mtk == false)
		{ 
			//HitBoxの内容を元に戻す
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(m_px + 4.0f, m_py + 4.0f);

			if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
			{
				//ダメージ
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.0f + damage;//敵の攻撃力
				AllDamage += 1.0f + damage;
			}

			if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
			{
				//ダメージ
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.4f + damage;//敵の攻撃力
				AllDamage += 1.4f + damage;

			}

			if (hit->CheckObjNameHit(OBJ_ENEMY3) != nullptr)
			{
				//ダメージ
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 2.0f+damage;//敵の攻撃力
				AllDamage += 2.0f + damage;
			}

			if (hit->CheckObjNameHit(OBJ_ENEMY4) != nullptr)
			{
				//ダメージ
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 2.5f+damage;//敵の攻撃力
				AllDamage += 2.5f + damage;
			}

			if (hit->CheckObjNameHit(OBJ_SMALLSLIM))
			{
				//ダメージ
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.0f + damage;//敵の攻撃力
			}

			if (hit->CheckObjNameHit(OBJ_SLIMEBALL))
			{
				//ダメージ
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 0.5f + damage;
				AllDamage += 0.5f + damage;//敵の攻撃力
			}
		}
		//無敵がtrueになった時
		if (m_mtk == true)
		{
			//HitBoxの内容を更新
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(m_px + 9999, m_py);
			//無敵時間を減らす
			mtk_jkn -= 1;

			if (mtk_jkn <= 0)//無敵時間が0になったとき
			{
				m_mtk = false;
				mtk_jkn = mtk_max;
			}
	
		}

		//魔法少女の回復魔法
		if (m_mp >= 20)
		{
			if (m_hp < max_hp)
			{
				if (Input::GetVKey('H') == true && h_t == true && m_Skill == 1)
				{
					h_t = false;
					m_hp += 3.0f;
					m_mp -= 20;
					if (m_hp > max_hp)
					{
						m_hp = max_hp;
					}
				}
				else if (Input::GetVKey('H') == false)
				{
					h_t = true;
				}
			}
		}

		//主人公のHPが無くなった時、消滅させる
		if (m_hp <= 0)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

			Scene::SetScene(new CSceneGameOver());
		}

		//テスト用
		if (Input::GetVKey('1')==true)
		{
		
			Scene::SetScene(new CSceneGameClear());
		}

		//テスト用
		if (Input::GetVKey('2') == true)
		{

			Scene::SetScene(new CSceneMain());
		}


		//クリアシーンにスコアを与える
		((UserData*)Save::GetData())->HeroHP = AllDamage;
		
	
}
//ドロー
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
		//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,mtk_jkn%3};

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top =(atk_anime*64)+0.0f;
	src.m_left =(AniData[m_anime]*64)+0.0f;
	src.m_right =(AniData[m_anime] *64)+64.0f;
	src.m_bottom = (atk_anime * 64) + 64.0f;
	//表示位置の設定
	dst.m_top = 0.0f+m_py;
	dst.m_left =(32.0f*m_posture)+m_px+32.0f;
	dst.m_right = (-32.0f*m_posture )+ m_px+32.0f;
	dst.m_bottom = 64.0f+m_py;

	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
}

int CObjHero::GetHP()
{
	return m_hp;
}

int CObjHero::GetMAXHP()
{
	return max_hp;
}

int CObjHero::GetMP()
{
	return m_mp;
}