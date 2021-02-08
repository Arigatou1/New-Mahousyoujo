//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjCaution.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjCaution::Init()
{
	m_time = 0;
	Opacity = 0;
}

//アクション
void CObjCaution::Action()
{
	m_time++;

	if (m_time < 30)
	{
		Opacity += 3;
	}
	else if (m_time < 60)
	{
		Opacity -= 3;
	}
	else if(m_time < 90)
	{
		Opacity += 3;
	}
	else if (m_time < 120)
	{
		Opacity -= 3;
	}
	else if (m_time < 150)
	{
		Opacity += 3;
	}
	else if (m_time < 180)
	{
		Opacity -= 3;
	}

	if (m_time == 180)
	{
		this->SetStatus(false);
	}
}



//ドロー
void CObjCaution::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,Opacity / 100.0f };
	wchar_t str[128];

	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = 0;
	src.m_right = 800;
	src.m_bottom = 600;

	dst.m_top = 0;
	dst.m_left = 0;
	dst.m_right = 800;
	dst.m_bottom = 600;

	Draw::Draw(6, &src, &dst, c, 0.0f);
}