//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"

#include "GameHead.h"
#include "ObjIcon.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjIcon::Init()
{
}

//�A�N�V����
void CObjIcon::Action()
{
	//-------- 2021 2 1 �M���@�ύX--------
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
		if (obj_magicalgirl != nullptr)
		{
			b_skill = obj_magicalgirl->GetSkill() - 1;
		}




	//--------�����܂�--------------------

	if (serect == false)
	{
		CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
		if (obj_magicalgirl != nullptr)
		{
			b_skill = obj_magicalgirl->GetSkill();
		}
	}
	else if(serect == true)
	{
		TutorialHero* obj_tutorialhero = (TutorialHero*)Objs::GetObj(OBJ_TUTORIALHERO);
		if (obj_tutorialhero != nullptr)
		{
			b_skill = obj_tutorialhero->GetSkill();
		}
		CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
		if (obj_tutorial != nullptr)
		{
 			i_order = obj_tutorial->GetOrder();
		}
	}

	//�q�[��
	if (Graphic_Serct == 12)
	{
		if (b_skill == 1 )
		{
			Graphic_Serct = 13;
		}
	}
	else if (Graphic_Serct == 13)
	{
		if (b_skill != 1)
		{
			Graphic_Serct = 12;
		}
	}

	////�o���A
	if (Graphic_Serct == 10)
	{
		if (b_skill == 2)
		{
			Graphic_Serct = 11;
		}

	}
	else if (Graphic_Serct == 11)
	{
		if (b_skill != 2)
		{
			Graphic_Serct = 10;
		}
	}

	////���e�I
	if (Graphic_Serct == 14)
	{
		if (b_skill == 3)
		{
			Graphic_Serct = 15;
		}

	}
	else if (Graphic_Serct == 15)
	{
		if (b_skill != 3)
		{
			Graphic_Serct = 14;
		}
	}

	if (i_order == 6 && Graphic_Serct == 13)
	{
		//����6�������Ƃ��q�[���̃A�C�R����^�񒆂ɑ傫���o��
		icon_size = 120;
		i_x = 250.0f;
		i_y = 250.0f;
	}
	else if (i_order == 7 && Graphic_Serct == 11)
	{
	//	//����7�������Ƃ��o���A�̃A�C�R����^�񒆂ɑ傫���o��
		icon_size = 120;
		i_x = 250.0f;
		i_y = 250.0f;
	}
	else if (i_order == 8 && Graphic_Serct == 15)
	{
	//	//����8�������Ƃ����e�I�̃A�C�R����^�񒆂ɑ傫���o��
	icon_size = 120;
		i_x = 250.0f;
		i_y = 250.0f;
	}
	else
	{
		icon_size = size_spare;
		i_x = x_spare;
		i_y = y_spare;
	}
}
//�h���[
void CObjIcon::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 384.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 736.0f;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 192.0f;

	//�`��
	Draw::Draw(10, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 384.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 512.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = (b_skill * 64);
	dst.m_left = 736.0f;
	dst.m_right = dst.m_left + 64.0f;
	dst.m_bottom = dst.m_top + 64.0f;

	//�`��
	Draw::Draw(10, &src, &dst, c, 0.0f);

}