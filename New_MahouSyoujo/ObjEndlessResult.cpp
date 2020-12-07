//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "GameL\UserData.h"
#include "ObjEndlessResult.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjEndlessResult::Init()
{
	
	Score = 0;
	m_key_flag = false;
}

//アクション
void CObjEndlessResult::Action()
{

	//スコアを計算
	
	Score = ((UserData*)Save::GetData())->HeroHP;


	//すこあを保存
	//ここは問題なさそう。
	if (((UserData*)Save::GetData())->ScoreData[16] < Score)
	{
		((UserData*)Save::GetData())->ScoreData[16] = Score;
	}




	//エンターキーを押してシーン:ゲームMenuに移行する
	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Scene::SetScene(new CSceneMenu());
			m_key_flag = false;
		}
	}

	else
	{
		m_key_flag = true;
	}
}

//ドロー
void CObjEndlessResult::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 960.0f;
	src.m_bottom = 600.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 500.0f;
	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

	wchar_t str[128];

	swprintf_s(str, L"スコア:%.0f", Score);//整数を文字列か
	Font::StrDraw(str, 240, 412, 72, c);


}