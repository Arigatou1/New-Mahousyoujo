#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjIcon : public CObj
{
public:
	CObjIcon(int size , float x , float y,int g, bool s);
	~CObjIcon() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	int b_skill;//���@�����̃X�L���I��

	int icon_size;//�\������A�C�R���̑傫��
	float i_x;//�\������摜�̍����X���W
	float i_y;//�\������摜�̍����Y���W
	int Graphic_Serct;//�摜�̕ύX�p
	int i_order;//�`���[�g���A���̏���

	bool serect;//true = �`���[�g���A���p false = ���C��


	int size_spare;//�T�C�Y�̃o�b�N�A�b�v
	float x_spare;// X���W�̃o�b�N�A�b�v
	float y_spare;// Y���W�̃o�b�N�A�b�v
};