#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//#include "ObjHero.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjSword :public CObj
{
public:
	CObjSword(float x,float y,int posture,bool m_f) ;
	~CObjSword() {};
	void Init();
	void Action();
	void Draw();
	float GetAttackPower();
	float Geta_px();
	float Geta_py();
private:
	float a_px;
	float a_py;
	int a_posture;
	bool a_f;
	int atk_time;
	float atk_power;
};

