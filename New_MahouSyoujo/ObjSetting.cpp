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
	moveCursor = 112;
	//�`���[�g���A���p
	nowLoading = false;
	menuAllButtonX = 0.0f;
	waitTime = 0;
}

//�A�N�V����
void CObjSetting::Action()
{

	//�J�[�\���̈ʒu����nowSelect���擾����B
	nowSelect = (cursor_y - 64) / 112;
	if (!nowLoading)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				if (nowSelect == 3)
				{
					nowLoading = true;
					((UserData*)Save::GetData())->Stage = -1;
				}
				else
				{
					Audio::Start(9);

					Save::Seve();

					this->SetStatus(false);
					//���j���[�I�u�W�F�N�g�쐬
					CObjModeSelect* obj = new CObjModeSelect();
					Objs::InsertObj(obj, OBJ_MODESELECT, 2);
				}
			}
		}
		else if (Input::GetVKey(VK_UP) == true)
		{
			cursorUp();
		}
		else if (Input::GetVKey(VK_DOWN) == true)
		{
			cursorDown();
		}
		else if (Input::GetVKey(VK_LEFT) == true)
		{
			if (m_key_flag == true)
			{
				Audio::Start(10);

				switch (nowSelect)
				{
				case 0:
					if (((UserData*)Save::GetData())->Diffculty > 0)
					{
						((UserData*)Save::GetData())->Diffculty--;
					}
					break;

				case 1:
					if (((UserData*)Save::GetData())->DamageDraw)
					{
						((UserData*)Save::GetData())->DamageDraw = false;
					}
					else
					{
						((UserData*)Save::GetData())->DamageDraw = true;
					}
					break;
				default:
					break;
				}
				m_key_flag = false;
			}
			if (nowSelect == 2)
			{

				if (((UserData*)Save::GetData())->masterVolume > 0)
				{
					((UserData*)Save::GetData())->masterVolume -= 1;
					Audio::VolumeMaster(-0.01f);
				}


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
					if (((UserData*)Save::GetData())->Diffculty < 2)
						((UserData*)Save::GetData())->Diffculty++;
					break;

				case 1:
					if (((UserData*)Save::GetData())->DamageDraw)
						((UserData*)Save::GetData())->DamageDraw = false;
					else
						((UserData*)Save::GetData())->DamageDraw = true;
					break;

				case 2:


					break;
				default:

					break;
				}


				m_key_flag = false;
			}
			if (nowSelect == 2)
			{
				if (((UserData*)Save::GetData())->masterVolume < 200)
				{
					((UserData*)Save::GetData())->masterVolume += 1;
					Audio::VolumeMaster(0.01f);
				}
			}
		}
		else
			m_key_flag = true;

	}

	else if(nowLoading)
	{

		waitTime++;

		if (waitTime == 30)
		{
			//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout(8);
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}
		else if (waitTime > 30)
		{
			menuAllButtonX += 16;
	
			if (menuAllButtonX > 800)
			{
				Scene::SetScene(new CSceneMain());

			}
		}

	}
	
}

//�h���[
void CObjSetting::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu
	


	Font::StrDraw(L"GAME Setting", 2, 2, 32, c);

	for (int i = 0; i < 4; i++)
	{
		MenuBlockDraw(32 + menuAllButtonX, 64.0f+i*112.0f , 728.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);
	}

	MenuBlockDraw(cursor_x + menuAllButtonX, cursor_y, 728.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);

	wchar_t str1[128];
	wchar_t Diff[16];
	wchar_t OnOff[4];

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
	switch (((UserData*)Save::GetData())->DamageDraw)
	{
	case true:
		swprintf_s(OnOff, L"ON");
		break;
	case false:
		swprintf_s(OnOff, L"OFF");
		break;

	}
	
	for (int i = 0; i < 4; i++)
	{
		switch (i)
		{
		case 0:
			swprintf_s(str1, L"��Փx:%s", Diff);
			break;
		case 1:
			swprintf_s(str1, L"�_���[�W���l�̕\�L:%s", OnOff);
			break;
		case 2:
			swprintf_s(str1, L"����:%d%%", ((UserData*)Save::GetData())->masterVolume);
			break;
		case 3:
			swprintf_s(str1, L"�`���[�g���A��");
			break;
		}

		Font::StrDraw(str1, 48 + menuAllButtonX, 80 + 112*i, 64, c);
	}
	MenuBlockDraw(0, 560.0f, 800.0f, 48.0f, 0.1f, 0.1f, 0.1f, 0.7f);

	Font::StrDraw(L"�����L�[:�ړ�  �����L�[:�l�̕ύX�@Enter:����  ", 200, 566, 26, c);

}

void CObjSetting::cursorUp()
{
	if (m_key_flag == true)
	{
		//�����Đ�����
		Audio::Start(10);
		//�J�[�\���ړ�
		cursor_y -= moveCursor;

		m_key_flag = false;
	}
	
	//�J�[�\������ʂ��s���Ȃ�����(��)
	if (cursor_y < 64)
		cursor_y = 64;

}

void CObjSetting::cursorDown()
{
	//�������̍ۂɁA���ݑ��݂���{�^���̐�������B
	//���̐��Ԃ�J�[�\���ړ�����B
	int count=4;
	
	if (m_key_flag == true)
	{
		//�����Đ�����
		Audio::Start(10);
		//�J�[�\���ړ�
		cursor_y += moveCursor;

		m_key_flag = false;
	}

	//�J�[�\���̈ړ�����
	if (cursor_y > 64+((count-1)* moveCursor))
		cursor_y = 64;

}