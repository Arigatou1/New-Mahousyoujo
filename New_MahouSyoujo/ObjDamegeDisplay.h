#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:
	CObjDamegeDisplay() {};
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float Sword_ATK;
	int d_time;
};