#pragma once
//�g�p����w�b�_�[
#include"GameL/SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�G�R
class CObjEnemy4 :public CObj
{
public:
	CObjEnemy4(float x, float y);
	~CObjEnemy4() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_ex;//X���W
	float m_ey;//Y���W
	float m_vx;//�ړ��x�N�g��	
	float m_vy;
	float m_r;//�p�x

	
	int e4_damege;
	

	float m_mx;//�}�i��X�ʒu
	float m_my;//�}�i��Y�ʒu

	float m_hx;//hero��x�ʒu
	float m_hy;//hero�̂��ʒu

	float b_mx;//�o���A��x�ʒu
	//int Amount;
	float e_hp;
	float damage;
	int a_time;
};