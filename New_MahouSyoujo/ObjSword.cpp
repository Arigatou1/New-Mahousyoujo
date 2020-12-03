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
	
	Hits::SetHitBox(this, a_px + (a_posture * 60), a_py, 56, 56, ELEMENT_PLAYER, OBJ_SWORD, 1);
	atk_time = 0;

	atk_power = 10 - ((UserData*)Save::GetData())->Diffculty;
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
		hit->SetPos(a_px + (a_posture * 60), a_py);

		atk_time++;

		//情報部にあるヒットボックスに当たると消滅
		for (int i = 0; i < 7; i++)
		{
			if (hit->CheckObjNameHit(database[i]) != nullptr)
			{
				//ダメージ表記作成
				CObjDamegeDisplay* obj_dd = new CObjDamegeDisplay();
				Objs::InsertObj(obj_dd, OBJ_DAMEGEDISPLAY, 60);
			}
		}
	}

	//if (atk_time>=2)
	//{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	//}

}
//ドロー
void CObjSword::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置
	
	//切り取り位置の設定
	src.m_top =0.0f;
	src.m_left =0.0f;
	src.m_right = 0.0f;
	src.m_bottom = 0.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 0.0f;

	//描画
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

//攻撃力を返す関数
float CObjSword::GetAttackPower()
{
	return atk_power;
}

float CObjSword::Geta_px()
{
	return a_px;
}

float CObjSword::Geta_py()
{
	return a_py;
}