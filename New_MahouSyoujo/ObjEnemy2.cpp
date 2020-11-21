//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjEnemy2.h"
#include "GameL/Audio.h"
#include "GameL\UserData.h"


//使用するネームベース
using namespace GameL;


//コンストラクタ
CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//イニシャライズ
void CObjEnemy2::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	e2_hp = 18;
	e2_atk = 0.5;
	e2_damege = 0;
	e2_time = 0;

	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;


	//blockとの衝突状態確認用
	e2_hit_up = false;
	e2_hit_down = false;
	e2_hit_left = false;
	e2_hit_right = false;

	e2_t = true;
	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY2, 10);
	//Amount = 0;

}

//アクション
void CObjEnemy2::Action()
{


	if (e1_hit_right == true)
	{
		m_ex = m_ex - 40.0f;
		m_ey = m_ey - 80.0f;
	}
	else if (e1_hit_left == true)
	{
		m_ex = m_ex + 25.0f;
		m_ey = m_ey - 80.0f;
	}

	e2_time++;

	if (e2_time % 96 == 32)
	{
		e2_atk = 0.00;
	}
	else if (e2_time % 96 == 0)
	{
		e2_atk = 0.04;
	}


	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey + 14);

	//重力
	m_vy += 9.8 / (16.0f);

	//マナの位置で停止
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();
		if (e2_hit_down == true)
		{
			if (m_mx + 64.0f <= m_ex)
				m_vx = -1.5f;
			else if (m_mx - 64.0f >= m_ex)
				m_vx = 1.5f;
			else
				m_vx = 0;
		}
	}


	//ジョンプ
	if (e2_hit_right == true)
	{
		m_ex = m_ex - 5.0f;
		m_ey = m_ey - 60.0f;
	}
	else if (e2_hit_left == true)
	{
		m_ex = m_ex + 5.0f;
		m_ey = m_ey - 60.0f;
	}

	//バリア出てる時だけ止まる
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex == b_mx - 48.0f || m_ex == b_mx + 160.0f)
		{
			m_vx = 0;
		}
	}

	//m_vxの速度で移動
	m_ex += m_vx;
	m_ey += m_vy;


	CObjBlock* obj_block2 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block2->BlockHit(&m_ex, &m_ey,
		&e2_hit_up, &e2_hit_down, &e2_hit_left, &e2_hit_right,
		&m_vx, &m_vy);


	//マナに当たるとカウントが0になる
	if (hit->CheckObjNameHit(OBJ_MANA) != nullptr)
	{
		if (e2_t == true)
		{
			e2_time = 0;
			e2_t = false;
		}
	}

	//攻撃間隔
	e2_time++;

	if (e2_time % 96 == 32)
	{
		;
	}
	else if (e2_time % 96 == 0)
	{
		;
	}

	//魔法少女の弾に当たれば消滅
	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e2_hp -= 3;
		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e2_damege = obj_homing->GetM_ATK();

	}

	//全体攻撃の魔法に当たれば消滅
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e2_hp -= 10;
		CObjAllBullet* obj_allb = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e2_damege = obj_allb->GetZ_ATK();
		//Amount++;
	}

	//剣に当たれば消滅
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e2_hp -= obj_sword->GetAttackPower();
	}

	//弾(主人公)に当たれば消滅
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		e2_hp -= 3;
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e2_hp -= obj_bullet->GetAttackPower();
	}


	//hpが0になると消滅
	if (e2_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		
			//モンスターが倒された時の効果音
			Audio::Start(2);
			((UserData*)Save::GetData())->enemyRemain -= 1;
	}
}


//ドロー
void CObjEnemy2::Draw()
{
	//描画カラー情報
	float c[4] = { 0.4f,1.0f,0.3f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 320.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 384.0f;
	//表示位置の設定
	dst.m_top = m_ey+14;
	dst.m_left = m_ex+50.0f;
	dst.m_right = m_ex + 0.0f;
	dst.m_bottom = m_ey + 64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
float CObjEnemy2::GetE2_ATK()
{
	return e2_atk;
}