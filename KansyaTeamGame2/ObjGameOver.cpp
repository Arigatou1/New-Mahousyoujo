//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjGameOver.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameOver::Init()
{
	m_key_flag = false;//キーフラグ
}

//アクション
void CObjGameOver::Action()
{
	//Escキーを押してシーン:ゲームTitleに移行する
	if (Input::GetVKey(VK_ESCAPE) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneTitle());
			m_key_flag = false;
		}
	}
	//Enterキーを押してリトライする
	else if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMain());
			m_key_flag = false;
		}
	}
	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjGameOver::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };


	Font::StrDraw(L"GAME OVER", 230, 240, 72, c);

	Font::StrDraw(L"[Esc]:タイトルへ", 236, 368, 32, c);
	Font::StrDraw(L"[Enter]:リトライ", 236, 468, 32, c);
}