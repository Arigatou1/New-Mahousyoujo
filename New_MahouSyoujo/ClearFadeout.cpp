//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "ClearFadeout.h"
#include "GameL\UserData.h"
#include "GameL\DrawFont.h"
#include "GameL/WinInputs.h"


//使用するネームベース
using namespace GameL;


//イニシャライズ
void Fadeout::Init()
{
	shootDownTime = 0;
}

//アクション
void Fadeout::Action()
{
	//残り敵の数が0になったとき
	if (((UserData*)Save::GetData())->enemyRemain == 0)
	{

		shootDownTime++;

		if (shootDownTime >= 400)
			Scene::SetScene(new CSceneGameClear());
	}
}

//ドロー
void Fadeout::Draw()
{
	if (shootDownTime >= 300)
	{
		//描画カラー情報
		float c[4] = { 0.0f,0.0f,0.0f,(shootDownTime - 300) / 100.0f };

		RECT_F src;//描画元切り取り位置
		RECT_F dst;//描画先表示位置

		//切り取り位置の設定
		src.m_top = 0.0f;
		src.m_left = 192.0f;
		src.m_right = 192 + 64.0f;
		src.m_bottom = 64.0f;
		//表示位置の設定
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//描画
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}