//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeHP.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"


//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjGaugeHP::Init()
{
	
}

//アクション
void CObjGaugeHP::Action()
{
	//主人公HP
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		HP = obj->GetHP();
		MAXHP = obj->GetMAXHP();

		/// <summary>
		/// 例えば、HPが100でMaxHPも100とする。
		/// HPをmaxHPで割ると1は出てくるので、それにテクスチャサイズをかけてる。
		/// HPが半分の時は,0.5が出てくるので、半分のテクスチャしか表示されない。
		/// </summary>
		GaugePercent[0] = (HP / MAXHP) * 250;

	}

	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		//上と同じ。
		MP = obj_magicalgirl->GetMP();
		MaxMP = obj_magicalgirl->GetMaxMP();

		GaugePercent[1] = (MP / MaxMP) * 250;

	}

}
//ドロー
void CObjGaugeHP::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置

	//--------------ゲージの土台の描画。----------------------
	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 320.0f;
	src.m_bottom = 48.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 320.0f;
	dst.m_bottom = 48.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//--------------------------------------------------------

	wchar_t str[128];
	swprintf_s(str, L"%.0lf/%.0lf", HP,MAXHP);//整数を文字列か
	Font::StrDraw(str, 330, 2, 24, c);

	swprintf_s(str, L"%.0lf/%.0lf", MP, MaxMP);//整数を文字列か
	Font::StrDraw(str, 330, 26, 24, c);


	for (int i = 0; i < 2; i++)
	{
		//切り取り位置の設定
		src.m_top = 72.0f + 24.0f * i;
		//0%位置
		src.m_left = 69.0f;
		//100%位置
		src.m_right = GaugePercent[i] + 69.0f;
		src.m_bottom = src.m_top + 24.0f;
		//表示位置の設定
		dst.m_top = 0.0f + 24.0f * i;
		//0%位置
		dst.m_left = 69.0f;
		//100%位置
		dst.m_right = GaugePercent[i] + 69.0f;
		dst.m_bottom = dst.m_top + 24.0f;


		//描画
		Draw::Draw(1, &src, &dst, c, 0.0f);

	}
}
