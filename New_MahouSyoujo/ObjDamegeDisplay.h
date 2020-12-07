#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:
	CObjDamegeDisplay(float x, float y, int posture);
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float Sword_ATK;//剣の攻撃力
	float Mana_Damege;//マナの受けるダメージ
	float Damege_x;//ダメージ表記するX軸
	float Damege_y;//ダメージ表記するY軸

	int d_time;
	int appear_type;
	int Sword_posture;
};