#pragma once
//使用するヘッダー
#include"GameL/SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：敵３
class CObjEnemy3 :public CObj
{
public:
	CObjEnemy3(float x, float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_ex;		//X座標
	float m_ey;		//Y座標
	float m_vx;		//移動ベクトル
	float m_vy;

	int e_hp;
	int e3_time;
	int e_damege;

	float b_mx;//バリアの位置
	float b_my;
	

	float m_mx; //マナの座標
	float m_my;

	float jump;

	//blockとの衝突状態確認用
	bool e3_hit_up;
	bool e3_hit_down;
	bool e3_hit_right;
	bool e3_hit_left;

	bool e3_t;

	float damage;
	//攻撃間隔用変数
	int a_time;
};
