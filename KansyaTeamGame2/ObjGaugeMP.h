#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeMP :public CObj
{
public:
	CObjGaugeMP() {};
	~CObjGaugeMP() {};
	void Init();
	void Action();
	void Draw();
private:
	float MP;
	float MaxMP;
	float GaugePercent;
	float gm_x;
	float gm_y;

};