#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

class CTutorial :public CObj
{
public:
	CTutorial() {};
	~CTutorial() {};
	void Init();
	void Action();
	void Draw();
	int GetOrder() { return Order; };
	void SkillIconsDraw(int id);
private:
	bool cond1;//条件１
	bool cond2;//条件２

	bool condreset;//条件リセット
	int shootDownTime;

	int Order;//順番
	int m_skill;//魔法少女のスキル判別
	int Time;
};