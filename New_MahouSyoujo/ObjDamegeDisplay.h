#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:
	CObjDamegeDisplay(float x, float y, int posture,float atk,int damage=0);
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_Damege;//受けたor与えたダメージ
	float Damege_x;//ダメージ表記するX軸
	float Damege_y;//ダメージ表記するY軸

	int d_time;
	int display_type;
	int Sword_posture;
};