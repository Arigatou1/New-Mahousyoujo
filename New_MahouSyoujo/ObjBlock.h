#pragma once
//使用するヘッダーファイル
#include"GameL/DrawTexture.h"
#include"GameL/SceneObjManager.h"
//#include"GameL/SceneManager.h"

//使用するネームスペース
using namespace GameL;

class CObjBlock :public CObj
{
public :
	CObjBlock(int map[10][13]);
	~CObjBlock() {};
	void Init() ;
	void Action();
	void Draw();

	void BlockHit(float* x, float* y,
		bool* up, bool* down, bool* left, bool* right,
		float* vx, float* vy);

	bool BlockCrossPoint(
		float x, float y, float vx, float vy,
		float* out_px, float* out_py , float* out_len);
private:
	//マップ用変数。m_map[立幅][横幅];
	int m_map[10][13];

	void BlockDraw(float x, float y, RECT_F* dst, float c[]);

	float ex;
	float ey;

	float Dot(float ax, float ay, float bx, float by); //内積
	float Cross(float ax, float ay, float bx, float by);//外積

	//線と線との交差判定
	bool LineCrossPoint(
		float a1x, float a1y, float a2x, float a2y,
		float b1x, float b1y, float b2x, float b2y,
		float* out_px, float* out_py);
};