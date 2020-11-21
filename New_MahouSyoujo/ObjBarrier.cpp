//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Objbarrier.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBarrier::CObjBarrier(float x, float y)
{
	mb_x = x;
	mb_y = y;
}

//イニシャライズ
void CObjBarrier::Init()
{
	b_time = 100;
}

//アクション
void CObjBarrier::Action()
{
	b_time++;

	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		b_skill = obj_magicalgirl->GetSkill();

	}

	if (Input::GetVKey('H') == true && b_t == true && b_skill == 2)
	{
		b_time = 0;
		b_t = false;
	}
	else if (Input::GetVKey('H') == false && b_time > 200)
	{
		b_t = true;
	}

	if (b_time >= 200)
	{
		this->SetStatus(false);
	}
}
//ドロー
void CObjBarrier::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top    = 256.0f;
	src.m_left   = 128.0f;
	src.m_right  = 192.0f;
	src.m_bottom = 320.0f;

	//表示位置の設定
	dst.m_top    = mb_y - 384.0f;
	dst.m_left   = mb_x + 0.0f;
	dst.m_right  = mb_x + 32.0f;
	dst.m_bottom = mb_y + 224.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
float CObjBarrier::GetBX()
{
	return mb_x;
}