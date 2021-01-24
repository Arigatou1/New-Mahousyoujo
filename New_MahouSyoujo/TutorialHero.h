#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class TutorialHero :public CObj
{
public:
	TutorialHero() {};
	~TutorialHero();
	void Init();
	void Action();
	void Draw();
	int GetSkill() { return m_skill; };
	int GetTime() { return m_time; };
private:
	float m_px;		//�v���C���[�̍��WX
	float m_py;		//�v���C���[�̍��WY
	float m_vx;		//�v���C���[�̃x�N�g��X
	float m_vy;		//�v���C���[�̃x�N�g��Y
	float m_posture;//�����Ă�������p

	int m_mp;   //���݂�MP
	int m_Skill;//���@�����̃X�L���I��

	int m_order;//�`���[�g���A���̏���
	int m_time;//�`���[�g���A���̎���
	int m_num;//���[�v���鎞��
	int m_skill;//�A�C�R���̃X�L��
	bool icon;//�A�C�R���̕\��

	int m_anime;	//�����A�j���[�V����
	int m_anitime;	//�����A�j���[�V�����̊Ԋu

	int atk_anime;	//�����o��
	int atk_anitime;//
	int atk_time;	//�U���̊Ԋu

	float m_hp;//�v���C���[�̗̑�
	float max_hp;
	int mtk_jkn;//���G���ԗp�ϐ�
	int mtk_max;//���G���ԗp�ϐ�
	bool m_mtk;//��l���̖��G����

	bool m_f;		//�U���̊Ԋu
	bool isJump;//�W�����v�ł��邩�ł��Ȃ����𔻒f����

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;


	int Weapon;//��l���̕���
	float damage;//��l�����󂯂�_���[�W
	float AllDamage;//��l�����󂯂��_���[�W
	float HeroDamage;

	int shootDownTime;
	//	bool HPZeroCheck;

	bool clear_check;
};