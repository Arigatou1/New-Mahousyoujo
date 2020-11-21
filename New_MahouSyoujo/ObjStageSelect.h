#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjStageSelect : public CObj
{
public:
	CObjStageSelect() {};
	~CObjStageSelect() {};
	void Init();
	void Action();
	void Draw();
	int GetStageID();
private:
	bool m_key_flag;//キーフラグ
	float cursor_x;
	float cursor_y;
	int StageID;
	int PageID;
	int MaxPage;
};