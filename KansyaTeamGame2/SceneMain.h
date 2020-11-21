#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
class CSceneMain :public CScene
{
public:
	CSceneMain();
	~CSceneMain();
	void InitScene();//初期化メソッド
	void Scene();//実行中メソッド
private:
	int m_time;
	int EnemyAmount;
	bool m_key_flag;
};