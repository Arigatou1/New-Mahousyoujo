//使用するヘッダーファイル
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjHeelIcon.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjHeelIcon::Init()
{
	Graphic_Serct = 0;
}

//アクション
void CObjHeelIcon::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		b_skill = obj_magicalgirl->GetSkill();
	}

	if (b_skill == 1)
	{
		Graphic_Serct = 13;
	}
	else
		Graphic_Serct = 12;
}
//ドロー
void CObjHeelIcon::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 200.0f;
	src.m_bottom = 200.0f;

	//表示位置の設定
	dst.m_top    = 128.0f;
	dst.m_left   = 736.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 192.0f;

	//描画
	Draw::Draw(Graphic_Serct, &src, &dst, c, 0.0f);
}