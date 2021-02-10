//使用するヘッダーファイル
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjIcon.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjIcon::CObjIcon(float x,float y,float size, bool s)
{
	i_x = x;
	i_y = y;
	icon_size = size;
	serect = s;
}

//イニシャライズ
void CObjIcon::Init()
{
}

//アクション
void CObjIcon::Action()
{
	//-------- 2021 2 1 舟瀬　変更--------
	if (serect == false)
	{
		CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
		if (obj_magicalgirl != nullptr)
		{
			b_skill = obj_magicalgirl->GetSkill() - 1;
		}
	}
	else if (serect == true)
	{
		TutorialHero* obj_tutorialhero = (TutorialHero*)Objs::GetObj(OBJ_TUTORIALHERO);
		if (obj_tutorialhero != nullptr)
		{
			b_skill = obj_tutorialhero->GetSkill() - 1;
		}
	}

}
//ドロー
void CObjIcon::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 384.0f;

	//表示位置の設定
	dst.m_top = i_y;
	dst.m_left = i_x;
	dst.m_right = dst.m_left + 64.0f * icon_size;
	dst.m_bottom = dst.m_top + 192.0f * icon_size;

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);

	//切り取り位置の設定
	src.m_top = 384.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = i_y + (b_skill * 64) * icon_size;
	dst.m_left = i_x;
	dst.m_right = dst.m_left + 64.0f * icon_size;
	dst.m_bottom = dst.m_top + 64.0f * icon_size;

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);
}