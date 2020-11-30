#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g��l��
class CObjHero :public CObj
{
public :
	CObjHero() {};
	~CObjHero() ;
	void Init();
	void Action();
	void Draw();
	float GetX() { return m_px; };
	float GetY() { return m_py; };
	float GetVY() { return m_vy; };
	float GetVX() { return m_vx; };

	float SetX(float x) { return m_px=x; };
	float SetY(float y) { return m_py=y; };
	float SetVY(float vy) { return m_vy = vy; };
	float SetVX(float vx) { return m_vx = vx; };
	int GetHP();
	int GetMAXHP();
	int GetMP();

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_px;		//�v���C���[�̍��WX
	float m_py;		//�v���C���[�̍��WY
	float m_vx;		//�v���C���[�̃x�N�g��X
	float m_vy;		//�v���C���[�̃x�N�g��Y
	float m_posture;//�����Ă�������p

	int m_mp;   //���݂�MP
	int m_Skill;//���@�����̃X�L���I��


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

	bool h_t;//�񕜊Ԋu

	bool m_f;		//�U���̊Ԋu
	bool isJump;//�W�����v�ł��邩�ł��Ȃ����𔻒f����

	//block�Ƃ̏Փˏ�Ԋm�F�p
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	float h_xsize;
	float h_ysize;

	int Weapon;//��l���̕���
	float damage;//��l�����󂯂�_���[�W
	float AllDamage;//��l�����󂯂��_���[�W

//	int shootDownTime;
	bool HPZeroCheck;
};