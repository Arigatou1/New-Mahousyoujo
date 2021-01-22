//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "TutorialHero.h"
#include "ObjSword.h"
#include "GameL\UserData.h"


//使用するネームスペース
using namespace GameL;

TutorialHero::~TutorialHero()
{

}

//イニシャライズ
void TutorialHero::Init()
{
	m_px = 200;
	m_py = 200;
	m_vx = 0;
	m_vy = 0;
	m_posture = 1;
	m_anime = 0;
	m_anitime = 0;
	atk_anime = 0;
	atk_anitime = 0;
	atk_time = 0;

	m_time = 0;
	m_num = 100;
	
	m_f = true;
	isJump = true;
	//最大HP
	max_hp = 20.0f;
	m_hp = max_hp;
	//無敵時間調整用
	mtk_max = 130 - ((UserData*)Save::GetData())->Diffculty * 30;
	mtk_jkn = mtk_max;
	m_mtk = false;

	//あたり判定用Hitboxを作成
	Hits::SetHitBox(this, m_px + 8, m_py + 8, 56, 56, ELEMENT_PLAYER, OBJ_HERO, 1);

	Weapon = ((UserData*)Save::GetData())->weapon;
	damage = ((UserData*)Save::GetData())->Diffculty * 0.5;
	AllDamage = 0;

	shootDownTime = 0;

	clear_check = false;

}

//アクション
void TutorialHero::Action()
{

	CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
	if (obj_tutorial != nullptr)
	{
		m_order = obj_tutorial->GetOrder();
	}

	m_time++;
	if (m_time >= m_num)
		m_time = 0;
	//-------------------------------------
	//キー入力

	if (!clear_check)
	{
		if (m_order == 1)
		{
			m_num = 320;
			//右に移動
			if (m_time <= 80 && m_time >= 0)
			{
				m_vx += 0.1f;
				m_posture = 1;

				m_anitime += 1;
			}
			else if (m_time <= 240 && m_time >= 160)//左に移動
			{
				m_vx -= 0.1f;
				m_posture = -1;

				m_anitime += 1;
			}
			else
			{
				//どちらも押していない場合は減速させる。
				m_anime = 1;
				m_anitime = 0;
				m_vx = m_vx * 0.9;
			}
		}
		else if (m_order == 2)
		{
			m_num = 180;
			m_vx = m_vx * 0.9;

			m_posture = 1;
			m_anime = 1;

			if(m_time >=88 && m_time <=92)
			m_py -= 20.0f;
		}
		else if (m_order == 3)//攻撃用
		{
			if (m_time == 50)
				Weapon = 1;
			else if (m_time == 100)
				Weapon = 2;
			else
			{
				Weapon = 0;
				atk_anime = 0;
			}

			if (Weapon == 1)
			{
				atk_anime = 2;

				CObjBullet* obj_bullet = new CObjBullet(m_px + (m_posture * 48), m_py, m_posture, false);
				Objs::InsertObj(obj_bullet, OBJ_BULLET, 51);
			}
			else if(Weapon == 2)
			{
				atk_anime = 1;

				CObjSword* obj_b = new CObjSword(m_px + (m_posture * 48.0f), m_py, m_posture, false);
				Objs::InsertObj(obj_b, OBJ_SWORD, 51);
			}
		}

		
		//回復
		if (Input::GetVKey('D') == true)
		{
			CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
			if (obj_magicalgirl != nullptr)
			{
				m_hp = obj_magicalgirl->GetHP();
			}
		}

	}
	//キー入力
	//--------------------------------------------------

	//歩く時のアニメーション anitimeが10になったとき、コマを1つ進める
	if (m_anitime >= 8)
	{
		m_anime++;

		m_anitime = 0;
	}

	if (m_anime >= 4)
		m_anime = 0;


	//---------------------------------------

	//画面外に行かないように
	if (m_px > 600)
	{
		m_px = 600;
		m_vx = 0;
	}
	else if (m_px < 200)
	{
		m_px = 200;
		m_vx = 0;
	}
	if (m_py > 400)
	{
		m_py = 400;
		m_vy = 0;
	}
	else if (m_py < 200)
	{
		m_py = 200;
		m_vy = 0;
	}

	//無敵時間が無効になった時 敵とのあたり判定を行う
	if (m_mtk == false)
	{
		//HitBoxの内容を元に戻す
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_px + 4.0f, m_py + 4.0f);

		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			//ダメージ
			m_mtk = true;
			m_hp -= 1.0f + damage;//敵の攻撃力
			AllDamage += 1.0f + damage;
			m_vx = 0.0f;
		}
	}
	//無敵がtrueになった時
	else if (m_mtk == true)
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

	//--------------------------
	//最終的な速度

	//最高速度決定
	if (m_vx >= 6)
		m_vx = 6;
	if (m_vx <= -6)
		m_vx = -6;

	//自由落下運動
	m_vy += 9.8 / (16.0f);

	//ベクトルから座標に変換
	m_px += m_vx;
	m_py += m_vy;

	//----------------------------
}
//ドロー
void TutorialHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,mtk_jkn % 3 };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	if (!clear_check)
	{
		//切り取り位置の設定
		src.m_top = (atk_anime * 64) + 0.0f;
		src.m_left = (AniData[m_anime] * 64) + 0.0f;
		src.m_right = (AniData[m_anime] * 64) + 64.0f;
		src.m_bottom = (atk_anime * 64) + 64.0f;
		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = (32.0f * m_posture) + m_px + 32.0f;
		dst.m_right = (-32.0f * m_posture) + m_px + 32.0f;
		dst.m_bottom = 64.0f + m_py;

		//描画
		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
	else
	{
		//切り取り位置の設定
		src.m_top = 192.0f;
		src.m_left = 128.0f;
		src.m_right = src.m_left + 64.0f;
		src.m_bottom = src.m_top + 64.0f;
		//表示位置の設定
		dst.m_top = 0.0f + m_py;
		dst.m_left = m_px + 0.0f;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 64.0f + dst.m_top;

		//描画
		Draw::Draw(3, &src, &dst, c, 0.0f);
	}


}