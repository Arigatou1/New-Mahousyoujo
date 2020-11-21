#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�e��
class CObjBullet :public CObj
{
public:
	CObjBullet(float x, float y, int posture, bool m_f) ;//�R���X�g���N�^
	~CObjBullet() {};
	void Init();
	void Action();
	void Draw();
	float GetAttackPower();
private:

	float px;
	float py;
	float vx;
	float vy;

	int b_posture;
	bool b_f;
	float atk_power;
};