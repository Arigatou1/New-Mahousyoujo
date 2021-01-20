//使用するヘッダーファイル
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjMeteorIcon.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMeteorIcon::Init()
{
	Graphic_Serct = 0;
}

//アクション
void CObjMeteorIcon::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		b_skill = obj_magicalgirl->GetSkill();
	}

	if (b_skill == 3)
	{
		Graphic_Serct = 15;
	}
	else
		Graphic_Serct = 14;
}
//ドロー
void CObjMeteorIcon::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//表示位置の設定
	dst.m_top    = 0.0f;
	dst.m_left   = 736.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 64.0f;

	//描画
	Draw::Draw(Graphic_Serct, &src, &dst, c, 0.0f);
}