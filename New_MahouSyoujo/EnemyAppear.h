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
	void BossDisappearnce();

private:
	int EnemyAmount;
	int StageID;
	int m_time;
	//エンドレスタイム
	int e_time;
	int enemyAmo;
	//int e_num;//敵の個体名
	bool m_key_flag;
	int randomAppearTime;
	float appearEnemyX;

	//ボス登場中
	bool BossAppearRing;
	int enemyCount;

};