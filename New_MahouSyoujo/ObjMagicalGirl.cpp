//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMagicalGirl::Init()
{
	m_maxmp = 100;
	m_mp =m_maxmp;//MP����100
	
	m_postrue = 1.0f;//�E����0.0f ������1.0f
	m_atk_animation = 0;//0=�_�����̉摜

	m_mtime = 1;
	m_btime = 100;

	z_y = 0.0f;

	m_skill = 1;//1�Ȃ�� 2�Ȃ�o���A 3�Ȃ�S��
}

//�A�N�V����
void CObjMagicalGirl::Action()
{
	m_mtime++;
	m_btime++;

	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if(obj_mana != nullptr)
	{
		m_gx = obj_mana->GetX();
		m_gy = obj_mana->GetY();
	}
	
	//(�����炭1�b��1)MP��
	if (m_mp < 100)
	{

		if (m_mtime % 60 == 0)
		{
			m_mp++;
			m_mtime = 0;
		}
	}

	//�L�[�������ƌ����ύX
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 0.0f;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 1.0f;
	}

	//�㉺�L�[�������ƃX�L���ύX
	if (Input::GetVKey(VK_UP) == true && s_t == true)
	{
		m_skill += 1;
		s_t = false;

		if (m_skill == 4)
			{
				m_skill = 1;
			}
	}
	else if (Input::GetVKey(VK_DOWN) == true && s_t == true)
	{
		m_skill -= 1;
		s_t = false;

		if (m_skill == 0)
			{
				m_skill = 3;
			}
	}
	else if(Input::GetVKey(VK_UP) == false && Input::GetVKey(VK_DOWN) == false)
	{
		s_t = true;
	}

	//���@�����̒ʏ�U��
	if (m_mp >= 5)
	{
		if (Input::GetVKey('D') == true && m_t == true)
		{
			m_atk_animation = 3;//�񎝂����p�ɂȂ�

				//���@�U��SE
			Audio::Start(1);

			if (m_postrue == 0.0f)
			{
				m_t = false;
				//���@�������@�ʍ쐬
				CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx - 25.0f, m_gy, m_postrue);//�z�[�~���O�e�쐬
				Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 60);//�I�u�W�F�N�g�}�l�[�ɓo�^

				m_mp -= 5;

				if (m_mp < 0)
				{
					m_mp = 0;
				}
			}
			else if (m_postrue == 1.0f)
			{
				m_t = false;
				//���@�������@�ʍ쐬
				CObjHomingBullet* obj_homingbullet = new CObjHomingBullet(m_gx + 25.0f, m_gy, m_postrue);//�z�[�~���O�e�쐬
				Objs::InsertObj(obj_homingbullet, OBJ_HOMINGBULLET, 60);//�I�u�W�F�N�g�}�l�[�ɓo�^

				m_mp -= 5;

				if (m_mp < 5)
				{
					m_mp = 0;
				}
			}
		}
		else if (Input::GetVKey('D') == false)
		{
			m_atk_animation = 0;//�_�����̎p�ɂȂ�
			m_t = true;
		}
	}

	//���@�����̉񕜖��@
	if (m_mp >= 20)
	{
		if (Input::GetVKey('H') == true && h_t == true && m_skill == 1)
		{
			h_t = false;
			CObjHero* obj_hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
			if (obj_hero != nullptr)
			{
				m_mp = obj_hero->GetMP();
			}
		}
		else if (Input::GetVKey('H') == false)
		{
			h_t = true;
		}
	}
	
	//���@�����̃o���A
	if (m_mp >= 30)
	{
		if (Input::GetVKey('H') == true && b_t == true && m_skill == 2)
		{
			m_btime = 0;
			b_t = false;
			m_mp -= 30;

			if (m_btime == 0)
			{
				//Barrier�I�u�W�F�N�g
				CObjBarrier* objbarrier;
				objbarrier = new CObjBarrier(m_gx + 64.0f, m_gy);
				Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
				objbarrier = new CObjBarrier(m_gx - 32.0f, m_gy);
				Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
			}
		}
		else if (Input::GetVKey('H') == false && m_btime > 200)
		{
			b_t = true;
		}
	}

	//���@�����̑S�̍U��
	if (m_mp >= 50)
	{
		if (Input::GetVKey('H') == true && z_t == true && m_skill == 3)
		{
			m_atk_animation = 3;//�񎝂����p�ɂȂ�
			z_t = false;
			m_mp -= 50;

			for (int i = 0; i < 15; i++)
			{
				z_x = 64.0f * i;

				//���@�������@�ʍ쐬
				CObjAllBullet* obj_allbullet = new CObjAllBullet(z_x, z_y);//�z�[�~���O�e�쐬
				Objs::InsertObj(obj_allbullet, OBJ_ALLBULLET, 60);//�I�u�W�F�N�g�}�l�[�ɓo�^

				if (z_x >= 800)
				{
					break;
				}
			}
		}
		else if (Input::GetVKey('H') == false)
		{
			m_atk_animation = 0;//�_�����̎p�ɂȂ�
			z_t = true;
		}
	}
}

//�h���[
void CObjMagicalGirl::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	if (m_skill == 1)
	{
		wchar_t str[128];
		swprintf_s(str, L"�X�L��:�q�[��");//�����𕶎���
		Font::StrDraw(str, 550, 5, 36, c);
	}
	else if (m_skill == 2)
	{
		wchar_t str[128];
		swprintf_s(str, L"�X�L��:�o���A");//�����𕶎���
		Font::StrDraw(str, 550, 5, 36, c);
	}
	else if (m_skill == 3)
	{
		wchar_t str[128];
		swprintf_s(str, L"�X�L��:���e�I");//�����𕶎���
		Font::StrDraw(str, 550, 5, 36, c);
	}

	//�؂���ʒu�̐ݒ�
	src.m_top    = 128.0f;
	src.m_left   = (m_atk_animation * 64.0f) + 0.0f;
	src.m_right  = (m_atk_animation * 64.0f) + 64.0f;
	src.m_bottom = 192.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top	 =0.0f  + m_gy;
	dst.m_left   =0.0f  + (m_gx + 64.0f * m_postrue);
	dst.m_right  =64.0f + (m_gx - 64.0f * m_postrue);
	dst.m_bottom =64.0f + m_gy;

	//�`��
	Draw::Draw(0,&src,&dst,c,0.0f);
}

int CObjMagicalGirl::GetMP()
{
	return m_mp;
}

int CObjMagicalGirl::GetMaxMP()
{
	return m_maxmp;
}

int CObjMagicalGirl::GetSkill()
{
	return m_skill;
}