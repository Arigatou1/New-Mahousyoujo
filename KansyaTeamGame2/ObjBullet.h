#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//弾丸
class CObjBullet :public CObj
{
public:
	CObjBullet(float x, float y, int posture, bool m_f) ;//コンストラクタ
	~CObjBullet() {};
	void Init();
	void Action();
	void Draw();
	float GetAttackPower();
private:

	float px;
	float py;
	float vx;
	float vy;

	int b_posture;
	bool b_f;
	float atk_power;
};