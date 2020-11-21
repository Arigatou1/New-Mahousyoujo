#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト敵機
class CObjEnemy : public CObj
{
public:
	CObjEnemy(float x,float y,float vx=0,float vy=0);
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
//	int EneAmo();
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	int e_hp;//敵のHP
	int e1_damege;//ダメージ量
	int e1_time;//敵の攻撃時間
	int e1_anime;

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

	float damage;//敵が受けるダメージ
};
