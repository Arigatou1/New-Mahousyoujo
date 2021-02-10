//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "GameL\UserData.h"
#include "ObjGameClear.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGameClear::Init()
{
	StageID = 0;
	Score = 0;
	HeroDamage = 0.0f;
	ManaDamage = 0.0f;
}

//アクション
void CObjGameClear::Action()
{

	//スコアを計算
	///おそらく、ここの処理でバグが発生していることが分かったんで、
	/// 書き直していくことにする。
	/// しかし、スコアの情報だけでなく、クリアフラグの情報までも巻き込んで消してしまうのは
	/// なぜだろうか？
	//((UserData*)Save::GetData())->Score =
	//	(((UserData*)Save::GetData())->HeroHP * 40 + ((UserData*)Save::GetData())->ManaHP * 60);
	ManaDamage = ((UserData*)Save::GetData())->ManaHP;
	HeroDamage = ((UserData*)Save::GetData())->HeroHP;

	//追記
	//うまくいったかもしれない。

    Score =	(4000.0f-HeroDamage*80.0f) + (6000-ManaDamage*60.0f);

	if (Score < 0)
	{
		//スコアは0より小さくならない
		Score = 0;
	}

	//すこあを保存
	//ここは問題なさそう。
	StageID = ((UserData*)Save::GetData())->Stage;
	if(((UserData*)Save::GetData())->ScoreData[StageID]<Score)
	{
		((UserData*)Save::GetData())->ScoreData[StageID] = Score;
	}
	
	((UserData*)Save::GetData())->Clear_Flag[StageID + 1] = true;

	Save::Seve();
					

	//エンターキーを押してシーン:ゲームMenuに移行する
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Audio::Start(9);
				Scene::SetScene(new CSceneMenu(1));
				m_key_flag = false;
			}
		}

		else
		{
			m_key_flag = true;
		}
}

//ドロー
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;
	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);

	wchar_t str[128];
	
	swprintf_s(str, L"プレイヤーが受けたダメージ:%.2f", HeroDamage);//整数を文字列か
	Font::StrDraw(str, 150, 336, 36, c);

	swprintf_s(str, L"マナが受けたダメージ:%.2f", ManaDamage);//整数を文字列か
	Font::StrDraw(str, 150, 384, 36, c);
	
	swprintf_s(str, L"10000 - %.2f×80 - %.2f×60 =", HeroDamage, ManaDamage);//整数を文字列か
	Font::StrDraw(str, 50, 444, 18, c);

	swprintf_s(str, L"スコア:%.0f", Score);//整数を文字列か
	Font::StrDraw(str, 300, 476, 72, c);

	
	
	
	
}