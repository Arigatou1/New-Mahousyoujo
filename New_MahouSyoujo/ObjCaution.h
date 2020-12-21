#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjCaution : public CObj
{
public:
	CObjCaution() {};
	~CObjCaution() {};
	void Init();
	void Action();
	void Draw();
private:
	int m_time;
	int Opacity;
};