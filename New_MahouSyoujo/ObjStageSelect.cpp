//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjStageSelect::Init()
{
	m_key_flag = false;//キーフラグ
	cursor_x = 140;
	cursor_y = 64;
	 
	PageID = ((UserData*)Save::GetData())->Stage / 4;
	if (PageID >= 2)
		PageID = 0;
	MaxPage = 1;

	((UserData*)Save::GetData())->ManaHP = 0;
	((UserData*)Save::GetData())->HeroHP = 0;

	((UserData*)Save::GetData())->enemyRemain = 1;
	nowLoading=false;
	menuAllButtonX = 0.0f;
	waitTime = 0;
	tutorialStart = false;
}

//アクション
void CObjStageSelect::Action()
{
	//ステージ選択画面
	//今いるカーソルの場所から位置を取得し、
	//ステージIDを計算し設定するには？？

	if(cursor_y<448 && nowLoading==false)
		((UserData*)Save::GetData())->Stage = ((cursor_y - 32) / 96) +(PageID*4);

	//cursor_y = 16,96,176,256,336,416,496
	//カーソルの初期位置は16なので、
	//96から16を引き、80を出し、80で割ることで1が出てくる。
	//それに1を足す。

	//------------------------------------------------
	//キー操作
	if (!nowLoading)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Audio::Start(9);

				//チュートリアル開始します。表示してると気
				if (tutorialStart == true)
				{
					nowLoading = true;
					((UserData*)Save::GetData())->Stage = -1;
				}
				//チュートリアルまだやってない時
				else if(((UserData*)Save::GetData())->tutorialDone == false)
				{
					tutorialStart = true;
				}

				else if (((UserData*)Save::GetData())->tutorialDone == true)
				{
					if (cursor_y < 448)
					{
						StageStart();
					}

					if (cursor_y >= 448)
					{
						this->SetStatus(false);
						//メニューオブジェクト作成
						CObjCustomize* obj = new CObjCustomize();
						Objs::InsertObj(obj, OBJ_CUSTOMIZE, 2);
					}
				}
				m_key_flag = false;

			}
		}
		else if (Input::GetVKey(VK_UP) == true)
		{
			cursorUp();
		}
		else if (Input::GetVKey(VK_DOWN) == true)
		{
			cursorDown();
		}
		else if (Input::GetVKey(VK_LEFT) == true)
		{


			if (m_key_flag == true)
			{
				Audio::Start(10);

				if (PageID > 0)
					PageID -= 1;
				m_key_flag = false;
			}
		}

		else if (Input::GetVKey(VK_RIGHT) == true)
		{


			if (m_key_flag == true)
			{
				Audio::Start(10);

				if (PageID < MaxPage)
					PageID += 1;

				m_key_flag = false;

			}



		}
		else if (Input::GetVKey(VK_ESCAPE) == true)
		{

			if (m_key_flag == true)
			{
				Audio::Start(11);
				this->SetStatus(false);
				//メニューオブジェクト作成
				CObjModeSelect* obj = new CObjModeSelect();
				Objs::InsertObj(obj, OBJ_MODESELECT, 2);
			}
			m_key_flag = false;


		}
		else
		{
			m_key_flag = true;
		}
	
	}
	else if (nowLoading == true)
	{

		waitTime++;

		if (waitTime == 20)
		{
			//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout(8);
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}
		else if (waitTime > 20)
		{
			menuAllButtonX += 16;

			if (menuAllButtonX > 800)
			{
				Scene::SetScene(new CSceneMain());

			}
		}
	}
	
	
	//----------------------------------------------
	//カーソル位置調整
	if (cursor_y <448)
	{
		cursor_x = 140;
	}
	else//カスタマイズに合わせられたとき
	{
		cursor_x = 140;
	}

}

//ドロー
void CObjStageSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		//ステージセレクト
		for (int i = 0; i < 4; i++)
		{
			MenuBlockDraw(140+ menuAllButtonX, i * 96.0f + 64.0f, 512.0f, 80.0f, 1.0f, 0.0f, 0.0f, 1.0f);

		}

		MenuBlockDraw(140 + menuAllButtonX, 448.0f, 512.0f,80.0f, 1.0f, 0.2f, 1.0f, 1.0f);

		//カーソル描画
		MenuBlockDraw(cursor_x + menuAllButtonX, cursor_y, 512.0f, 80.0f, 1.0f, 0.8f, 0.0f, 1.0f);

		//矢印ボタン
		for (int i = 0; i < 2; i++)
			MenuBlockDraw(16 + i * 674.0f + menuAllButtonX, 156.0f, 96.0f, 200.0f, 0.0f, 0.0f, 1.0f, 1.0f);


		Font::StrDraw(L"←", 40 + menuAllButtonX, 240, 48, c);
		Font::StrDraw(L"→", 712 + menuAllButtonX, 240, 48, c);



		for (int i = 0; i < 4; i++)
		{
			wchar_t str[128];
			swprintf_s(str, L"ステージ%d", i + 1 + (PageID * 4));

			Font::StrDraw(str, 230 + menuAllButtonX, 61 + (i * 96) + 8, 72, c);
		}

		

		Font::StrDraw(L"カスタマイズ", 175 + menuAllButtonX, 452, 72, c);
		
		MenuBlockDraw(-32, 0.0f, 864.0f, 56.0f, 0.1f, 0.6f, 0.1f, 0.7f);
		if (cursor_y < 448)
		{

			//そのときのスコア表示
			wchar_t Score[16];
			swprintf_s(Score, L"ハイスコア:%d", ((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage]);
			Font::StrDraw(Score, 2 + menuAllButtonX, 2, 48, c);
		}

			//遊べるか遊べないかの表示
			if(cursor_y==448)
				Font::StrDraw(L"武器の変更などを行うことができます。", 376, 2, 24, c);
			else if (((UserData*)Save::GetData())->Clear_Flag[((UserData*)Save::GetData())->Stage] == true)
				Font::StrDraw(L"このステージは遊ぶことができます。", 400, 2, 24, c);
			else
				Font::StrDraw(L"このステージはまだ遊べません。", 400, 2, 24, c);


			

			MenuBlockDraw(0, 560.0f, 800.0f, 48.0f, 0.1f, 0.1f, 0.1f, 0.7f);

			Font::StrDraw(L"↑↓キー:移動  Enter:決定  Esc:戻る", 200, 566, 26, c);
		
			if (tutorialStart == true)
			{
				MenuBlockDraw(100, 100.0f,600.0f, 400.0f, 1.1f, 0.1f, 0.1f, 0.9f);
				Font::StrDraw(L"チュートリアルを開始します。", 200, 300, 26, c);
			}
}


void CObjStageSelect::cursorUp()
{
	if (m_key_flag == true)
	{
		//音を再生する
		Audio::Start(10);
		//カーソル移動
		cursor_y -= 96;

		m_key_flag = false;
	}

	//カーソルが画面が行かない処理(上)
	if (cursor_y < 64)
		cursor_y = 448;

}

void CObjStageSelect::cursorDown()
{

	if (m_key_flag == true)
	{
		//音を再生する
		Audio::Start(10);
		//カーソル移動
		cursor_y += 96;

		m_key_flag = false;
	}

	//カーソルの移動制限
	if (cursor_y > 448)
		cursor_y = 64;

}

void CObjStageSelect::StageStart()
{
	//そのステージが解放されているかをチェックする。
	if (((UserData*)Save::GetData())->Clear_Flag[((UserData*)Save::GetData())->Stage] == true)
	{
		nowLoading = true;
	}
}