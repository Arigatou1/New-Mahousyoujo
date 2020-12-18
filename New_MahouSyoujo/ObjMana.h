#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

//オブジェクトマナ
class CObjMana :public CObj
{
public:
	CObjMana(float x,float y);
	~CObjMana() ;
	void Init();
	void Action();
	void Draw();
	float GetHP();
	float GetX();
	float GetY();
	float GetDamege();
private:
	float Mana_HP;
	float Mana_x;
	float Mana_y;
	int shootDownTime;

	float MANA_damege;

	float mana_damege;//
};

