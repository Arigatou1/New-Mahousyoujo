#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
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
	float Sword_ATK;
	float Sword_x;
	float Sword_y;

	int d_time;
	int Sword_posture;
};