#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G�@
class CObjEnemy2 : public CObj
{
public:
	CObjEnemy2(float x, float y) ;
	~CObjEnemy2() {};
	void Init();
	void Action();
	void Draw();
	float GetE2_ATK();

	
private:
	int e2_time;//�G2�̍U���X�s�[�h

	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	int e2_hp;//�G�Q��HP
	int e2_damege;//�_���[�W��

	float e2_atk;//�G�Q�̍U����

	float b_mx;//�o���Ax�ʒu

	float m_mx;//�}�i��X�ʒu
	float m_my;//�}�i��Y�ʒu
	//int Amount;


	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool e1_hit_up;
	bool e1_hit_down;
	bool e1_hit_left;
	bool e1_hit_right;

	float e1_xsize;
	float e1_ysize;

	bool e2_t;//�G2�̍U���Ԋu
	bool e2_hit_up;
	bool e2_hit_down;
	bool e2_hit_left;
	bool e2_hit_right;

	float e_hp;
	float damage;
};
