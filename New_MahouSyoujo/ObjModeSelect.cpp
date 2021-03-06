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


	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Audio::Start(9);

			this->SetStatus(false);
			switch (nowSelect)
			{
			case 0:
			{
				//メニューオブジェクト作成
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT, 2);

				break;
			}
			case 1:
			{
				//エンドレスメニューオブジェクト作成
				CObjMenuEndless* obj2 = new CObjMenuEndless();
				Objs::InsertObj(obj2, OBJ_STAGEENDLESS, 2);

				break;
			}
			case 2:
			{
				//っ設定
				CObjSetting* sett = new CObjSetting();
				Objs::InsertObj(sett, OBJ_SETTING, 2);

				break;
			}
			default:
			{
				//メニューオブジェクト作成
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT,2);
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

			Audio::Start(10);

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
			Audio::Start(10);
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

			Audio::Start(10);
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
				Audio::Start(10);
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
				Audio::Start(11);
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
		cursor_x = 40;
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

	MenuBlockDraw(cursor_x, cursor_y, cursor_sx, cursor_sy, 1, 0.8, 0, 1);
	
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
	
	case 1:
		wchar_t Score[16];

		//そのときのスコア表示
		swprintf_s(Score, L"ハイスコア:%d", ((UserData*)Save::GetData())->ScoreData[16]);
		Font::StrDraw(Score, 2, 2, 32, c);

		break;

	default:

		Font::StrDraw(L"ゲームに関する設定を変更します。", 2, 2, 32, c);
	
		break;

	}


	MenuBlockDraw(0, 560.0f, 800.0f, 48.0f, 0.1f, 0.1f, 0.1f, 0.7f);

	Font::StrDraw(L"↑↓キー:移動  Enter:決定  Esc:戻る", 200, 566, 26, c);

}
