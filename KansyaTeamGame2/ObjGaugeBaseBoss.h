#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjGaugeBaseBoss :public CObj
{
public:
	CObjGaugeBaseBoss() {};
	~CObjGaugeBaseBoss() {};
	void Init();
	void Action();
	void Draw();
private:

};

