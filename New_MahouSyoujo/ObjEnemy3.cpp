//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL\UserData.h"
#include"ObjEnemy3.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;

CObjEnemy3::CObjEnemy3(float x,float y)
{
	m_ex = x;
	m_ey = y;
	
}

//イニシャライズ
void CObjEnemy3::Init()
{

	m_vx = 2.0f;
	m_vy = 0.0f;
	e_hp = 20;
	e_damege = 0;

	e3_hit_up = false;
	e3_hit_down = false;
	e3_hit_left = false;
	e3_hit_right = false;

	e3_t = true;


	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY3, 1);

	a_time = 0;
}

//アクション
void CObjEnemy3::Action()
{
	a_time++;

	

	//摩擦
	//m_vx += -(m_vx * 0.098);

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	m_ex += m_vx;
	m_ey += m_vy;

	CObjBlock* obj_block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block3->BlockHit(&m_ex, &m_ey,
		&e3_hit_up, &e3_hit_down, &e3_hit_left, &e3_hit_right,
		&m_vx, &m_vy);

	//ジョンプ
	if (e3_hit_right == true)
	{
		m_vx = -1.0f;
		m_vy = -8.0f;
	}
	else if (e3_hit_left == true)
	{
		m_vx = +1.0f;
		m_vy = -8.0f;
	}

	//自由落下運動
	m_vy += 9.8 / (16.0f);


	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);

	if (obj != nullptr)
	{
	float m_mx = obj->GetX();

		if (m_mx+96 < m_ex) {
			m_vx = -2.0f;
		}
		else if (m_mx-96 > m_ex)
		{
			m_vx = 2.0f;
		}

		else
		{
			m_vx = 0;
		}

		if (m_mx+192 > m_ex && m_mx-192 < m_ex )
		{
			if (a_time % 100 == 0)
			{

				CObjShockWave* obj = new CObjShockWave(m_ex, m_ey);
				Objs::InsertObj(obj, OBJ_SHOCKWAVE, 49);


			}
		}

	}

	
	



	//バリア出てる時だけ止まる
	//バリアの情報
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex >= b_mx - 64.0f && m_ex <= b_mx)
		{
			m_vx = 0;
			m_ex = b_mx - 64.0f;
		}
		else if (m_ex <= b_mx + 128.0f && m_ex >= b_mx)
		{
			m_vx = 0;
			m_ex = b_mx + 128.0f;
		}

	}

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e_hp -= 10;
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_damege = obj_all->GetZ_ATK();
	}

	//剣に当たれば減らす
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e_hp -= obj_sword->GetAttackPower();
	}

	//弾に当たればHP減らす
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		e_hp -= 3;
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e_hp -= obj_bullet->GetAttackPower();
	}

	//hpが0になると消滅
	if (e_hp <= 0)
	{
		Audio::Start(2);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		((UserData*)Save::GetData())->enemyRemain -= 1;
		//Amount++;
	}
}

	



//ドロー
void CObjEnemy3::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 384.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 448.0f;
	//表示位置の設定
	dst.m_top =m_ey;
	dst.m_left = m_ex;
	dst.m_right =  m_ex+64.0f;
	dst.m_bottom =  m_ey+64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}