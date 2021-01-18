#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

class CTutorial :public CScene
{
public:
	CTutorial() {};
	~CTutorial() {};
	void Init();
	void Action();
	void Draw();
private:
	bool cond1;//条件１
	bool cond2;//条件２

	int Order;//順番
};