//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include "ObjBoss1.h"
#include "GameL\UserData.h"

//使用するネームベース
using namespace GameL;

//コンストラクタ
CObjBoss1::CObjBoss1(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
//イニシャライズ
void CObjBoss1::Init()
{
	m_vx = 0;
	m_vy = 0;

	//全体攻撃一回だけダメージ与える　　与えない＝false   与える＝true
	allbullet_hit = true;

	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	a_time = 0;

	maxhp = 800;
	e_hp = maxhp;

	m_posture = m_ex<400?0:1;
	
	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 250, 250, ELEMENT_ENEMY, OBJ_BOSS1, 10);

	//ゲージオブジェクト作成
	CObjGaugeBoss* obj_gboss = new CObjGaugeBoss(m_ex-25,m_ey+272);
	Objs::InsertObj(obj_gboss, OBJ_GAUGEBOSS, 51);


}

//アクション
void CObjBoss1::Action()
{

	
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
	if (a_time % 100 == 0)
	{
		Audio::Start(28);

		CObjSlimeBall* obj = new CObjSlimeBall(m_posture == 1?m_ex:m_ex+186, m_ey + 50.0f,-15.0f,4.0f);
		Objs::InsertObj(obj, OBJ_SLIMEBALL, 49);
		


	}

	if (a_time % 500 == 0)
	{
		Audio::Start(29);
		//場所と発射速度を設定できるようにした。
		CObjEnemy* obj = new CObjEnemy(m_posture == 1 ? m_ex : m_ex + 186,m_ey+50, m_posture == 1 ? -5:+5,-10);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		obj = new CObjEnemy(m_posture == 1 ? m_ex : m_ex + 186, m_ey + 50, m_posture == 1 ? -5 : 5,0);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		
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
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr && allbullet_hit == true)
	{
		CObjAllBullet* obj_allbullet = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_hp -= obj_allbullet->GetZ_ATK();
		allbullet_hit = false;
	}
	else if(hit->CheckObjNameHit(OBJ_ALLBULLET) == nullptr)
		allbullet_hit = true;

	//hpが0になると消滅
	if (e_hp <= 0)
	{
		Audio::Start(31);

		if (((UserData*)Save::GetData())->Stage != 16)
			((UserData*)Save::GetData())->enemyRemain = 0;

		EnemyAppear* obj_appear = (EnemyAppear*)Objs::GetObj(OBJ_APPEAR);

		obj_appear->BossDisappearnce();

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//ドロー
void CObjBoss1::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 320.0f;
	src.m_left = 0.0f+(m_posture*64.0f);
	src.m_right = 64.0f - (m_posture * 64.0f);
	src.m_bottom = 384.0f;
	//表示位置の設定
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 250.0f;
	dst.m_bottom = m_ey + 250.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

