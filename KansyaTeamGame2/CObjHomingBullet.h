#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�z�[�~���O�e
class CObjHomingBullet :public CObj
{
public:
	CObjHomingBullet(float x,float y,float m);//�R���X�g���N�^
	~CObjHomingBullet() {};
	void Init();
	void Action();
	void Draw();
	int GetM_ATK();
private:
	float m_bx;//�e�ۂ�X�ʒu
	float m_by;//�e�ۂ�Y�ʒu
	float m_bpostrue;//����
	float m_vx;//�e��X�̕ϐ�
	float m_vy;//�e��Y�̕ϐ�
	float m_atk;//�U����
};