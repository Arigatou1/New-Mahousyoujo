#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeHP :public CObj
{
public:
	CObjGaugeHP() {};
	~CObjGaugeHP() {};
	void Init();
	void Action();
	void Draw();
private:
	float HP;
	float MAXHP;
	float GaugePercent[2];//GaugePercent{ HPの割合, MPの割合};
	float MP;
	float MaxMP;

};

