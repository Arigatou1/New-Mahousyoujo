#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:
	CObjDamegeDisplay(float x, float y, int posture,float atk,int damage=0);
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_Damege;//�󂯂�or�^�����_���[�W
	float Damege_x;//�_���[�W�\�L����X��
	float Damege_y;//�_���[�W�\�L����Y��

	int d_time;
	int display_type;
	int Sword_posture;
};