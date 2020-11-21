#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjSlimeBall : public CObj
{
public:
	CObjSlimeBall(float x, float y, float vx = 0, float vy = 0);
	~CObjSlimeBall() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	

	float b_mx;//バリアのx位置

	float m_mx;//マナのX位置
	float m_my;//マナのY位置 
	//int Amount;

	//blockとの衝突状態確認用
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	bool e1_t;//敵の攻撃間隔

	float e1_xsize;
	float e1_ysize;
};
