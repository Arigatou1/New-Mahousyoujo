#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjEndlessResult : public CObj
{
public:
	CObjEndlessResult() {};
	~CObjEndlessResult() {};
	void Init();
	void Action();
	void Draw();
private:
	float Score;
	bool m_key_flag;//キーフラグ

};