//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBoss.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"
#include "UtilityModule.h"


//使用するネームスペース
using namespace GameL;

CObjGaugeBoss::CObjGaugeBoss(float x,float y)
{
	pos_x = x;
	pos_y = y;
}
//イニシャライズ
void CObjGaugeBoss::Init()
{
	HP = 0;
	MAXHP = 0;
	GaugePercent = 0;
	GaugePosTweak();
}

//アクション
void CObjGaugeBoss::Action()
{
	if (((UserData*)Save::GetData())->Stage + 1 == 4 || ((UserData*)Save::GetData())->Stage + 1 == 17)
	{
		CObjBoss1* obj = (CObjBoss1*)Objs::GetObj(OBJ_BOSS1);

		if (obj != nullptr)
		{


			HP = obj->GetHP();
			MAXHP = obj->GetMAXHP();

			//MAXHPが100%とする

			GaugePercent = (HP / MAXHP) * 292;

		}
	}
	else if (((UserData*)Save::GetData())->Stage + 1 == 8)
	{
		CObjDragon* obj = (CObjDragon*)Objs::GetObj(OBJ_DRAGON);

		if (obj != nullptr)
		{


			HP = obj->GetHP();
			MAXHP = obj->GetMAXHP();

			//MAXHPが100%とする

			GaugePercent = (HP / MAXHP) * 292;

		}
	}
	
	if (GaugePercent <= 0.0f)
	{
		this->SetStatus(false);
	}


}
//ドロー
void CObjGaugeBoss::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	
		//切り取り位置の設定
		src.m_top = 48.0f;
		src.m_left = 26.0f;
		src.m_right = 320.0f;
		src.m_bottom = 72.0f;
		//表示位置の設定
		dst.m_top =pos_y;
		dst.m_left = pos_x;
		dst.m_right = dst.m_left + 294.0f;
		dst.m_bottom = dst.m_top + 24;


		//描画
		Draw::Draw(1, &src, &dst, c, 0.0f);

	//切り取り位置の設定
	src.m_top = 192.0f;
	//0%位置
	src.m_left = 27.0f;
	//100%位置
	src.m_right = GaugePercent + 27.0f;
	src.m_bottom = 216.0f;
	//表示位置の設定
	dst.m_top = pos_y;
	dst.m_left = pos_x;
	dst.m_right = dst.m_left+ GaugePercent;
	dst.m_bottom = dst.m_top+24.0f;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

//テクスチャ幅294 ウィンドウサイズ800
//ゲージ位置調整用関数。
//画面からはみ出させないと気に使う。
void CObjGaugeBoss::GaugePosTweak()
{
	if (pos_x < 294)
	{
		pos_x = 294;
	}
	else if (pos_x > 800-294)
	{
		pos_x = 800 - 294;
	}
}