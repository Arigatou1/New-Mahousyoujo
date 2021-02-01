#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeBoss :public CObj
{
public:
	CObjGaugeBoss(float x,float y) ;

	~CObjGaugeBoss() {};
	void Init();
	void Action();
	void Draw();
	int GetPercent();
	void GaugePosTweak();
private:
	float HP;
	float MAXHP;
	float GaugePercent;

	float pos_x;
	float pos_y;
};

