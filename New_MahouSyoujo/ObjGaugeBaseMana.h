#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjGaugeMANABase :public CObj
{
public:
	CObjGaugeMANABase(float x,float y);
	~CObjGaugeMANABase() {};
	void Init();
	void Action();
	void Draw();
private:
	float gb_x;
	float gb_y;

	float xoffset;
	float yoffset;

};

