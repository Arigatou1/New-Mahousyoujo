//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjModeSelect.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjModeSelect::Init()
{
	m_key_flag = false;//キーフラグ
	cursor_x = 40;
	cursor_y = 96;
	nowSelect = 0;
	cursor_sx = 320;
	cursor_sy = 256;
	countStage = 0;

	Save::Seve();
}

//アクション
void CObjModeSelect::Action()
{
	//モード選択画面
	//今いるカーソルの場所から位置を取得し、
	//モード設定する

	//nowSelect = ((cursor_x - 40) / 400) ;

	//cursor_x = 40,440
	//カーソルの初期位置は40なので、
	//440から40を引き、400を出し、400で割ることで1が出てくる。
	

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			this->SetStatus(false);
			switch (nowSelect)
			{
			case 0:
			{
				//メニューオブジェクト作成
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT, 0);

				break;
			}
			case 2:
			{
				//っ設定
				CObjSetting* sett = new CObjSetting();
				Objs::InsertObj(sett, OBJ_SETTING, 0);

				break;
			}
			default:
			{
				//メニューオブジェクト作成
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT, 0);
				break;
			}
			}
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
	
	
		if (m_key_flag == true)
		{
			//どこにいてもステージセレクトにカーソルを合わせる。
			nowSelect=0;
			cursor_x = 40;
			cursor_y = 96;
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_RIGHT)==true)
	{
		
		if (m_key_flag == true)
		{
			//どこにいてもエンドレスモードにカーソルを合わせる。
			nowSelect=1;
			cursor_x = 440;
			cursor_y = 96;
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
	
		if (m_key_flag == true)
		{
			
			//どこにいても設定にカーソルを合わせる。
			nowSelect = 2;
			cursor_x = 200;
			cursor_y = 450;
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
	
		
		if (cursor_y >= 450)
		{
			if (m_key_flag == true)
			{
				//下にいるときだけステージセレクトにカーソルを合わせる。
				nowSelect = 0;
				cursor_x = 40;
				cursor_y = 96;
			}
			m_key_flag = false;
		}
		
	}
	else if (Input::GetVKey(VK_ESCAPE) == true)
	{

			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneTitle());
			}
			m_key_flag = false;


	}
	else
	{
		m_key_flag = true;
	}

	//カーソルが画面買い行かない処理
	if (cursor_x > 440)
	{
		cursor_x = 440;
	}
	else if (cursor_x < 40)
	{
		cursor_x = 40;
	}

	if (cursor_x == 200 && cursor_y == 450)
	{
		cursor_sx = 400;
		cursor_sy = 72;
	}
	else
	{
		cursor_sx = 320;
		cursor_sy = 256;
	}
}

//ドロー
void CObjModeSelect::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//ステセレ・エンドレボタン
	for (int i = 0; i < 2; i++)
		MenuBlockDraw(40 + (i * 400), 96, 320, 256, 1, 0, 0, 1);

	//設定ボタン
	MenuBlockDraw(200, 450, 400, 72, 0.5f, 0, 1, 1);

	//カーソル描画
	MenuBlockDraw(cursor_x, cursor_y, cursor_sx, cursor_sy, 1, 0.8, 0, 1);
	
	//Font::StrDraw(L"GAME ModeSelect", 2, 2, 32, c);

	Font::StrDraw(L"ステージセレクト", 72, 200, 32, c);

	Font::StrDraw(L"エンドレスモード", 472, 200, 32, c);

	Font::StrDraw(L"設定", 360, 460, 48, c);

	switch (nowSelect)
	{
	case 0:

		countStage = 0;
		//ClearFlagは0はかならずtrue.
		//falseかそれ以外になるまで続ける。
		for (int i = 0; ((UserData*)Save::GetData())->Clear_Flag[i] != false; i++)
		{
			countStage++;
		}


		wchar_t str[128];
		swprintf_s(str, L"現在のステージ到達数:%d", countStage - 1);
		Font::StrDraw(str, 2, 2, 32, c);

		break;
	
	case 2:
	
		break;

	default:
	
		break;

	}

	
}
