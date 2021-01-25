//STLデバッグ機能OFFにする

#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/Audio.h"

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
	Draw::LoadImageW(L"Graphics/GameOver11.png", 1, TEX_SIZE_512);



	//音楽情報の読み込み
	Audio::LoadAudio(12, L"Sounds/gameoverBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"Sounds/kakuteiSE.wav", EFFECT);
	Audio::LoadAudio(11, L"Sounds/cancelSE.wav", EFFECT);

	float Volume = Audio::VolumeMaster(0);
	Audio::Start(12);


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