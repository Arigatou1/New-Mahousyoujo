#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�z�[�~���O�e
class CObjAllBullet :public CObj
{
public:
	CObjAllBullet(float x, float y);//�R���X�g���N�^
	~CObjAllBullet() {};
	void Init();
	void Action();
	void Draw();
	int GetZ_ATK();
private:
	float m_ax;//�e�ۂ�X�ʒu
	float m_ay;//�e�ۂ�Y�ʒu

	float m_avx;//�e��X�̕ϐ�
	float m_avy;//�e��Y�̕ϐ�
	float z_atk;//�U����
};
