//STLデバッグ機能OFFにする

#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/Audio.h"
#include "UtilityModule.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMenu.h"
#include "GameHead.h"

//コンストラクタ
CSceneMenu::CSceneMenu(int mode)
{
	loadMode = mode;
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
	Draw::LoadImageW(L"Graphics/Menu.png", 0, TEX_SIZE_512);
	//背景読み込み
	for (int i = 0; i <= 10; i++)
	{
		wchar_t bgid[128];

		swprintf_s(bgid, L"BackGrounds/bg_%02d.png", i);

		Draw::LoadImageW(bgid, i + 50, TEX_SIZE_512);
	}
	
	switch (loadMode)
	{
	case 0:
	{
		//モードセレクトオブジェクト作成
		CObjModeSelect* obj = new CObjModeSelect();
		Objs::InsertObj(obj, OBJ_MODESELECT, 3);
		break;
	}
	case 1:
	{
		//モードセレクトオブジェクト作成
		CObjStageSelect* obj2 = new CObjStageSelect();
		Objs::InsertObj(obj2, OBJ_STAGESELECT, 3);
		break;
	}
	case 2:
	{
		//エンドレスメニューオブジェクト作成
		CObjMenuEndless* obj2 = new CObjMenuEndless();
		Objs::InsertObj(obj2, OBJ_STAGEENDLESS, 3);
		break;
	}

	}
	
	CObjBackGround* obj_bg = new CObjBackGround(0);
	Objs::InsertObj(obj_bg, OBJ_BG, 1);

	//フェードイン
	Fadeout* obj_Fadeout = new Fadeout(3, true);
	Objs::InsertObj(obj_Fadeout, FADEOUT, 151);

	//音楽情報の読み込み
	Audio::LoadAudio(8, L"Sounds/menuBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"Sounds/kakuteiSE.wav", EFFECT);
	Audio::LoadAudio(10, L"Sounds/sentakuSE.wav", EFFECT);
	Audio::LoadAudio(11, L"Sounds/cancelSE.wav", EFFECT);

	//バックミュージックスタート
	float Volume = Audio::VolumeMaster(0);
	Audio::Start(8);

	
}
//実行中メソッド
void CSceneMenu::Scene()
{
	
}