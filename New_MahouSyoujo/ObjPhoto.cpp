//使用するヘッダーファイル
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjPhoto.h"

//使用するネームスペース
using namespace GameL;

//コンストラクタ
CObjPhoto::CObjPhoto(float src_top, float src_left, float src_right, float src_bottom,
					float x_size, float y_size, float dst_top, float dst_left, int g,int n)
{
	size_x = x_size;
	size_y = y_size;
	s_t = src_top;
	s_l = src_left;
	s_r = src_right;
	s_b = src_bottom;
	d_t = dst_top;
	d_l = dst_left;
	Graphic_Serct = g;
	p_num = n;
}

//イニシャライズ
void CObjPhoto::Init()
{
}

//アクション
void CObjPhoto::Action()
{
	CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
	if (obj_tutorial != nullptr)
	{
		p_order = obj_tutorial->GetOrder();
	}
	if (p_num + 1 == p_order)
		this->SetStatus(false);
}

//ドロー
void CObjPhoto::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top = s_t;
	src.m_left = s_l;
	src.m_right = s_r;
	src.m_bottom = s_b;

	//表示位置の設定
	dst.m_top = d_t;
	dst.m_left = d_l;
	dst.m_right = dst.m_left + size_x;
	dst.m_bottom = dst.m_top + size_y;

	//描画
	Draw::Draw(Graphic_Serct, &src, &dst, c, 0.0f);
}