//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjEnemyAmount.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjEnemyAmount::Init()
{
	EnemyAmount = 0;
	shootDownTime = 0;
}

//アクション
void CObjEnemyAmount::Action()
{
	if (((UserData*)Save::GetData())->enemyRemain==0 && ((UserData*)Save::GetData())->HPZeroCheck==false)
	{
		//HPがゼロになったら、待機時間を増価させる。
		shootDownTime++;
	
		if (shootDownTime == 1)
		{
			/// <summary>
			///		シーンメインのロードを早く終わらせるために変えた処理。
			/// こうするしかなかったんだ__________
			/// </summary>
			switch (((UserData*)Save::GetData())->Stage + 1)
			{
			case 1:
				Audio::Stop(14);
				break;
			case 2:
			case 3:
			case 4:
				Audio::Stop(15);
				break;
			case 5:
			case 6:
				Audio::Stop(17);
				break;
			case 7:
				Audio::Stop(18);
				break;
			case 8:
				Audio::Stop(19);
				break;
			default:
				break;
			}
			Audio::Stop(16);
			Audio::Start(13);
			
			
		}
	    else if (shootDownTime == 200)
		{
		//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout();
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}

		else if (shootDownTime == 300)
		{
			Scene::SetScene(new CSceneGameClear());
		}
	}
}



//ドロー
void CObjEnemyAmount::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];




	swprintf_s(str, L"残り敵の数:%d", ((UserData*)Save::GetData())->enemyRemain);//整数を文字列か
	
	//swprintf_s(str, L"スコア:%d", ((UserData*)Save::GetData())->Score);//整数を文字列か
	
	//-1以下の時以外表示する
	if(((UserData*)Save::GetData())->enemyRemain>=0)
	Font::StrDraw(str, 2, 96, 24, c);


	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = 192;
	src.m_right =256;
	src.m_bottom =64;

	dst.m_top = 560;
	dst.m_left = 0;
	dst.m_right = 800;
	dst.m_bottom = 600;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	for (int i = 0; i < 3; i++)
	{
		c[i] = 1.0f;
	}

	swprintf_s(str, L"操作方法:←→移動　↑↓魔法切り替え 　Space:ジャンプ  F攻撃  D魔法");//整数を文字列か
	Font::StrDraw(str, 2, 566, 24, c);

}