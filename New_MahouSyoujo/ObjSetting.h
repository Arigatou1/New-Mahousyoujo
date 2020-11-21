#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjSetting : public CObj
{
public:
	CObjSetting() {};
	~CObjSetting() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_key_flag;//キーフラグ
	float cursor_x;
	float cursor_y;
	int nowSelect;

};