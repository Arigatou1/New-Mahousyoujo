#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�R
class CObjEnemy3 :public CObj
{
public:
	CObjEnemy3(float x, float y);
	~CObjEnemy3() {};
	void Init();
	void Action();
	void Draw();

private:
	float m_ex;		//X���W
	float m_ey;		//Y���W
	float m_vx;		//�ړ��x�N�g��
	float m_vy;

	
	int e_damege;

	float b_mx;//�o���A�̈ʒu
	float b_my;
	

	float m_mx; //�}�i�̍��W
	float m_my;

	float jump;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool e3_hit_up;
	bool e3_hit_down;
	bool e3_hit_right;
	bool e3_hit_left;

	float e3_xsize;
	float e3_ysize;

	float e_hp;
	float damage;
};
