//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjMana.h"
#include "GameHead.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"
//#include "ObjGaugeBaseMana.h"

//テスト用
#include "GameL\WinInputs.h"

//使用するネームスペース
using namespace GameL;

CObjMana::~CObjMana()
{
	
}

CObjMana::CObjMana(float x, float y)
{
	Mana_x = x;
	Mana_y = y;
}



//イニシャライズ
void CObjMana::Init()
{
	
	Mana_HP = 100;


	//MANAゲージオブジェクト作成
	CObjGaugeMANAHP* obj_manahp = new CObjGaugeMANAHP(Mana_x, Mana_y);
	Objs::InsertObj(obj_manahp, OBJ_MANA_HP, 51);

	//あたり判定用Hitboxを作成
	Hits::SetHitBox(this, Mana_x , Mana_y, 64, 64, ELEMENT_WHITE, OBJ_MANA, 1);


	mana_damege = ((UserData*)Save::GetData())->Diffculty * 0.5;

	shootDownTime = 0;
}

//アクション
void CObjMana::Action()
{

	//HitBoxの内容
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(Mana_x,Mana_y);

	//当たり判定を行うオブジェクト情報部
	int database[8] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ENEMY3,
		OBJ_ENEMY4,
		OBJ_SMALLSLIM,
		OBJ_SHOCKWAVE,
		OBJ_FIREBALL,
		OBJ_SLIMEBALL,
	};

	for (int i = 0; i < 8; i++)
	{
		//敵の攻撃力
		if (hit->CheckObjNameHit(database[i]) != nullptr)
		{
			Audio::Start(25);
			if (i == 0)
				MANA_damege = 2.0 + mana_damege * 0.20;
			else if (i == 1)
				MANA_damege = 4.0 + mana_damege * 0.20;
			else if (i == 2)
				MANA_damege = 0.5;
			else if (i == 3)
				MANA_damege = 0.5;
			else if (i == 4)
				MANA_damege = 1.0 + mana_damege * 0.20;
			else if (i == 5)
				MANA_damege = 2.0 + mana_damege * 0.10;
			else if (i == 6)
				MANA_damege = 0.1 + mana_damege * 0.10;
			else if (i == 7)
				MANA_damege = 0.1 + mana_damege * 0.20;

			Mana_HP -= MANA_damege;

		}

		if (hit->CheckObjNameHit(database[i]) != nullptr)
		{
			//ダメージ表記作成
			CObjDamegeDisplay* obj_dd = new CObjDamegeDisplay(Mana_x+13+32, Mana_y-32, MANA_damege,1);
			Objs::InsertObj(obj_dd, OBJ_DAMEGEDISPLAY, 60);
		}
	}

	//HP0になったとき
	if (Mana_HP <= 0)
	{
		//0固定
		Mana_HP = 0;
		//HPがゼロになったら、待機時間を増価させる。
		shootDownTime++;
		((UserData*)Save::GetData())->HPZeroCheck = true;

		if (shootDownTime == 50)
		{
			Audio::Start(20);
		}

		if (shootDownTime == 200)
		{
			//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout();
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}

		else if (shootDownTime > 300)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Scene::SetScene(new CSceneGameOver());
		}

	}

	//エンドレスモードではない場合
	if(((UserData*)Save::GetData())->Stage!=16)
	((UserData*)Save::GetData())->ManaHP = 100.0f - Mana_HP;
}
//ドロー
void CObjMana::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,Mana_HP/100,Mana_HP/100,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//切り取り位置の設定
	src.m_top = 192.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 256.0f;
	//表示位置の設定
	dst.m_top = Mana_y;
	dst.m_left = Mana_x;
	dst.m_right = Mana_x+64;
	dst.m_bottom = Mana_y+64;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}


float CObjMana::GetHP()
{
	return Mana_HP;
}

//位置情報X取得用
float CObjMana::GetX()
{
	return Mana_x;
}

//位置情報Y取得用
float CObjMana::GetY()
{
	return Mana_y;
}