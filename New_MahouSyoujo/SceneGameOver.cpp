//STLデバッグ機能OFFにする

#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneGameOver.h"
#include "GameHead.h"
#include "GameL\UserData.h"

//コンストラクタ
CSceneGameOver::CSceneGameOver()
{

}
//デストラクタ
CSceneGameOver::~CSceneGameOver()
{

}
//初期化メソッド
void CSceneGameOver::InitScene()
{
	//出力させる文字のグラフィックを作成

	Draw::LoadImageW(L"Graphics/GameOver.png", 0, TEX_SIZE_512);


	if (((UserData*)Save::GetData())->Stage!=16)
	{
		//ゲームオーバーオブジェクト作成
		CObjGameOver* obj = new CObjGameOver();
		Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
	}
	else
	{
		CObjEndlessResult* obj = new CObjEndlessResult();
		Objs::InsertObj(obj, OBJ_ENDLESSRESULT, 10);
	}

}
//実行中メソッド
void CSceneGameOver::Scene()
{

}