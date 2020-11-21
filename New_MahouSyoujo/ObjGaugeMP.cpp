#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeMP.h"
#include "GameL\DrawFont.h"


//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjGaugeMP::Init()
{
	
}

//アクション
void CObjGaugeMP::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{


		MP = obj_magicalgirl->GetMP();
		MaxMP = obj_magicalgirl->GetMaxMP();


		//MAXMPが100%とする

		GaugePercent = (MP / MaxMP) * 250;

	}
}
//ドロー
void CObjGaugeMP::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	wchar_t str[128];
	swprintf_s(str, L"%.0lf", MP);//整数を文字列か
	Font::StrDraw(str, 330, 26, 24, c);

	//切り取り位置の設定
	src.m_top = 96.0f;
	//0%位置
	src.m_left = 69.0f;
	//100%位置
	src.m_right = GaugePercent + 69.0f;
	src.m_bottom = 120.0f;

	//表示位置の設定
	dst.m_top    = 24.0f;
	//0%位置
	dst.m_left   = 69.0f;
	//100%位置
	dst.m_right  = GaugePercent + 69.0f;
	dst.m_bottom = 48.0f;


	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}