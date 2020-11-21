#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//ホーミング弾
class CObjAllBullet :public CObj
{
public:
	CObjAllBullet(float x, float y);//コンストラクタ
	~CObjAllBullet() {};
	void Init();
	void Action();
	void Draw();
	int GetZ_ATK();
private:
	float m_ax;//弾丸のX位置
	float m_ay;//弾丸のY位置

	float m_avx;//弾丸Xの変数
	float m_avy;//弾丸Yの変数
	float z_atk;//攻撃力
};
