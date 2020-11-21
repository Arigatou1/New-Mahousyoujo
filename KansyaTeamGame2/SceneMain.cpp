//STLデバッグ機能をOFFにする
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameLで使用するヘッダー
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//使用ヘッダー
#include "SceneMain.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"
#include "GameL/Audio.h"

//コンストラクタ
CSceneMain::CSceneMain()
{

}

//デストラクタ
CSceneMain::~CSceneMain()
{
	
}

//初期化メソッド
void CSceneMain::InitScene()
{
	//音楽読み込み
	Audio::LoadAudio(0, L"swordSE.wav", EFFECT);
	Audio::LoadAudio(1, L"girlSE.wav", EFFECT);
	Audio::LoadAudio(2, L"bakuhatuSE.wav", EFFECT);
	Audio::LoadAudio(3, L"menuSE.wav", EFFECT);
	Audio::LoadAudio(4, L"herodamageSE2.wav", EFFECT);
	Audio::LoadAudio(5, L"bulletSE.wav", EFFECT);
	Audio::LoadAudio(6, L"herojumpSE.wav", EFFECT);
	
	//外部データの読み込み

	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;
	int StageID =((UserData*)Save::GetData())->Stage+1;

	
	//マップデータを読み込む。
	wchar_t s[128];

	if (StageID >= 9)
	swprintf_s(s, L"Stage/Stage1.csv", StageID);

	else
		swprintf_s(s, L"Stage/Stage%d.csv", StageID);

	p = Save::ExternalDataOpen(s, &size);//外部データ読み込み
	
	int map[10][13];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//HP用Font作成
	Font::SetStrTex(L"1234567890/.+-残り敵の数:");


	//グラフィックの読み込み
	Draw::LoadImageW(L"image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Gauge.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"BackGround.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"Hero.png", 3, TEX_SIZE_512);

	for (int i = 1; i <= 10; i++)
	{
		wchar_t bgid[128];

		swprintf_s(bgid, L"BackGrounds/bg_%02d.png", i);

		Draw::LoadImageW(bgid, i+50, TEX_SIZE_512);
	}
	

	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 60);
	

	//ゲージオブジェクト作成
	CObjGaugeBase* obj_gb = new CObjGaugeBase();
	Objs::InsertObj(obj_gb, OBJ_GAUGEBASE, 50);

	//HPゲージオブジェクト作成
	CObjGaugeHP* obj_ghp = new CObjGaugeHP();
	Objs::InsertObj(obj_ghp, OBJ_GAUGEHP, 51);

	//魔法少女オブジェクト作成
	CObjMagicalGirl* obj_magicalgirl = new CObjMagicalGirl();
	Objs::InsertObj(obj_magicalgirl, OBJ_MAGICALGIRL, 61);
	
	//Blockオブジェクト
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	//MPゲージオブジェクト作成
	CObjGaugeMP* obj_gmp = new CObjGaugeMP();
	Objs::InsertObj(obj_gmp, OBJ_GAUGEMP, 51);
	
	//背景オブジェクト作成
	CObjBackGround* obj_bg = new CObjBackGround();
	Objs::InsertObj(obj_bg, OBJ_BG, 1);

	//敵の数オブジェクト作成
	CObjEnemyAmount* obj_eneamo = new CObjEnemyAmount();
	Objs::InsertObj(obj_eneamo, OBJ_ENEMYAMOUNT, 51);


	//PauseMenuオブジェクト作成
	CObjPauseMenu* obj_pause = new CObjPauseMenu();
	Objs::InsertObj(obj_pause, OBJ_PAUSEMENU, 100);

	
	//EnemyAppear
	EnemyAppear* obj_appear = new EnemyAppear();
	Objs::InsertObj(obj_appear, OBJ_APPEAR, 101);

	//タイム初期化
	m_time = 0;

	EnemyAmount = 0;
}

//実行中メソッド
void CSceneMain::Scene()
{

	//ポーズメニュー
	if (Input::GetVKey(VK_ESCAPE) == true)
	{
		//ポーズメニューSE
		Audio::Start(3);
		if (m_key_flag == true)
		{
			((UserData*)Save::GetData())->PauseMenu = true;
			m_key_flag = false;
		}
	}

	else
		m_key_flag = true;


	if(((UserData*)Save::GetData())->enemyRemain == 0)
		Scene::SetScene(new CSceneGameClear());
}

