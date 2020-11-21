#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjBoss1 : public CObj
{
public:
	CObjBoss1(float x,float y) ;
	~CObjBoss1() {};
	void Init();
	void Action();
	void Draw();
	int GetMAXHP();
	int GetHP();

	
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;


	//blockとの衝突状態確認用
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	float e1_xsize;
	float e1_ysize;
	
	int a_time ;

	float e_hp;
	float maxhp;
};
