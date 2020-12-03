#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//#include "ObjHero.h"
//使用するネームスペース
using namespace GameL;

//オブジェクトソード
class CObjSword :public CObj
{
public:
	CObjSword(float x,float y,int posture,bool m_f) ;
	~CObjSword() {};
	void Init();
	void Action();
	void Draw();
	float GetAttackPower();
private:
	float a_px;
	float a_py;
	int a_posture;
	bool a_f;
	int atk_time;
	float atk_power;
};

