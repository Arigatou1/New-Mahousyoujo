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
	int GetMAXHP() { return maxhp; };
	int GetHP() {return e_hp;};
	int GetPosture() { return m_posture; };
	float GetX() { return m_ex; }
	
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

	//全体攻撃に当たったか確認
	bool allbullet_hit;

	float e1_xsize;
	float e1_ysize;
	
	int a_time ;

	float e_hp;
	float maxhp;

	int m_posture;
};
