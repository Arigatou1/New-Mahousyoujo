#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:
	CObjDamegeDisplay(float x, float y, int posture);
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float Sword_ATK;
	float Sword_x;
	float Sword_y;

	int d_time;
	int Sword_posture;
};