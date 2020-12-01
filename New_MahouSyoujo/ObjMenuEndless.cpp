//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"
#include "ObjMenuEndless.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjMenuEndless::Init()
{
	m_key_flag = false;//�L�[�t���O
	
	nowLoading = false;

	cursor_x = 140.0f;
	cursor_y = 64.0f;
	cursor_sy = 384.0f;

	((UserData*)Save::GetData())->Stage = 16;
}

//�A�N�V����
void CObjMenuEndless::Action()
{

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
		//	if (((UserData*)Save::GetData())->Clear_Flag[7] == true)
		//	{

				if (cursor_y < 512)
				{
					Scene::SetScene(new CSceneMain());

					nowLoading = true;
				}
				if (cursor_y >= 512)
				{
					this->SetStatus(false);
					//���j���[�I�u�W�F�N�g�쐬
					CObjCustomize* obj = new CObjCustomize();
					Objs::InsertObj(obj, OBJ_CUSTOMIZE, 0);
				}
		//	}
			
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_UP) == true)
	{

		if (m_key_flag == true)
		{
			cursor_y = 64;
			cursor_sy = 384.0f;
			
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{

		if (m_key_flag == true)
		{
			cursor_y = 512;
			cursor_sy = 96.0f;
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_ESCAPE) == true)
	{

		if (m_key_flag == true)
		{
			this->SetStatus(false);
			//���j���[�I�u�W�F�N�g�쐬
			CObjModeSelect* obj = new CObjModeSelect();
			Objs::InsertObj(obj, OBJ_MODESELECT, 0);
		}
		m_key_flag = false;
	}
	else
	{
		m_key_flag = true;
	}




}

//�h���[
void CObjMenuEndless::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	if (nowLoading == false)
	{
			MenuBlockDraw(140,  64.0f, 512.0f, 384.0f, 1.0f, 0.0f, 0.0f, 1.0f);


		MenuBlockDraw(140, 512.0f, 512.0f, 96.0f, 1.0f, 0.2f, 1.0f, 1.0f);
		//if()

		MenuBlockDraw(cursor_x, cursor_y, 512.0f, cursor_sy, 1.0f, 0.8f, 0.0f, 1.0f);


	
		Font::StrDraw(L"�J�X�^�}�C�Y", 156, 512, 80, c);
	
		Font::StrDraw(L"�G���h���X���[�h", 156, 220, 56, c);

		wchar_t Score[16];

		//���̂Ƃ��̃X�R�A�\��
		swprintf_s(Score, L"�X�R�A:%d", ((UserData*)Save::GetData())->ScoreData[16]);
		Font::StrDraw(Score, 2, 2, 48, c);
	}
	else
	{

		Font::StrDraw(L"Now Loading...", 60, 256, 96, c);


	}



}

