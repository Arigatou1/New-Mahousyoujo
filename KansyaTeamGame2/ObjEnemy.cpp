//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjEnemy.h"
#include "GameL\UserData.h"

#include "GameL\UserData.h"
#include "GameL/Audio.h"


//使用するネームベース
using namespace GameL;

//コンストラクタ
CObjEnemy::CObjEnemy(float x, float y,float vx,float vy)
{
	m_ex = x;
	m_ey = y;
	m_vx = vx;
	m_vy = vy;
}
//イニシャライズ
void CObjEnemy::Init()
{
	
	e1_damege = 0;
	e1_time = 0;
	e1_anime = 1;

	//最大HP
	e_hp = 15;
	

	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_t = true;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY, 10);

}

//アクション
void CObjEnemy::Action()
{
	e1_time++;

	//マナの位置で停止
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();
		if (e1_hit_down == true)
		{

			if (m_mx + 65.0f <= m_ex)
				m_vx = -1.5f;
			else if (m_mx - 65.0f >= m_ex)
				m_vx = 1.5f;
			else
			{
				m_vx = 0;
				e1_t = false;
			}
		}
		
		
		//マナの手前に停止して攻撃する間隔
				//120ごとに攻撃する(マナより右側)
		if (m_mx <= m_ex && e1_t ==false)
		{
			if (e1_time % 120 == 0)
			{
				m_ex = m_ex - 10.0f;
				e1_anime = 3;
			}
			else
			{
				m_ex = m_mx + 66.0f;
				e1_anime = 1;
			}
		}
		//120ごとに攻撃する(マナより左側)
		else if (m_mx >= m_ex && e1_t ==false)
		{
			if (e1_time % 120 == 0)
			{
				m_ex = m_ex + 10.0f;
				e1_anime = 3;
			}
			else
			{
				m_ex = m_mx - 66.0f;
				e1_anime = 1;
			}
		}
		
		//ジョンプ
		if (e1_hit_right == true)
		{
			m_ex = m_ex - 5.0f;
			m_ey = m_ey - 60.0f;
		}
		else if (e1_hit_left == true)
		{
			m_ex = m_ex + 5.0f;
			m_ey = m_ey - 60.0f;
		}
	}

	//バリアの情報
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex == b_mx - 48.0f || m_ex == b_mx + 128.0f)
		{
			m_vx = 0;
			m_vy = 0;
		}

	}

	//重力
	m_vy += 9.8 / (16.0f);

	//m_vxの速度で移動
	m_ex += m_vx;
	m_ey += m_vy;

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey+14);


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);


	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e_hp -= 3;
		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e1_damege = obj_homing->GetM_ATK();

		if (e_hp <= 0) 
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			
			//モンスターが倒された時の効果音
			Audio::Start(2);
		}
		
		//Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e_hp -= 10;
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e1_damege = obj_all->GetZ_ATK();
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

	//hpが0になると消滅
	if(	e_hp <= 0)
	{
		//モンスターが倒された時の効果音
		Audio::Start(2);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		((UserData*)Save::GetData())->enemyRemain -= 1;
		//Amount++;
	}

}

//ドロー
void CObjEnemy::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top    = 320.0f;
	src.m_left   = e1_anime * 64.0f - 64.0f;
	src.m_right  = e1_anime * 64.0f;
	src.m_bottom = 384.0f;
	//表示位置の設定
	dst.m_top    = m_ey+14;
	dst.m_left	 = m_ex+50.0f;
	dst.m_right  = m_ex + 0.0f;
	dst.m_bottom = m_ey + 64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

//int CObjEnemy::EneAmo()
//{
//	return Amount;
//}