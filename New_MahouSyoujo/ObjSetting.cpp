//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjSetting.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjSetting::Init()
{
	cursor_x = 32;
	cursor_y = 64;
	nowSelect = 0;
}

//アクション
void CObjSetting::Action()
{

	//カーソルの位置からnowSelectを取得する。
	nowSelect = (cursor_y - 64) / 112;


	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Save::Seve();

			this->SetStatus(false);
			//メニューオブジェクト作成
			CObjModeSelect* obj = new CObjModeSelect();
			Objs::InsertObj(obj, OBJ_MODESELECT, 0);
		}
	}


	else if (Input::GetVKey(VK_UP) == true)
	{
		//選択
		Audio::Start(4);
		
		if (m_key_flag == true)
		{
			cursor_y -= 112;

			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		
		if (m_key_flag == true)
		{

			cursor_y += 112;

			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		
	
		if (m_key_flag == true)
		{
			switch (nowSelect)
			{
			case 0:
				if(((UserData*)Save::GetData())->Diffculty>0)
				((UserData*)Save::GetData())->Diffculty--;
				break;

			default:

				break;
			}



			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{

		if (m_key_flag == true)
		{


			switch (nowSelect)
			{
			case 0:
				if (((UserData*)Save::GetData())->Diffculty < 2)
					((UserData*)Save::GetData())->Diffculty++;
				break;

			default:

				break;
			}


			m_key_flag = false;
		}
	}
	else
		m_key_flag = true;

	//カーソルが画面が行かない処理(上)
	if (cursor_y < 64)
		cursor_y = 64;

	if (cursor_y > 176)
		cursor_y = 176;
}

//ドロー
void CObjSetting::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	Font::StrDraw(L"GAME Setting", 2, 2, 32, c);

	MenuBlockDraw(32, 64.0f, 728.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);

	MenuBlockDraw(cursor_x, cursor_y, 728.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);

	wchar_t str1[128];
	wchar_t Diff[16];

	switch (((UserData*)Save::GetData())->Diffculty)
	{
	case 0:
		swprintf_s(Diff, L"EASY");
		break;

	case 1:
		swprintf_s(Diff, L"NORMAL");
		break;
		
	case 2:
		swprintf_s(Diff, L"HARD");
		break;
	}


	swprintf_s(str1, L"難易度:%s",Diff);
	Font::StrDraw(str1, 32, 64, 64, c);


}

//MenuBlockDraw関数
