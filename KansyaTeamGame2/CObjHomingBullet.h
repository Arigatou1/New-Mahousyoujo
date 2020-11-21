#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//ホーミング弾
class CObjHomingBullet :public CObj
{
public:
	CObjHomingBullet(float x,float y,float m);//コンストラクタ
	~CObjHomingBullet() {};
	void Init();
	void Action();
	void Draw();
	int GetM_ATK();
private:
	float m_bx;//弾丸のX位置
	float m_by;//弾丸のY位置
	float m_bpostrue;//向き
	float m_vx;//弾丸Xの変数
	float m_vy;//弾丸Yの変数
	float m_atk;//攻撃力
};