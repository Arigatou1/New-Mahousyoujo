//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeMana.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"


//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjGaugeMANAHP::CObjGaugeMANAHP(float x, float y)
{

	if (x < 113.0f)
		x = 113.0f;
	if (x > 687.0f)
		x = 687.0f;

	gb_x = x;
	gb_y = y;

}
//イニシャライズ
void CObjGaugeMANAHP::Init()
{
	
}

//アクション
void CObjGaugeMANAHP::Action()
{
	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj_mana != nullptr)
	{


		HP = obj_mana->GetHP();
	

		//MAXHPが100%とする

		GaugePercent = (HP / 100.0) * 292.0f;

	}

}
//ドロー
void CObjGaugeMANAHP::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	wchar_t str[128];
	swprintf_s(str, L"%.3lf", HP);//整数を文字列か
	Font::StrDraw(str, 2, 48, 24, c);

	//切り取り位置の設定
	src.m_top = 144.0f;
	//0%位置
	src.m_left = 27.0f;
	//100%位置
	src.m_right = GaugePercent + src.m_left;
	src.m_bottom = 168.0f;
	//表示位置の設定
	dst.m_top = gb_y + 96.0f;
	//0%位置
	dst.m_left =gb_x - 112.0f;
	//100%位置
	dst.m_right = dst.m_left+GaugePercent;
	dst.m_bottom = gb_y + 120.0f;


	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}


//int CObjGaugeMANAHP::GetPercent()
//{
//	if(0)
//	return GaugePercent;
//}
