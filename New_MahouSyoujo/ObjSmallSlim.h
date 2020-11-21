#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjSmallSlim : public CObj
{
public:
	CObjSmallSlim(float x, float y);
	~CObjSmallSlim() {};
	void Init();
	void Action();
	void Draw();
	//	int EneAmo();
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	
	int e_damege;//ダメージ量

	float b_mx;//バリアのx位置
	float b_my;//バリアのy位置

	float m_mx;//マナのX位置
	float m_my;//マナのY位置
	//int Amount;

	int e_jkn;//
	int e_time;//
	bool e_mtk;

	//blockとの衝突状態確認用
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	float e1_xsize;
	float e1_ysize;
	float e_hp;
	float damage;
};
