//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjShockWave.h"
#include "GameL\UserData.h"
#include "UtilityModule.h"

//使用するネームベース
using namespace GameL;

//コンストラクタ
CObjShockWave::CObjShockWave(float x, float y, float vx, float vy)
{
	m_ex = x;
	m_ey = y;
	m_vx = vx;
	m_vy = vy;
}
//イニシャライズ
void CObjShockWave::Init()
{

	//blockとの衝突状態確認用
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_t = true;

	//当たり判定用のHITBOXを作成
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_SHOCKWAVE, 10);


	//主人公機で角度をとる

	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	float x = obj->GetX() - m_ex;
	float y = obj->GetY() - m_ey;
	float ar = atan2(-y, x) * 180.0f / 3.14f;

	if (ar < 0)
		ar = 360 - abs(ar);

	//m_vxの速度で移動

	m_vx = cos(3.14 / 180 * ar);

	m_vy = -sin(3.14 / 180 * ar);


}

//アクション
void CObjShockWave::Action()
{
	m_ex += m_vx*2;
	m_ey += m_vy*2;

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	///ここをコメントアウトしたら例外が起こらなくなったので、
	/// 近々書き直す必要があるかもしれません。
	/// ReleaseMode 舟瀬 12/07

	//バリアの情報
/*	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex >= b_mx - 50.0f && m_ex <= b_mx + 128.0f)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

	}*/




	//領域外に出たら削除する

	bool check = CheckWindow(m_ex,m_ey, -64.0f, -64.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	
	//移動ベクトルの正規化
	UnitVec(&m_vx, &m_vy);

	//マナに当たると削除
	if (hit->CheckObjNameHit(OBJ_MANA) != nullptr)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
	///ここをコメントアウトしたら例外が起こらなくなったので、
	/// 近々書き直す必要があるかもしれません。
	/// ReleaseMode 舟瀬 12/07

	//バリアの情報
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex >= b_mx - 50.0f && m_ex <= b_mx + 128.0f)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
		}

	}
}

//ドロー
void CObjShockWave::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	float r = 0.0f;

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 448.0f;
	src.m_left = 128.0f;
	src.m_right = 192.0f;
	src.m_bottom = 512.0f;
	//表示位置の設定
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 64.0f;
	dst.m_bottom = m_ey + 64.0f;

	//主人公機で角度をとる

	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	float x = obj->GetX() - m_ex;
	float y = obj->GetY() - m_ey;
	r = atan2(-y, x) * 180.0f / 3.14f;

	if (r < 0)
		r = 360 - abs(r);


	//描画
	Draw::Draw(0, &src, &dst, c, r);
}
