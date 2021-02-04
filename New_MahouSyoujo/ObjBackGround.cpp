//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjBackGround.h"
#include "GameL\MultiThread.h"

//使用するネームスペース
using namespace GameL;

/// <summary>
/// ウィンドウの横幅、縦幅はそれぞれ800x600。
/// </summary>
/// <param name="id"></param>
CObjBackGround::CObjBackGround(int id)
{
	BackGroundID = id;
}
//イニシャライズ
void CObjBackGround::Init()
{
	wchar_t bgid[128];

	swprintf_s(bgid, L"BackGrounds/bg_%02d.png", BackGroundID);

	Draw::LoadImageW(bgid, BackGroundID + 50, TEX_SIZE_512);
}

//アクション
void CObjBackGround::Action()
{


}

//ドロー
void CObjBackGround::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	//切り取り位置の設定
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	//表示位置の設定
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;


	//描画
	Draw::Draw(50 + BackGroundID, &src, &dst, c, 0.0f);
}