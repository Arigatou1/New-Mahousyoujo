#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjDragon : public CObj
{
public:
	CObjDragon(float x, float y);
	~CObjDragon() {};
	void Init();
	void Action();
	void Draw();
	int GetMAXHP();
	int GetHP();
	void FireBress();
	int GetPosture() { return b_posture; }
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

	int a_time;

	float e_hp;
	float maxhp;

	int shootDownTime;

	int AttackPattern;
	int lastAttack;

	bool fireBressOn;
	bool attack_now;
	//全体攻撃当たったか確認
	bool AllBullet_Hit;

	int b_posture;

};