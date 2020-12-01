//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjDragon.h"
#include "GameL\UserData.h"

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


	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	a_time = 0;

	maxhp = 1800;
	e_hp = maxhp;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 256, 256, ELEMENT_ENEMY, OBJ_DRAGON, 10);



	//ゲージオブジェクト作成
	CObjGaugeBoss* obj_gboss = new CObjGaugeBoss();
	Objs::InsertObj(obj_gboss, OBJ_GAUGEBOSS, 51);

	shootDownTime = 0;
}

//アクション
void CObjDragon::Action()
{



	//timeが500になったとき上昇する
	if (a_time >= 500 && a_time <= 600)
	{
		m_ey -= 2;
	}


//Y座標が100になるまで上昇する
	if (a_time >= 600 && a_time <= 650)
	{
		m_ey += 1;
	}
	if (a_time >= 650 && a_time <= 700)
	{
		m_ey -= 1;
	}
	if (a_time >= 700 && a_time <= 750)
	{
		m_ey += 1;
	}
	if (a_time >= 750 && a_time <= 800)
	{
		m_ey -= 1;
	}
	if (a_time >= 800 && a_time <= 900)
	{
		m_ey += 2;
	}


	//100に到達したら、100->200->100をしばらく繰り返す


	//また下げる



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

	a_time++;
	if (a_time >= 600 && a_time<=800)
	{
		if (a_time % 10 == 0)
		{

			CObjFireBall* obj = new CObjFireBall(m_ex, m_ey + 50.0f, -15.0f, 4.0f);
			Objs::InsertObj(obj, OBJ_FIREBALL, 49);
		}
	}

	if (a_time >= 900)
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
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_hp -= obj_all->GetZ_ATK();
	}

	//hpが0になると消滅
	if (e_hp <= 0)
	{
		((UserData*)Save::GetData())->enemyRemain = 0;
		return;

	}
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
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;
	//表示位置の設定
	dst.m_top = m_ey-128;
	dst.m_left = m_ex-96;
	dst.m_right = dst.m_left + 512.0f;
	dst.m_bottom = dst.m_top + 512.0f;

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

