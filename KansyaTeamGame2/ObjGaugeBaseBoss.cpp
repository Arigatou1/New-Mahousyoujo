//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBaseBoss.h"


//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjGaugeBaseBoss::Init()
{

}

//アクション
void CObjGaugeBaseBoss::Action()
{



}
//ドロー
void CObjGaugeBaseBoss::Draw()
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
	dst.m_top = 552.0f;
	dst.m_left = 480.0f;
	dst.m_right = dst.m_left+294.0f;
	dst.m_bottom = dst.m_top+24;


	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}