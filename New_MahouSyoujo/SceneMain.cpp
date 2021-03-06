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
	((UserData*)Save::GetData())->HPZeroCheck = false;

	//音楽読み込み
	Audio::LoadAudio(0, L"Sounds/swordSE.wav", EFFECT);
	Audio::LoadAudio(1, L"Sounds/girlsentakuSE.wav", EFFECT);
	Audio::LoadAudio(2, L"Sounds/bakuhatuSE.wav", EFFECT);
	Audio::LoadAudio(3, L"Sounds/menuSE.wav", EFFECT);
	Audio::LoadAudio(4, L"Sounds/herodamageSE.wav", EFFECT);
	Audio::LoadAudio(5, L"Sounds/bulletSE.wav", EFFECT);
	Audio::LoadAudio(6, L"Sounds/herojumpSE.wav", EFFECT);
	Audio::LoadAudio(13, L"Sounds/gameclearBGM.wav", EFFECT);
	Audio::LoadAudio(14, L"Sounds/danjonBGM1.wav", BACK_MUSIC);
	Audio::LoadAudio(15, L"Sounds/danjonBGM2.wav", BACK_MUSIC);
	Audio::LoadAudio(16, L"Sounds/bossBGM1.wav", BACK_MUSIC); 
	
	Audio::LoadAudio(17, L"Sounds/wahuBGM.wav", BACK_MUSIC);
	Audio::LoadAudio(18, L"Sounds/danjonBGM3.wav", BACK_MUSIC);
	Audio::LoadAudio(19, L"Sounds/bossBGM2.wav", BACK_MUSIC);
	
	Audio::LoadAudio(20, L"Sounds/herodownSE.wav", EFFECT);
	Audio::LoadAudio(21, L"Sounds/girlattackSE.wav", EFFECT);
	Audio::LoadAudio(22, L"Sounds/kaihukuSE.wav", EFFECT);
	Audio::LoadAudio(23, L"Sounds/bariaSE.wav", EFFECT);
	Audio::LoadAudio(25, L"Sounds/manadamageSE.wav", EFFECT);
	Audio::LoadAudio(26, L"Sounds/dragondownSE.wav", EFFECT);
	Audio::LoadAudio(27, L"Sounds/firebreathSE.wav", EFFECT);
	Audio::LoadAudio(28, L"Sounds/bossattackSE2.wav", EFFECT);
	Audio::LoadAudio(29, L"Sounds/bossskillSE1.wav", EFFECT);
	Audio::LoadAudio(30, L"Sounds/endlessBGM.wav", BACK_MUSIC);

	Audio::LoadAudio(31, L"Sounds/bossdownSE.wav", EFFECT);
	//外部データの読み込み

	unique_ptr<wchar_t>p;//ステージ情報ポインター
	int size;
	int StageID =((UserData*)Save::GetData())->Stage+1;

	
	//マップデータを読み込む。
	wchar_t s[128];

	if (StageID >= 9 && StageID!=17)
	swprintf_s(s, L"Stage/Stage8.csv", StageID);

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
	Draw::LoadImageW(L"Graphics/image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/Gauge.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/BackGround.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/Hero.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/Dragon.png", 4, TEX_SIZE_128);
	Draw::LoadImageW(L"Graphics/Baria.png", 5, TEX_SIZE_128);
	Draw::LoadImageW(L"Graphics/Caution.png", 6, TEX_SIZE_128);

	Draw::LoadImageW(L"Graphics/skill_icons.png", 10, TEX_SIZE_128);
	Draw::LoadImageW(L"Graphics/block.png", 63, TEX_SIZE_64);


	//主人公オブジェクト作成
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO,150);

	//魔法少女オブジェクト作成
	CObjMagicalGirl* obj_magicalgirl = new CObjMagicalGirl();
	Objs::InsertObj(obj_magicalgirl, OBJ_MAGICALGIRL, 61);

	//HPゲージオブジェクト作成
	CObjGaugeHP* obj_ghp = new CObjGaugeHP();
	Objs::InsertObj(obj_ghp, OBJ_GAUGEHP, 51);
	
	//Blockオブジェクト
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	//敵の数オブジェクト作成
	CObjEnemyAmount* obj_eneamo = new CObjEnemyAmount();
	Objs::InsertObj(obj_eneamo, OBJ_ENEMYAMOUNT, 51);

	//PauseMenuオブジェクト作成
	CObjPauseMenu* obj_pause = new CObjPauseMenu();
	Objs::InsertObj(obj_pause, OBJ_PAUSEMENU, 100);

	
	//EnemyAppear
	EnemyAppear* obj_appear = new EnemyAppear();
	Objs::InsertObj(obj_appear, OBJ_APPEAR, 101);

	//フェードイン
	Fadeout* obj_Fadeout = new Fadeout(3,true);
	Objs::InsertObj(obj_Fadeout, FADEOUT, 151);

	//アイコン作成
	CObjIcon* obj_icon = new CObjIcon(736.0f,0.0f,1.0f, false);
	Objs::InsertObj(obj_icon, OBJ_ICON, 60);



	//タイム初期化
	m_time = 0;

	EnemyAmount = 0;
	shootDownTime = 0;
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


}

