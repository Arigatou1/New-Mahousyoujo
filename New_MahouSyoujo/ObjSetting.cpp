//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjSetting.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjSetting::Init()
{
	cursor_x = 32;
	cursor_y = 64;
	nowSelect = 0;
}

//�A�N�V����
void CObjSetting::Action()
{

	//�J�[�\���̈ʒu����nowSelect���擾����B
	nowSelect = (cursor_y - 64) / 112;


	if (Input::GetVKey(VK_RETURN) == true || Input::GetVKey(VK_ESCAPE) == true)
	{
		if (m_key_flag == true)
		{
			Save::Seve();

			this->SetStatus(false);
			//���j���[�I�u�W�F�N�g�쐬
			CObjModeSelect* obj = new CObjModeSelect();
			Objs::InsertObj(obj, OBJ_MODESELECT, 2);
		}
	}


	else if (Input::GetVKey(VK_UP) == true)
	{
		//�I��
	//	Audio::Start(4);
		
		if (m_key_flag == true)
		{
			cursor_y -= 112;

			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_DOWN) == true)
	{
		
		if (m_key_flag == true)
		{

			cursor_y += 112;

			m_key_flag = false;
		}
	}

	else if (Input::GetVKey(VK_LEFT) == true)
	{
		
	
		if (m_key_flag == true)
		{
			switch (nowSelect)
			{
			case 0:
				if(((UserData*)Save::GetData())->Diffculty>0)
				((UserData*)Save::GetData())->Diffculty--;
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


			switch (nowSelect)
			{
			case 0:
				if (((UserData*)Save::GetData())->Diffculty < 2)
					((UserData*)Save::GetData())->Diffculty++;
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
}

//�h���[
void CObjSetting::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	Font::StrDraw(L"GAME Setting", 2, 2, 32, c);

	MenuBlockDraw(32, 64.0f, 728.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);

	MenuBlockDraw(cursor_x, cursor_y, 728.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);

	wchar_t str1[128];
	wchar_t Diff[16];

	switch (((UserData*)Save::GetData())->Diffculty)
	{
	case 0:
		swprintf_s(Diff, L"EASY");
		break;

	case 1:
		swprintf_s(Diff, L"NORMAL");
		break;
		
	case 2:
		swprintf_s(Diff, L"HARD");
		break;
	}


	swprintf_s(str1, L"��Փx:%s",Diff);
	Font::StrDraw(str1, 32, 64, 64, c);


}

//MenuBlockDraw�֐�
