//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjCustomize.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjCustomize::Init()
{
	m_key_flag = false;//�L�[�t���O
	
	cursor_x = 32.0f;
	cursor_y = 64.0f;
	nowSelect = 0;
}

//�A�N�V����
void CObjCustomize::Action()
{

	//�J�[�\���̈ʒu����nowSelect���擾����B
	nowSelect = (cursor_y - 64) / 112;




	if (Input::GetVKey(VK_RETURN) == true||Input::GetVKey(VK_ESCAPE) == true)
	{
		if (m_key_flag == true)
		{
			Audio::Start(9);
			Save::Seve();
			this->SetStatus(false);
			//���j���[�I�u�W�F�N�g�쐬
			CObjStageSelect* obj = new CObjStageSelect();
			Objs::InsertObj(obj, OBJ_STAGESELECT, 2);
		}
	}

	else if (Input::GetVKey(VK_UP) == true)
	{
		if (m_key_flag == true)
		{
			Audio::Start(10);
			cursor_y -= 112;
			
			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		
		if (m_key_flag == true)
		{
			Audio::Start(10);
			cursor_y += 112;
		
			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
	
		if (m_key_flag == true)
		{
			Audio::Start(10);
			switch (nowSelect)
			{
			case 0:
				if (((UserData*)Save::GetData())->weapon==1)
				{
					((UserData*)Save::GetData())->weapon = 0;
				}
				break;

			default:

				break;
			}



			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		
		if (m_key_flag == true)
		{

			Audio::Start(10);

			switch (nowSelect)
			{
			case 0:
				if (((UserData*)Save::GetData())->weapon == 0)
				{
					((UserData*)Save::GetData())->weapon = 1;
				}
				break;

			default:

				break;
			}


			m_key_flag = false;
		}
	}
	else
		m_key_flag = true;

	//�J�[�\������ʂ��s���Ȃ�����(��)
	if (cursor_y < 64)
		cursor_y = 64;

	if (cursor_y > 176)
		cursor_y = 176;

	//default�Z�b�e�B���O
	if(((UserData*)Save::GetData())->weapon >1 || ((UserData*)Save::GetData())->weapon < 0)
	((UserData*)Save::GetData())->weapon = 0;

}

//�h���[
void CObjCustomize::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	Font::StrDraw(L"GAME Customize", 2, 2, 32, c);

	MenuBlockDraw(32, 64.0f, 728.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);

	MenuBlockDraw(cursor_x, cursor_y, 728.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);

	wchar_t str1[128];
	wchar_t weap[16];

	switch (((UserData*)Save::GetData())->weapon)
	{
	case 0:
		swprintf_s(weap, L"��");
		break;

	case 1:
		swprintf_s(weap, L"���e");
		break;

	}

	swprintf_s(str1, L"��l���̕���:%s", weap);
	Font::StrDraw(str1, 32, 64, 64, c);


	

	//�؂���ʒu�̐ݒ�
	src.m_top =0.0f;
	src.m_left = 64.0f;
	src.m_right =  128.0f;
	src.m_bottom = 64.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f ;
	dst.m_left =  332.0f;
	dst.m_right =  396.0f;
	dst.m_bottom = 64.0f;

	//�`��
	for(int i=0;i<4;i++)
	Draw::Draw(0, &src, &dst, c, i*90.0f);
}

//MenuBlockDraw�֐�
