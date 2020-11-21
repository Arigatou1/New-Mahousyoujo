//使用するヘッダーファイル
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBoss.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"


//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CObjGaugeBoss::Init()
{
	HP = 0;
	MAXHP = 0;
	GaugePercent = 0;
}

//アクション
void CObjGaugeBoss::Action()
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
//ドロー
void CObjGaugeBoss::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//切り取り位置の設定
	src.m_top = 192.0f;
	//0%位置
	src.m_left = 27.0f;
	//100%位置
	src.m_right = GaugePercent + 27.0f;
	src.m_bottom = 216.0f;
	//表示位置の設定
	dst.m_top = 552.0f;
	dst.m_left = 481.0f;
	dst.m_right = dst.m_left+ GaugePercent;
	dst.m_bottom = dst.m_top+24.0f;

	//描画
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

//int CObjGaugeHP::GetPercent()
//{
//	return GaugePercent;
//}