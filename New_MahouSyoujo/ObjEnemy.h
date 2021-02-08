#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G�@
class CObjEnemy : public CObj
{
public:
	CObjEnemy(float x,float y,float vx=0,float vy=0);
	~CObjEnemy() {};
	void Init();
	void Action();
	void Draw();
//	int EneAmo();
private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	int e_hp;//�G��HP
	int e1_damege;//�_���[�W��
	int e1_time;//�G�̍U������
	int e1_anime;

	float b_mx;//�o���A��x�ʒu

	float m_mx;//�}�i��X�ʒu
	float m_my;//�}�i��Y�ʒu 
	//int Amount;
	
	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	bool e1_t;//�G�̍U���Ԋu

	float damage;//�G���󂯂�_���[�W

	bool e_delete;//�G����
	int delete_time;

	int m_posture;
};
