//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjBarrierIcon.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjBarrierIcon::Init()
{
	Graphic_Serct = 0;
}

//�A�N�V����
void CObjBarrierIcon::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		b_skill = obj_magicalgirl->GetSkill();
	}

	if (b_skill == 2)
	{
		Graphic_Serct = 11;
	}
	else
		Graphic_Serct = 10;
}
//�h���[
void CObjBarrierIcon::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 0.0f;
	src.m_left   = 0.0f;
	src.m_right  = 200.0f;
	src.m_bottom = 200.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 64.0f;
	dst.m_left   = 736.0f;
	dst.m_right  = 800.0f;
	dst.m_bottom = 128.0f;

	//�`��
	Draw::Draw(Graphic_Serct, &src, &dst, c, 0.0f);
}