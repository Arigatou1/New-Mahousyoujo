#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include <math.h>
//MenuBlockDraw関数
//表示位置dstの値を受け取って、描画だけできる。
void MenuBlockDraw(float x, float y, float width, float height, float r, float g, float b, float a)
{
	float c[4] = { r,g,b,a };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = 0;
	src.m_right = 64;
	src.m_bottom = 64;

	dst.m_top = y;
	dst.m_left = x;
	dst.m_right = dst.m_left + width;
	dst.m_bottom = dst.m_top + height;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
/*
//ブロック当たり判定
bool Gravity(float *x ,float* y,float* b_x,float* b_y)
{
	//主人公のブロックの当たり判定
	if ((*x + 64.0f > *b_x) && (*x < *b_x + 64.0f) && (*y + 64.0f > *b_y) && (*y < *b_y + 64.0f))
	{
		//vectorの作成
		float vx = *x - *b_x;
		float vy = *y - *b_y;

		//長さを求める
		float len = sqrt(vx * vx + vy * vy);

		//角度を求める
		float r = atan2(vy, vx);
		r = r * 180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);
	
		if (len < 88.0f)
		{
			//角度で上下左右判定
			if ((r < 40 && r>0) || r > 320)
			{
				//右
				hero->SetX(*b_x + 64.0f);//ブロックの位置-主人公の幅
				hero->SetRight(true);//主人公の左側が衝突
				hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
			}
			if (r > 45 && r < 135)
			{
				//上
				hero->SetDown(true);//主人公から見て、下の部分が衝突している
				hero->SetY(*b_y - 64.0f);//ブロックの位置-主人公の幅
				hero->SetVY(0.0f);
			}
			if (r > 140 && r < 220)
			{
				//左
				hero->SetX(*b_x - 64.0f);//ブロックの位置-主人公の幅
				hero->SetLeft(true);//主人公の左側が衝突
				hero->SetVX(-hero->GetVX() * 0.1f);//-VX*反発係数
			}
			if (r > 225 && r < 315)
			{
				//下
				hero->SetUp(true);
				hero->SetY(*b_y + 64.0f);//ブロックの位置-主人公の幅

				if (hero->GetVY() < 0)
				{
					hero->SetVY(0.0f);
				}
			}
		}
		
	}
}*/
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