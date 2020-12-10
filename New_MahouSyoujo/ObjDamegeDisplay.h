#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:

	/// <summary>
	/// �_���[�W�f�B�X�v���C�@�ύX
	/// 12/10 �M��
	/// 
	/// �����A��ނ̈����͊��S�ɗv��Ȃ��āA
	/// �e�I�u�W�F�N�g���炱�̃I�u�W�F�N�g���쐬����Ƃ���
	/// �_���[�W���l�ƐF���w�肷��΂����񂶂�Ȃ��́H�Ǝv��
	/// �ύX���Ă݂��B
	/// 
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="posture"></param>
	/// <param name="atk"></param>
	/// <param name="damage"></param>
	CObjDamegeDisplay(float x, float y,int damage=0,int color=0);
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_Damege;//�󂯂�or�^�����_���[�W
	float Damege_x;//�_���[�W�\�L����X��
	float Damege_y;//�_���[�W�\�L����Y��

	int d_time;
	int color_type;
};