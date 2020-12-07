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
#include "SceneMenu.h"
#include "GameHead.h"

//コンストラクタ
CSceneMenu::CSceneMenu()
{

}
//デストラクタ
CSceneMenu::~CSceneMenu()
{

}
//初期化メソッド
void CSceneMenu::InitScene()
{
	//出力させる文字のグラフィックを作成
	Font::SetStrTex(L"Game Menu");

	//グラフィックの読み込み
	Draw::LoadImageW(L"Menu.png", 0, TEX_SIZE_512);

	
	//モードセレクトオブジェクト作成
	CObjModeSelect* obj = new CObjModeSelect();
	Objs::InsertObj(obj, OBJ_MODESELECT, 0);

	//音楽情報の読み込み
	Audio::LoadAudio(8, L"Sounds/menuBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"Sounds/kakuteiSE.wav", EFFECT);
	Audio::LoadAudio(10, L"Sounds/sentakuSE.wav", EFFECT);
	Audio::LoadAudio(11, L"Sounds/cancelSE.wav", EFFECT);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(-0.05f);
	Audio::Start(8);


}
//実行中メソッド
void CSceneMenu::Scene()
{

}