#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include <math.h>

//MenuBlockDraw関数
//表示位置dstの値を受け取って、描画だけできる。
void MenuBlockDraw(float x, float y, float width, float height, float r, float g, float b, float a, int type)
{
	float c[4] = { r,g,b,a };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = type*64;
	src.m_right = src.m_left+ 64;
	src.m_bottom = 64;

	dst.m_top = y;
	dst.m_left = x;
	dst.m_right = dst.m_left + width;
	dst.m_bottom = dst.m_top + height;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}

bool UnitVec(float* vx, float* vy)
{
	//ベクトルの正規化を行う
	float r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//長さ０がどうか調べる
	if (r == 0.0f)
	{
		//0なら計算失敗
		return false;
	}
	else
	{
		//正規化を行い、vxとvyの参照先の値を変更
		(*vx) = 3.0f / r * (*vx);
		(*vy) = 3.0f / r * (*vy);
	}

	//計算成功
	return true;
}

//領域チェック
bool CheckWindow(float pos_x, float pos_y, float window_x, float window_y, float window_w, float window_h)
{
	if (pos_x < window_x)
	{
		return false;//領域外
	}
	if (pos_x > window_w)
	{
		return false;//領域外
	}
	if (pos_y < window_y)
	{
		return false;//領域外
	}
	if (pos_y > window_h)
	{
		return false;//領域外
	}

	return true;
}

//ゲージベースを描画できるようにします。
void DrawGaugeBase(float x, float y,int id)
{
	//描画カラー情報
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//描画元切り取り位置
	RECT_F dst;//描画先表示位置


	switch (id)
	{
	case 1:

		//切り取り位置の設定
		src.m_top = 48.0f;
		src.m_left = 26.0f;
		src.m_right = 320.0f;
		src.m_bottom = 72.0f;
		//表示位置の設定
		dst.m_top =y;
		dst.m_left = x;
		dst.m_right = dst.m_left + 294.0f;
		dst.m_bottom = dst.m_top + 24;


		//描画
		Draw::Draw(1, &src, &dst, c, 0.0f);
		break;
	}
}