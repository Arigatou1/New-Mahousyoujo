//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjBullet.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBullet::CObjBullet(float x, float y, int posture, bool m_f)
{
	px = x;
	py = y;

	b_posture = posture;
	b_f = m_f;
}

//イニシャライズ
void CObjBullet::Init()
{
	Hits::SetHitBox(this, px, py+24, 64, 16, ELEMENT_PLAYER, OBJ_BULLET, 1);
	
	atk_power = 5 - ((UserData*)Save::GetData())->Diffculty;
}

//アクション
void CObjBullet::Action()
{

	//HitBOxの内容を変更
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(px, py+24);

	if (b_posture == 1)
		px += 36;
	else
		px -= 36;
	

	//当たり判定を行うオブジェクト情報部
	int database[6] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ENEMY3,
		OBJ_ENEMY4,
		OBJ_SMALLSLIM,
		OBJ_BOSS1,
	};

	for(int i=0;i<6;i++)
	{

		if (hit->CheckObjNameHit(database[i])!=nullptr)
		{
			this->SetStatus(false);
				Hits::DeleteHitBox(this);
		}

		//Amount++;
	}

	//領域外に出たら削除する

	bool check = CheckWindow(px, py, -64.0f, -64.0f, 800.0f, 600.0f);
	if (check == false)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//ドロー
void CObjBullet::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元ffｆ切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 192.0f;
	src.m_left = 128.0f;
	src.m_right = 192.0f;
	src.m_bottom = 256.0f;

	//表示位置の設定
	dst.m_top =py+0.0f;
	dst.m_left = (b_posture*32)+px+32.0f;
	dst.m_right = (b_posture*-32)+px+32.0f;
	dst.m_bottom = py+64.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

//攻撃力を返す関数
float CObjBullet::GetAttackPower()
{
	return atk_power;
}