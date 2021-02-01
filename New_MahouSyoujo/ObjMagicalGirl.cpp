//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"
#include "GameL/Audio.h"

//#include <stdlib.h">

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
	
	m_skill = 1;//1�Ȃ�� 2�Ȃ�o���A 3�Ȃ�S��

	m_key_flag = false;
}

//�A�N�V����
void CObjMagicalGirl::Action()
{
	m_mtime++;
	
	//��l����HP�ƃ}�b�N�XHP�Ƃ��Ă���
	CObjHero* obj_hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if(obj_mana != nullptr)
	{
		m_gx = obj_mana->GetX();
		m_gy = obj_mana->GetY();
	}

	CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
	
	//(�����炭1�b��1)MP��
	if (m_mp < 100)
	{

		if (m_mtime % 60 == 0)
		{
			//�`���[�g���A���̎�
			if (obj_tutorial != nullptr)
				m_mp += 10;
			else                          //�`���[�g���A���ȊO
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
		Audio::Start(1);
	
		m_skill += 1;
		s_t = false;

		if (m_skill == 4)
			{
				m_skill = 1;
			}
	}
	else if (Input::GetVKey(VK_DOWN) == true && s_t == true)
	{
		Audio::Start(1);

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
	
	
	// 2021 01 28 �M�� �ύX----------------------------------
	m_atk_animation = 0;//�_�����̎p�ɂȂ�

	if (Input::GetVKey('D') == true)
	{
		if (m_key_flag == true)
		{
			switch (m_skill)
			{
			case 1:
			
				if (obj_hero != nullptr)
				{
					//HP���^���HMP��20�ȏ�̏ꍇ
					if (m_mp >= 20 && obj_hero->GetHP() < obj_hero->GetMAXHP())
					{
						//�񕜖��@
						Audio::Start(22);
						m_mp -= 20;
						obj_hero->AddHP(3);
					}
				}
				break;
			case 2:
				//�o���A
				if (m_mp >= 30 && (CObjBarrier*)Objs::GetObj(OBJ_BARRIER)==nullptr)
				{
					Audio::Start(23);
					//Barrier�I�u�W�F�N�g
					CObjBarrier* objbarrier;
					objbarrier = new CObjBarrier(m_gx + 64.0f);
					Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
					objbarrier = new CObjBarrier(m_gx - 32.0f);
					Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);

					m_mp -= 30;
				}
				break;
			case 3:
				//�S�̍U��
				if (m_mp >= 50)
				{
					Audio::Start(21);
					m_mp -= 50;

					float z_x[] = { 0,700,200,500,736,100,300,600,400,64 };

					for (int i = 0; i < 10;i++ )
					{
						//���@�������@�ʍ쐬
						CObjAllBullet* obj_allbullet = new CObjAllBullet(z_x[i],(i*-64)-64);//�z�[�~���O�e�쐬
						Objs::InsertObj(obj_allbullet, OBJ_ALLBULLET, 60);//�I�u�W�F�N�g�}�l�[�ɓo�^
					
					}
				}

				break;
			default:
				break;
			}
			m_key_flag = false;
		}

		m_atk_animation = 3;//�񎝂����p�ɂȂ�
	}
	else
	{
		m_key_flag = true;
	}

	//----�����܂�-----------------------------------------

	//���@�����̉񕜖��@
	//
	//		if (Input::GetVKey('D') == true && h_t == true && m_skill == 1)
	//		{
	//			Audio::Start(22);
	//			m_atk_animation = 3;//�񎝂����p�ɂȂ�
	//			h_t = false;
	//			m_mp -= 20;
	//			if (h_hp > 20)
	//				h_hp = 20;
	//		}
	//		else if (Input::GetVKey('D') == false)
	//		{
	//			h_t = true;
	//		}

	////���@�����̃o���A
	//if (Input::GetVKey('D') == true && b_t == true && m_skill == 2)
	//	{
	//		Audio::Start(23);
	//		m_atk_animation = 3;//�񎝂����p�ɂȂ�
	//		m_btime = 0;
	//		b_t = false;
	//		m_mp -= 30;
	//		if (m_btime == 0)
	//		{
	//			//Barrier�I�u�W�F�N�g
	//			CObjBarrier* objbarrier;
	//			objbarrier = new CObjBarrier(m_gx + 64.0f);
	//			Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
	//			objbarrier = new CObjBarrier(m_gx - 32.0f);
	//			Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
	//		}
	//	}
	//	else if (Input::GetVKey('D') == false && m_btime > 300)
	//	{
	//		b_t = true;
	//	}
	//

	////���@�����̑S�̍U��
	//
	//	if (Input::GetVKey('D') == true && z_t == true && m_skill == 3)
	//	{
	//		Audio::Start(21);
	//		m_atk_animation = 3;//�񎝂����p�ɂȂ�
	//		z_t = false;
	//		m_mp -= 50;
	//		for (int i = 0; i< 10; )
	//		{
	//			switch (i)
	//			{
	//			case 0:
	//				z_x = 0.0f;
	//				z_y = 0.0f;
	//				break;
	//			case 1:
	//				z_x = 700.0f;
	//				z_y = -64.0f;
	//				break;
	//			case 2:
	//				z_x = 200.0f;
	//				z_y = -128.0f;
	//				break;
	//			case 3:
	//				z_x = 500.0f;
	//				z_y = -192.0f;
	//				break;
	//			case 4:
	//				z_x = 736.0f;
	//				z_y = -256.0f;
	//				break;
	//			case 5:
	//				z_x = 100.0f;
	//				z_y = -320.0f;
	//				break;
	//			case 6:
	//				z_x = 300.0f;
	//				z_y = -384.0f;
	//				break;
	//			case 7:
	//				z_x = 600.0f;
	//				z_y = -448.0f;
	//				break;
	//			case 8:
	//				z_x = 400.0f;
	//				z_y = -512.0f;
	//				break;
	//			case 9:
	//				z_x = 64.0f;
	//				z_y = -576.0f;
	//				break;
	//			}
	//			//���@�������@�ʍ쐬
	//			CObjAllBullet* obj_allbullet = new CObjAllBullet(z_x, z_y);//�z�[�~���O�e�쐬
	//			Objs::InsertObj(obj_allbullet, OBJ_ALLBULLET, 60);//�I�u�W�F�N�g�}�l�[�ɓo�^
	//			i++;
	//			if (z_x >= 800)
	//			{
	//				break;
	//			}
	//		}
	//	}
	//	else if (Input::GetVKey('D') == false)
	//	{
	//		z_t = true;
	//	}
	//

		
}

//�h���[
void CObjMagicalGirl::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,1.0f,0.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

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

int CObjMagicalGirl::GetHP()
{
	return h_hp;
}
