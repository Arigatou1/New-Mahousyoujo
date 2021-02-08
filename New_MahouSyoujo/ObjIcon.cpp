//使用するヘッダーファイル
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjIcon.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjIcon::Init()
{
}

//アクション
void CObjIcon::Action()
{
	//-------- 2021 2 1 舟瀬　変更--------
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
		if (obj_magicalgirl != nullptr)
		{
			b_skill = obj_magicalgirl->GetSkill() - 1;
		}




	//--------ここまで--------------------

	if (serect == false)
	{
		CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
		if (obj_magicalgirl != nullptr)
		{
			b_skill = obj_magicalgirl->GetSkill();
		}
	}
	else if(serect == true)
	{
		TutorialHero* obj_tutorialhero = (TutorialHero*)Objs::GetObj(OBJ_TUTORIALHERO);
		if (obj_tutorialhero != nullptr)
		{
			b_skill = obj_tutorialhero->GetSkill();
		}
		CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
		if (obj_tutorial != nullptr)
		{
 			i_order = obj_tutorial->GetOrder();
		}
	}

	//ヒール
	if (Graphic_Serct == 12)
	{
		if (b_skill == 1 )
		{
			Graphic_Serct = 13;
		}
	}
	else if (Graphic_Serct == 13)
	{
		if (b_skill != 1)
		{
			Graphic_Serct = 12;
		}
	}

	////バリア
	if (Graphic_Serct == 10)
	{
		if (b_skill == 2)
		{
			Graphic_Serct = 11;
		}

	}
	else if (Graphic_Serct == 11)
	{
		if (b_skill != 2)
		{
			Graphic_Serct = 10;
		}
	}

	////メテオ
	if (Graphic_Serct == 14)
	{
		if (b_skill == 3)
		{
			Graphic_Serct = 15;
		}

	}
	else if (Graphic_Serct == 15)
	{
		if (b_skill != 3)
		{
			Graphic_Serct = 14;
		}
	}

	if (i_order == 6 && Graphic_Serct == 13)
	{
		//順番6だったときヒールのアイコンを真ん中に大きく出す
		icon_size = 120;
		i_x = 250.0f;
		i_y = 250.0f;
	}
	else if (i_order == 7 && Graphic_Serct == 11)
	{
	//	//順番7だったときバリアのアイコンを真ん中に大きく出す
		icon_size = 120;
		i_x = 250.0f;
		i_y = 250.0f;
	}
	else if (i_order == 8 && Graphic_Serct == 15)
	{
	//	//順番8だったときメテオのアイコンを真ん中に大きく出す
	icon_size = 120;
		i_x = 250.0f;
		i_y = 250.0f;
	}
	else
	{
		icon_size = size_spare;
		i_x = x_spare;
		i_y = y_spare;
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
	dst.m_top = 0.0f;
	dst.m_left = 736.0f;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 192.0f;

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);

	//切り取り位置の設定
	src.m_top = 384.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 512.0f;

	//表示位置の設定
	dst.m_top = (b_skill * 64);
	dst.m_left = 736.0f;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);

}