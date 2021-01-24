//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjPhoto.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjPhoto::CObjPhoto(float src_top, float src_left, float src_right, float src_bottom,
					float x_size, float y_size, float dst_top, float dst_left, int g,int n)
{
	size_x = x_size;
	size_y = y_size;
	s_t = src_top;
	s_l = src_left;
	s_r = src_right;
	s_b = src_bottom;
	d_t = dst_top;
	d_l = dst_left;
	Graphic_Serct = g;
	p_num = n;
}

//�C�j�V�����C�Y
void CObjPhoto::Init()
{
}

//�A�N�V����
void CObjPhoto::Action()
{
	CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
	if (obj_tutorial != nullptr)
	{
		p_order = obj_tutorial->GetOrder();
	}
	if (p_num + 1 == p_order)
		this->SetStatus(false);
}

//�h���[
void CObjPhoto::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = s_t;
	src.m_left = s_l;
	src.m_right = s_r;
	src.m_bottom = s_b;

	//�\���ʒu�̐ݒ�
	dst.m_top = d_t;
	dst.m_left = d_l;
	dst.m_right = dst.m_left + size_x;
	dst.m_bottom = dst.m_top + size_y;

	//�`��
	Draw::Draw(Graphic_Serct, &src, &dst, c, 0.0f);
}