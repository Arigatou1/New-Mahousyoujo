#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�}�i
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
private:
	float Mana_HP;
	float Mana_x;
	float Mana_y;
	int shootDownTime;

	float mana_damege;//
};

