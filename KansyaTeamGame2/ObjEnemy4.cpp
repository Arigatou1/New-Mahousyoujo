#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL\UserData.h"
#include "ObjEnemy4.h"


CObjEnemy4::CObjEnemy4(float x, float y)
{
	m_ex = x;
	m_ey = y;
	e_hp = 5;
}

//イニシャライズ
void CObjEnemy4::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	m_r = 0.0f;

	

	//当たり判定HitBoxを作成
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY4, 10);

	e_hp = 8.0f;
}

//アクション
void CObjEnemy4::Action()
{
	m_ex += 2*m_vx;

	//
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	//CObjHero* obj_h = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();

		if (m_mx <= m_ex)
			m_vx = -1.0f;
		else if (m_mx >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;
	}

	//HitBoxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex+0.0f, m_ey+0.0f);

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e_hp -= 1;
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e4_damege = obj_all->GetZ_ATK();

		e_hp <= 0;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//Amount++;
	}

	//弾に当たれば消滅
	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e_hp -= 1;
		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e4_damege = obj_homing->GetM_ATK();

		e_hp <= 0;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e_hp -= 1;
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e4_damege = obj_all->GetZ_ATK();
	}

	//剣に当たれば消滅
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e_hp -= obj_sword->GetAttackPower();
	}

	//hpが0になると消滅
	if (e_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		((UserData*)Save::GetData())->enemyRemain -= 1;
	}

}

//ドロー
void CObjEnemy4::Draw()
{
	//描画カラー情報
	float c[4] = { 2.0f,2.0f,2.0f,2.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 448.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 512.0f;
	
	//表示位置の設定
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 64.0f;
	dst.m_bottom = m_ey + 64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}