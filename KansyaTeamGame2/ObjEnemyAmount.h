#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：ゲームオーバー
class CObjEnemyAmount : public CObj
{
public:
	CObjEnemyAmount() {};
	~CObjEnemyAmount() {};
	void Init();
	void Action();
	void Draw();
private:
	int EnemyAmount;
};