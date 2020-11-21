#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class EnemyAppear :public CObj
{
public:
	EnemyAppear() {};
	~EnemyAppear() {};
	void Init();
	void Action();
	void Draw();
	//int GetNUM();
private:
	int EnemyAmount;
	int StageID;
	int m_time;

	//int e_num;//敵の個体名
};