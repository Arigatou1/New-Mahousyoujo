#pragma once

//オブジェクトネーム------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//オブジェクト名無し(禁止)
	//ゲームで使うオブジェクトの名前
	//OBJ_○○と表記
	OBJ_HERO,
	OBJ_MAGICALGIRL,
	OBJ_HOMINGBULLET,
	OBJ_ALLBULLET,
	OBJ_SWORD,
	OBJ_ENEMY,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_ENEMY4,
	OBJ_GAUGEBASE,
	OBJ_GAUGEHP,
	OBJ_GAUGEMP,
	OBJ_BLOCK,
	OBJ_MANA,
	OBJ_MANABASE,
	OBJ_MANA_HP,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_BG,
	OBJ_GAME_CLEAR,
	OBJ_ENEMYAMOUNT,
	OBJ_STAGESELECT,
	OBJ_BULLET,
	OBJ_MODESELECT,
	OBJ_BARRIER,
	OBJ_CUSTOMIZE,
	OBJ_SMALLSLIM,
	OBJ_PAUSEMENU,
	OBJ_SETTING,
	OBJ_BOSS1,
	OBJ_SLIMEBALL,
	OBJ_APPEAR,
	OBJ_GAUGEBASEBOSS,
	OBJ_GAUGEBOSS,
	OBJ_FIREBALL,
	OBJ_DRAGON,
	OBJ_SHOCKWAVE,
	OBJ_STAGEENDLESS,
	FADEOUT,
	OBJ_ENDLESSRESULT,
	OBJ_DAMEGEDISPLAY,
	OBJ_CAUTION,
	OBJ_TUTORIAL,
	OBJ_TUTORIALHERO,
	OBJ_ICON,
	OBJ_PHOTO,
};
//------------------------------------------------

//当たり判定属性----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//属性無し 全ての属性と当たり判定が実行される
	//以下　同じ属性同士では当たり判定は実行されない
	//属性は追加可能だが、デバック時の色は初期設定分しか無い
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//セーブ＆ロードとシーン間のやり取りするデータ
struct UserData
{

	//設定で変更できないデータ------------------------
	int mSeveData;	//サンプルセーブデータ
	//ステージIDを取得する
	int Stage;
	//ステージのスコアデータ
	int ScoreData[20];
	//最大ステージ数は20だが、２０のクリア判定をつけるため
	bool Clear_Flag[21];
	//ポーズメニュー用変数
	bool PauseMenu;
	//スコアの計算するためのもの
	float HeroHP;
	float ManaHP;
	//残り敵の数の表示
	int enemyRemain;
	bool HPZeroCheck;
	bool tutorialDone;

	//---------------------------------------------
	//設定で変更できるデータ

	//主人公の武器。剣 0 銃 1
	int weapon;
	//難易度
	int Diffculty;

	bool DamageDraw;
	int masterVolume;
};
//------------------------------------------------


//ゲーム内で使用されるグローバル変数・定数・列挙--



//------------------------------------------------
//ゲーム内で使用するクラスヘッダ------------------


//------------------------------------------------

//ゲームシーンオブジェクトヘッダ-----------------
#include "ObjHero.h"
#include "ObjMagicalGirl.h"
#include "CObjHomingBullet.h"
#include "ObjAllBullet.h"
#include "ObjEnemy.h"
#include "ObjEnemy2.h"
#include "ObjEnemy3.h"
#include "ObjEnemy4.h"
#include "ObjBlock.h"
#include "ObjGaugeHP.h"
#include "ObjGaugeMana.h"
#include "ObjMana.h"
#include "ObjTitle.h"
#include "ObjGameOver.h"
#include "ObjBackGround.h"
#include "ObjGameClear.h"
#include "ObjEnemyAmount.h"
#include "ObjStageSelect.h"
#include "ObjBullet.h"
#include "ObjModeSelect.h"
#include "Objbarrier.h"
#include "ObjCustomize.h"
#include "ObjSmallSlim.h"
#include "ObjPauseMenu.h"
#include "ObjSetting.h"
#include "ObjBoss1.h"
#include "ObjSlimeBall.h"
#include "ObjSword.h"
#include "EnemyAppear.h"
#include "ObjMenuEndless.h"
#include "ObjEndlessResult.h"

#include "ObjGaugeBoss.h"
#include "ObjFireBall.h"
#include "ObjDragon.h"
#include "ObjShockWave.h"
#include "ClearFadeout.h"
#include "ObjCaution.h"

#include "ObjDamegeDisplay.h"
#include "Tutorial.h"
#include "TutorialHero.h"
#include "ObjIcon.h"
#include "ObjPhoto.h"


//------------------------------------------------

//ゲームシーンクラスヘッダ------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"
#include "SceneMenu.h"
//-----------------------------------------------

//シーンスタートクラス---------------------------
//ゲーム開始時のシーンクラス登録
#define SET_GAME_START CSceneTitle
//-----------------------------------------------