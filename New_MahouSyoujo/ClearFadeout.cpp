//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "ClearFadeout.h"
#include "GameL\UserData.h"
#include "GameL\DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/Audio.h"


//使用するネームベース
using namespace GameL;

Fadeout::Fadeout(int speed,bool fadeIn)
{
	fadeSpeed = speed;
	pfadeIn = fadeIn;
}

//イニシャライズ
void Fadeout::Init()
{

	if (pfadeIn)//フェードイン
		shootDownTime = 100;
	else//フェードアウト
		shootDownTime = 1;
}

//アクション
void Fadeout::Action()
{
	if (pfadeIn)
	{
		//フェードイン
		shootDownTime -= fadeSpeed;
	}
	else
	{
	
		//フェードアウト
		shootDownTime += fadeSpeed;
	}

	if (shootDownTime <= 0)
	{
		//フェードインとき、0以下になると削除
		this->SetStatus(false);
	}
}

//ドロー
void Fadeout::Draw()
{
	
		//描画カラー情報
		float c[4] = { 0.0f,0.0f,0.0f,shootDownTime / 100.0f };

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//描画
		Draw::Draw(50, &src, &dst, c, 0.0f);
	
}

