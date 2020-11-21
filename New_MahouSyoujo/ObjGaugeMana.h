#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeMANAHP :public CObj
{
public:
	CObjGaugeMANAHP(float x,float y) ;
	~CObjGaugeMANAHP() {};
	void Init();
	void Action();
	void Draw();
	float GetPercent();
private:
	float HP;
	float GaugePercent;
	float gb_x;
	float gb_y;

	float xoffset;
	float yoffset;

};

