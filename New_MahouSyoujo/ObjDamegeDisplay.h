#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:
	CObjDamegeDisplay(float x, float y, int posture);
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float Sword_ATK;//���̍U����
	float Mana_Damege;//�}�i�̎󂯂�_���[�W
	float Damege_x;//�_���[�W�\�L����X��
	float Damege_y;//�_���[�W�\�L����Y��

	int d_time;
	int appear_type;
	int Sword_posture;
};