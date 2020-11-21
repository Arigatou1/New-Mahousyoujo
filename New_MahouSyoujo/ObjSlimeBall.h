#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�G�@
class CObjSlimeBall : public CObj
{
public:
	CObjSlimeBall(float x, float y, float vx = 0, float vy = 0);
	~CObjSlimeBall() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_ex;
	float m_ey;
	float m_vx;
	float m_vy;
	

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

	float e1_xsize;
	float e1_ysize;
};
