//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSword.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;


//コンストラクタ
CObjSword::CObjSword(float x, float y,int posture,bool m_f)
{
	a_px = x;
	a_py = y;

	a_posture = posture;
	a_f = m_f;
}

//イニシャライズ
void CObjSword::Init()
{
	
	Hits::SetHitBox(this, a_px, a_py, 64, 64, ELEMENT_PLAYER, OBJ_SWORD, 1);
	atk_time = 0;

	atk_power = 10 - ((UserData*)Save::GetData())->Diffculty;

	atk_ani = 0;
}

//アクション
void CObjSword::Action()
{
	//当たり判定を行うオブジェクト情報部
	int database[7] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ENEMY3,
		OBJ_ENEMY4,
		OBJ_SMALLSLIM,
		OBJ_BOSS1,
		OBJ_DRAGON,

	};

	//m_fから真偽を受け取る
	if (a_f == false)
	{

		//HitBoxの内容を更新
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(a_px , a_py);

		atk_time++;

		//情報部にあるヒットボックスに当たると
		for (int i = 0; i < 7; i++)
		{
			if (hit->CheckObjNameHit(database[i]) != nullptr)
			{
				//ダメージ表記作成
				CObjDamegeDisplay* obj_dd = new CObjDamegeDisplay(a_px+32+12+a_posture*48, a_py, atk_power);
				Objs::InsertObj(obj_dd, OBJ_DAMEGEDISPLAY, 60);
			}
		}

		if (atk_time ==1)
		{
			//あたり判定無効
			hit->SetInvincibility(true);
		}
		else if (atk_time == 5)
		{
			atk_ani++;
		}
		else if (atk_time == 7)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);

		}

	}
	
	

}
//ドロー
void CObjSword::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	
	//切り取り位置の設定
	src.m_top =192.0f;
	src.m_left =0.0f+ atk_ani*64.0f;
	src.m_right = 64.0f + atk_ani * 64.0f;
	src.m_bottom = 256.0f;
	//表示位置の設定
	dst.m_top = a_py+0.0f;
	dst.m_left = (32.0f * a_posture) + a_px + 32.0f;
	dst.m_right = (-32.0f * a_posture) + a_px + 32.0f;
	dst.m_bottom = a_py+64.0f;

	//描画
	Draw::Draw(3, &src, &dst, c, 0.0f);
}

//攻撃力を返す関数
float CObjSword::GetAttackPower()
{
	return atk_power;
}