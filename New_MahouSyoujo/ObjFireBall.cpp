//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjFireBall.h"
#include "GameL\UserData.h"
#include "UtilityModule.h"

//使用するネームベース
using namespace GameL;

//コンストラクタ
CObjFireBall::CObjFireBall(float x, float y, float vx, float vy)
{
	m_ex = x;
	m_ey = y;
	m_vx = vx;
	m_vy = vy;
}
//イニシャライズ
void CObjFireBall::Init()
{

	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_xsize = 64.0f;
	e1_ysize = 64.0f;

	e1_t = true;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_FIREBALL, 10);

	m_vx = -14.0f;
	m_vy = 20.0f;

	hitGround = false;
	hitTime = 100.0f;
}

//アクション
void CObjFireBall::Action()
{


	m_ex += m_vx;
	m_ey += m_vy;

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);




	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);



	if (e1_hit_down == true)
	{
		hitGround = true;
	}

	if (hitGround == true)
	{
		hitTime -= 1.0f;
		m_vx = -14.0f;
		m_vy = -2.0f;
	}
	//hitTimeが0に
	if (hitTime <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//移動ベクトルの正規化
	UnitVec(&m_vx, &m_vy);
}

//ドロー
void CObjFireBall::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,hitTime / 100.0f};

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 192.0f;
	src.m_left = 256.0f;
	src.m_right = 320.0f;
	src.m_bottom = 256.0f;
	//表示位置の設定
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 64.0f;
	dst.m_bottom = m_ey + 64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
