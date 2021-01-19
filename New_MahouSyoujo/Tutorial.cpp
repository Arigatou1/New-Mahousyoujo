//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\UserData.h"
#include "GameHead.h"
#include "Tutorial.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CTutorial::CTutorial()
{
	
}


//イニシャライズ
void CTutorial::Init()
{

	cond1 = false;
	cond2 = false;

	condreset = false;

	Order = 1;
}

//アクション
void CTutorial::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_skill = obj_magicalgirl->GetSkill();
	}

	if (Order == 1)//左右移動
	{
		
		if (Input::GetVKey(VK_LEFT) == true)
			cond1 = true;
		if (Input::GetVKey(VK_RIGHT) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 2)//ジャンプ
	{
		if (condreset == true)
		{
			cond1 = false; cond2 = false;
			condreset = false;
		}

		if (Input::GetVKey(' ') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 3)//攻撃
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
		}

		if (Input::GetVKey('F') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 4)//スキル変更
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey(VK_UP) == true)
			cond1 = true;
		if (Input::GetVKey(VK_DOWN) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 5)//ヒール
	{
		if (condreset == true)
		{
			cond1 = false; cond2 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 1)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 6)//バリア
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 2)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if(Order == 7)//メテオ
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 3)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
}

//ドロー
void CTutorial::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	if (Order == 1)
	{
		swprintf_s(str, L"条件1");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if(Order == 2)
	{
		swprintf_s(str, L"条件2");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 3)
	{
		swprintf_s(str, L"条件3");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 4)
	{
		swprintf_s(str, L"条件4");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 5)
	{
		swprintf_s(str, L"条件5");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 6)
	{
		swprintf_s(str, L"条件6");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 7)
	{
		swprintf_s(str, L"条件7");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 8)
	{
		swprintf_s(str, L"終わり");//整数を文字列か
		Font::StrDraw(str, 350, 336, 36, c);
	}
}