#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeBoss :public CObj
{
public:
	CObjGaugeBoss() {};

	~CObjGaugeBoss() {};
	void Init();
	void Action();
	void Draw();
	int GetPercent();
private:
	float HP;
	float MAXHP;
	float GaugePercent;


};

