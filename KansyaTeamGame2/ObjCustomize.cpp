//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjCustomize.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjCustomize::Init()
{
	m_key_flag = false;//キーフラグ
	
	cursor_x = 32.0f;
	cursor_y = 64.0f;
	nowSelect = 0;
}

//アクション
void CObjCustomize::Action()
{

	//カーソルの位置からnowSelectを取得する。
	nowSelect = (cursor_y - 64) / 112;




	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			

			this->SetStatus(false);
			//メニューオブジェクト作成
			CObjStageSelect* obj = new CObjStageSelect();
			Objs::InsertObj(obj, OBJ_STAGESELECT, 0);
		}
	}

	else if (Input::GetVKey(VK_UP) == true)
	{
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
				if (((UserData*)Save::GetData())->weapon==1)
				{
					((UserData*)Save::GetData())->weapon = 0;
				}
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
				if (((UserData*)Save::GetData())->weapon == 0)
				{
					((UserData*)Save::GetData())->weapon = 1;
				}
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

	//defaultセッティング
	if(((UserData*)Save::GetData())->weapon >1 || ((UserData*)Save::GetData())->weapon < 0)
	((UserData*)Save::GetData())->weapon = 0;

}

//ドロー
void CObjCustomize::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	Font::StrDraw(L"GAME Customize", 2, 2, 32, c);

	MenuBlockDraw(32, 64.0f, 728.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);

	MenuBlockDraw(cursor_x, cursor_y, 728.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);

	wchar_t str1[128];

	swprintf_s(str1, L"主人公の武器:%d", ((UserData*)Save::GetData())->weapon);
	Font::StrDraw(str1, 32, 64, 64, c);


	

	//切り取り位置の設定
	src.m_top =0.0f;
	src.m_left = 64.0f;
	src.m_right =  128.0f;
	src.m_bottom = 64.0f;
	//表示位置の設定
	dst.m_top = 0.0f ;
	dst.m_left =  332.0f;
	dst.m_right =  396.0f;
	dst.m_bottom = 64.0f;

	//描画
	for(int i=0;i<4;i++)
	Draw::Draw(0, &src, &dst, c, i*90.0f);
}

//MenuBlockDraw関数
