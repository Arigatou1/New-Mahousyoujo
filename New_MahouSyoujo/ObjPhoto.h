#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjPhoto : public CObj
{
public:
	CObjPhoto(float src_top, float src_left,float src_right,float src_bottom,
				float x_size, float y_size, float dst_top, float dst_left, int g,int n);
	~CObjPhoto() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	float size_x;//�\������A�C�R���̑傫��
	float size_y;
	float s_t;//top
	float s_l;//left
	float s_r;//right
	float s_b;//bottom
	float d_t;//�\��top
	float d_l;//�\��left
	int Graphic_Serct;//�摜�̕ύX�p

	int p_num;//���݂̔ԍ��i�H�j
	int p_order;//�`���[�g���A���̏���
};