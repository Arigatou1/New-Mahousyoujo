#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjCustomize : public CObj
{
public:
	CObjCustomize(int mode = 0) { Mode = mode; };
	~CObjCustomize() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_key_flag;//キーフラグ
	float cursor_x;
	float cursor_y;
	int nowSelect;
	int Mode;
	
	void cursorUp();
	void cursorDown();
	void CustomizeClose();
};