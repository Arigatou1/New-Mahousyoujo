//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

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
	if (((UserData*)Save::GetData())->enemyRemain==0)
	{
		//HPがゼロになったら、待機時間を増価させる。
		shootDownTime++;

		if (shootDownTime == 200)
		{
			//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout();
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}

		else if (shootDownTime > 300)
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
	//swprintf_s(str, L"操作方法:←→移動 Spaceジャンプ F攻撃 H魔法攻撃");//整数を文字列か
	
	
	//swprintf_s(str, L"スコア:%d", ((UserData*)Save::GetData())->Score);//整数を文字列か
	
	//-1以下の時以外表示する
	if(((UserData*)Save::GetData())->enemyRemain>=0)
	Font::StrDraw(str, 2, 96, 24, c);

}