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
#include "SceneGameClear.h"
#include "GameHead.h"

//コンストラクタ
CSceneGameClear::CSceneGameClear()
{

}
//デストラクタ
CSceneGameClear::~CSceneGameClear()
{

}
//初期化メソッド
void CSceneGameClear::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"GAME CLEAR");
	
	Draw::LoadImageW(L"Graphics/Stage Clear.png", 0, TEX_SIZE_512);


	//音楽情報の読み込み
	Audio::LoadAudio(13, L"Sounds/gameclearBGM.wav", SOUND_TYPE::EFFECT);

	float Volume = Audio::VolumeMaster(0);
	Audio::Start(13);


	//ゲームオーバーオブジェクト作成
	CObjGameClear* obj = new CObjGameClear();
	Objs::InsertObj(obj, OBJ_GAME_CLEAR, 10);
}
//実行中メソッド
void CSceneGameClear::Scene()
{

}