#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjGaugeMANAHP :public CObj
{
public:
	CObjGaugeMANAHP(float x,float y) ;
	~CObjGaugeMANAHP() {};
	void Init();
	void Action();
	void Draw();
	float GetPercent();
private:
	float HP;
	float GaugePercent;
	float gb_x;
	float gb_y;

	float xoffset;
	float yoffset;

};

