//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include "ObjDragon.h"
#include "GameL\UserData.h"


#include <stdlib.h>
#include <time.h>

//使用するネームベース
using namespace GameL;

//コンストラクタ
CObjDragon::CObjDragon(float x, float y)
{
	m_ex = x;
	m_ey = y;

}
//イニシャライズ
void CObjDragon::Init()
{
	b_posture = 0;

	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	a_time = 0;

	maxhp = 1800;
	e_hp = maxhp;

	//全体攻撃一回だけダメージ与える　　与えない＝false   与える＝true
	AllBullet_Hit = true;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 256, 256, ELEMENT_ENEMY, OBJ_DRAGON, 10);



	//ゲージオブジェクト作成
	CObjGaugeBoss* obj_gboss = new CObjGaugeBoss(m_ex - 25, m_ey+272);
	Objs::InsertObj(obj_gboss, OBJ_GAUGEBOSS, 51);

	//ランダム
	unsigned int now = (unsigned int)time(0);

	srand(now);

	shootDownTime = 0;

	attack_now = false;

	lastAttack = 1;

	fireBressOn = false;
}

//アクション
void CObjDragon::Action()
{
	a_time++;

	rand(); rand(); rand();

	if (!attack_now)
	{
		
			if (a_time == 240)
			{
				do {
				AttackPattern = rand() % 4;
				a_time = 0;
				attack_now = true;
				} while (lastAttack == AttackPattern);//最後の攻撃と今の攻撃が一緒な場合、やり直す
			}
		
			//最後のアタックは今のアタック
		lastAttack = AttackPattern;

	}
	else if (attack_now)
	{
		if (AttackPattern == 1)
		{
			fireBressOn = true;
			if (a_time >= 200)
			{
				a_time = 0;
				attack_now = false;
				fireBressOn = false;
			}
		
		}
		else if (AttackPattern == 0)
		{
			if(a_time<=120)
			{

					m_ey -= 2;
				
			}
			else if (a_time <= 180)
			{
			
				m_ey += 1;

			}
			else if (a_time <= 240)
			{
				m_ey -= 1;
			}
			else if (a_time <= 300)
			{
				m_ey += 1;
			}
			else if (a_time <= 360)
			{
				m_ey -= 1;
			}
			else if (a_time <= 480)
			{
				m_ey += 2;
			}

			if (a_time >= 480)
			{
				a_time = 0;
				attack_now = false;
			}
		}
		else if (AttackPattern == 2)
		{
			if (a_time <= 120)
			{
				m_ey -=5;
			}

			else if (a_time == 240)
			{
				if (b_posture == 0)
				{
					b_posture = 1;
					m_ex = -32;
				}
				else if (b_posture == 1)
				{
					b_posture = 0;
					m_ex = 576;
				}


			}
			else if (a_time >=240&&a_time <= 360)
			{
				m_ey += 5;
			}


		
			if (a_time >= 360)
			{
				a_time = 0;
				attack_now = false;
			}
		}

		else if (AttackPattern == 3)
		{
			if (a_time <= 120)
			{
				m_ey -= 2;
			}
			else if (a_time <= 180)
			{
				m_ey += 1;
				fireBressOn = true;
			}
			else if (a_time <= 240)
			{
				m_ey -= 1;
			

			}
			else if (a_time <= 300)
			{
				m_ey += 1;
				
				
			}
			else if (a_time <= 360)
			{
				m_ey -= 1;
				
			}
			else if (a_time <= 480)
			{
				m_ey += 2;
			}

			if (a_time >= 480)
			{
				a_time = 0;
				attack_now = false;
				fireBressOn = false;
			}
		}
	}

	//重力
	m_vy += 9.8 / (16.0f);


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);
	//


		//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	


	if (a_time >= 600)
	{
		a_time = 0;
	}


	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e_hp -= obj_sword->GetAttackPower();
	}
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e_hp -= obj_bullet->GetAttackPower();
	}
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr && AllBullet_Hit == true)
	{
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_hp -= obj_all->GetZ_ATK();
		AllBullet_Hit = false;
	}
	else if (hit->CheckObjNameHit(OBJ_ALLBULLET) == nullptr)
		AllBullet_Hit = true;

	//hpが0になると消滅
	if (e_hp <= 0)
	{
		((UserData*)Save::GetData())->enemyRemain = 0;

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;

	}

	if (fireBressOn)
		FireBress();
}

//ドロー
void CObjDragon::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;
	//表示位置の設定
	dst.m_top = m_ey;
	dst.m_left = m_ex+(256.0f*b_posture);
	dst.m_right = dst.m_left + 256.0f-(256.0f*b_posture*2);
	dst.m_bottom = dst.m_top + 256.0f;

	//描画
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

int CObjDragon::GetHP()
{
	return e_hp;
}

int CObjDragon::GetMAXHP()
{
	return maxhp;
}
void CObjDragon::FireBress()
{
	if (a_time % 10 == 0)
	{

		CObjFireBall* obj = new CObjFireBall(m_ex + (256.0f - 64.0f) * b_posture, m_ey + 50.0f, -3.5f + (b_posture * 7.0f), 5.0f);
		Objs::InsertObj(obj, OBJ_FIREBALL, 49);
	}
}
