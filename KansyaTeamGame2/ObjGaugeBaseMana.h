#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeMANABase :public CObj
{
public:
	CObjGaugeMANABase(float x,float y);
	~CObjGaugeMANABase() {};
	void Init();
	void Action();
	void Draw();
private:
	float gb_x;
	float gb_y;

	float xoffset;
	float yoffset;

};

