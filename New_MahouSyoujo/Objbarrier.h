#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjBarrier : public CObj
{
public:
	CObjBarrier(float x);
	~CObjBarrier() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
	float GetBX();//�o���A��x���W
private:
	float mb_x;
	float b_time;//�o���A�̏o�Ă鎞��

	int b_skill;//���@�����̃X�L���I��
	int b_mp;

	bool b_t;//�o���A�̊Ԋu(��)
};