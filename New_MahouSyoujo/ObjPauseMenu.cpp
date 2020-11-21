//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjPauseMenu.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL\DrawTexture.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjPauseMenu::Init()
{
	m_key_flag = false;//キーフラグ
	cursor_x = 40;
	cursor_y = 96;
	nowSelect = 0;
	cursor_sx = 320;
	cursor_sy = 256;
}

//アクション
void CObjPauseMenu::Action()
{
	
}

//ドロー
void CObjPauseMenu::Draw()
{
	//描画カラー情報
	float c[4] = { 0.5f,0.5f,0.5f,0.5f };

	RECT_F src;
	RECT_F dst;

	if (((UserData*)Save::GetData())->PauseMenu == true)
	{

		src.m_top = 0;
		src.m_left = 0;
		src.m_right = 1;
		src.m_bottom = 1;

		dst.m_top = 0;
		dst.m_left = 0;
		dst.m_right = 800;
		dst.m_bottom = 600;

		Draw::Draw(0, &src, &dst, c, 0.0f);

		for (int i = 0; i < 4; i++)
			c[i] = 1.0f;
		


		Font::StrDraw(L"PAUSE", 336, 268, 64, c);

		Font::StrDraw(L"[Esc]:モードセレクト", 236, 368, 32, c);
		Font::StrDraw(L"[Enter]:ゲームに戻る", 236, 468, 32, c);
	
	}
}

//MenuBlockDraw関数
