//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Objbarrier.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjBarrier::CObjBarrier(float x)
{
	mb_x = x;
}

//イニシャライズ
void CObjBarrier::Init()
{
	b_time = 0;
}

//アクション
void CObjBarrier::Action()
{
	/*CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		b_skill = obj_magicalgirl->GetSkill();
		b_mp = obj_magicalgirl->GetMP();
		b_time = obj_magicalgirl->GetBTime();
	}

	if (b_mp >= 30)
	{
		if (Input::GetVKey('D') == true && b_t == true && b_skill == 2)
		{
			b_t = false;
		}
		else if (Input::GetVKey('D') == false && b_time > 300)
		{
			b_t = true;
		}
	}*/

	// 2021 01 28 舟瀬 変更
	b_time++;

	if (b_time >= 300)
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
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 64.0f;
	src.m_bottom = 640.0f;

	//表示位置の設定
	dst.m_top    = -2.0f;
	dst.m_left   = mb_x + 0.0f;
	dst.m_right  = mb_x + 32.0f;
	dst.m_bottom = 602.0f;

	//描画
	Draw::Draw(5, &src, &dst, c, 0.0f);
}
float CObjBarrier::GetBX()
{
	return mb_x;
}