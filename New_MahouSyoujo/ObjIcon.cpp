//使用するヘッダーファイル
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjIcon.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjIcon::CObjIcon(int size ,float x,float y, int g ,bool s)
{
	icon_size = size;
	i_x = x;
	i_y = y;
	Graphic_Serct = g;
	serect = s;

	size_spare = size;
	x_spare = x;
	y_spare = y;
}

//イニシャライズ
void CObjIcon::Init()
{
}

//アクション
void CObjIcon::Action()
{
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

	//バリア
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

	//メテオ
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
		//順番7だったときバリアのアイコンを真ん中に大きく出す
		icon_size = 120;
		i_x = 250.0f;
		i_y = 250.0f;
	}
	else if (i_order == 8 && Graphic_Serct == 15)
	{
		//順番8だったときメテオのアイコンを真ん中に大きく出す
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
	src.m_right = 200.0f;
	src.m_bottom = 200.0f;

	//表示位置の設定
	dst.m_top = i_y;
	dst.m_left = i_x;
	dst.m_right = dst.m_left + icon_size;
	dst.m_bottom = dst.m_top + icon_size;

	//描画
	Draw::Draw(Graphic_Serct, &src, &dst, c, 0.0f);
}