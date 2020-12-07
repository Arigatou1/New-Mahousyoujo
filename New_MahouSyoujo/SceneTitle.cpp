//STLデバッグ機能をOFFにする
#define _SECURE_SCL_(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;
//使用するヘッダー
#include "SceneMain.h"
#include "GameHead.h"

//コンストラクタ
CSceneTitle::CSceneTitle()
{

}

//デストラクタ
CSceneTitle::~CSceneTitle()
{

}

//ゲームメイン初期化メソッド
void CSceneTitle::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"マジカルウォーズ");

	//タイトルオブジェクト作成
	CObjTitle* obj = new CObjTitle();
	Objs::InsertObj(obj, OBJ_TITLE, 0);

	Draw::LoadImageW(L"Graphics/logo.png", 0, TEX_SIZE_512);

    //音楽情報の読み込み
	Audio::LoadAudio(7, L"Sounds/gametitleBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"Sounds/sentakuSE.wav", EFFECT);

    //バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.05f);
	Audio::Start(7);
}

//ゲームメイン実行中メソッド
void CSceneTitle::Scene()
{

}