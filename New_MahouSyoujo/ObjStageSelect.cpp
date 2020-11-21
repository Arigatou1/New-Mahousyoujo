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
	MaxPage = 4;

	((UserData*)Save::GetData())->ManaHP = 0;
	((UserData*)Save::GetData())->HeroHP = 0;

	((UserData*)Save::GetData())->enemyRemain = 1;
}

//アクション
void CObjStageSelect::Action()
{
	//ステージ選択画面
	//今いるカーソルの場所から位置を取得し、
	//ステージIDを計算し設定するには？？

	if(cursor_y<512)
		((UserData*)Save::GetData())->Stage = ((cursor_y - 32) / 112) +(PageID*4);

	//cursor_y = 16,96,176,256,336,416,496
	//カーソルの初期位置は16なので、
	//96から16を引き、80を出し、80で割ることで1が出てくる。
	//それに1を足す。

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			if (((UserData*)Save::GetData())->Clear_Flag[((UserData*)Save::GetData())->Stage] == true)
			{
				if (cursor_y < 512)
					Scene::SetScene(new CSceneMain());
		}
			if (cursor_y >= 512)
			{
				this->SetStatus(false);
				//メニューオブジェクト作成
				CObjCustomize* obj = new CObjCustomize();
				Objs::InsertObj(obj, OBJ_CUSTOMIZE, 0);
			}
			m_key_flag = false;
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
	else if (Input::GetVKey(VK_DOWN) == true )
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
			if (PageID > 0)
				PageID -= 1;
			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		
	
		if (m_key_flag == true)
		{
			if (PageID < MaxPage )
				PageID += 1;

			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_ESCAPE) == true)
	{

		if (m_key_flag == true)
		{
			this->SetStatus(false);
			//メニューオブジェクト作成
			CObjModeSelect* obj = new CObjModeSelect();
			Objs::InsertObj(obj, OBJ_MODESELECT, 0);
		}
		m_key_flag = false;


	}
	else
	{
		m_key_flag = true;
	}

	//カーソルが画面外いかない処理
	if (cursor_y < 64)
		cursor_y = 512;

	if (cursor_y > 512)
		cursor_y = 64;



	

}

//ドロー
void CObjStageSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };



	
	
	//ステージセレクト
	for (int i = 0; i < 4; i++)
	{
		MenuBlockDraw(140, i * 112.0f + 64.0f, 512.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);
		
	}

	MenuBlockDraw(140, 512.0f, 512.0f, 96.0f, 1.0f, 0.2f, 1.0f, 1.0f);
	//if()

	MenuBlockDraw(cursor_x, cursor_y, 512.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);


	for (int i = 0; i < 2; i++)
		MenuBlockDraw(16 + i * 674.0f, 200.0f, 96.0f, 200.0f, 0.0f, 0.0f, 1.0f, 1.0f);
	
	
	for (int i = 0; i < 4; i++)
	{
		wchar_t str[128];
		swprintf_s(str,L"ステージ%d",i+1+ (PageID * 4));
		
		Font::StrDraw(str, 196, 64+(i*112)+8, 80, c);
	}

	Font::StrDraw(L"←", 40, 284, 48, c);

	Font::StrDraw(L"→", 712, 284, 48, c);

	Font::StrDraw(L"カスタマイズ", 156, 512 , 80, c);
	wchar_t Score[16];

	//そのときのスコア表示
	swprintf_s(Score, L"スコア:%d", ((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage]);
	Font::StrDraw(Score, 2,2, 48, c);

	//遊べるか遊べないかの表示
	if (((UserData*)Save::GetData())->Clear_Flag[((UserData*)Save::GetData())->Stage] == true)
	Font::StrDraw(L"このステージは遊ぶことができます。", 400, 2, 24, c);
	else 
		Font::StrDraw(L"このステージは遊べません。", 400, 2, 24, c);

}

