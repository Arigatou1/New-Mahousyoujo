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
	menuAllButtonX = 0.0f;
	waitTime = 0;

	cursor_x = 140.0f;
	cursor_y = 64.0f;
	cursor_sy = 384.0f;

	((UserData*)Save::GetData())->Stage = 16;
}

//�A�N�V����
void CObjMenuEndless::Action()
{
	if (!nowLoading)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{

				Audio::Start(9);
				//	if (((UserData*)Save::GetData())->Clear_Flag[7] == true)
				//	{

				if (cursor_y < 470)
				{
					nowLoading = true;
				}
				if (cursor_y >= 470)
				{
					this->SetStatus(false);
					//���j���[�I�u�W�F�N�g�쐬
					CObjCustomize* obj = new CObjCustomize();
					Objs::InsertObj(obj, OBJ_CUSTOMIZE, 2);
				}
				//	}

				m_key_flag = false;
			}
		}
		else if (Input::GetVKey(VK_UP) == true)
		{
		


			if (m_key_flag == true)
			{
				Audio::Start(10);
				cursor_y = 64;
				cursor_sy = 384.0f;

			}
			m_key_flag = false;
		}
		else if (Input::GetVKey(VK_DOWN) == true)
		{
		


			if (m_key_flag == true)
			{
				Audio::Start(10);
				cursor_y = 470;
				cursor_sy = 96.0f;
			}
			m_key_flag = false;
		}
		else if (Input::GetVKey(VK_ESCAPE) == true)
		{

			if (m_key_flag == true)
			{
				Audio::Start(11);
				this->SetStatus(false);
				//���j���[�I�u�W�F�N�g�쐬
				CObjModeSelect* obj = new CObjModeSelect();
				Objs::InsertObj(obj, OBJ_MODESELECT, 2);
			}
			m_key_flag = false;
		}
		else
		{
			m_key_flag = true;
		}
	}

	else if (nowLoading == true)
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
void CObjMenuEndless::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	
			MenuBlockDraw(140 + menuAllButtonX,  64.0f, 512.0f, 384.0f, 1.0f, 0.0f, 0.0f, 1.0f);


		MenuBlockDraw(140 + menuAllButtonX, 470.0f, 512.0f, 96.0f, 1.0f, 0.2f, 1.0f, 1.0f);
		//if()

		MenuBlockDraw(cursor_x + menuAllButtonX, cursor_y, 512.0f, cursor_sy, 1.0f, 0.8f, 0.0f, 1.0f);


	
		Font::StrDraw(L"�J�X�^�}�C�Y", 175 + menuAllButtonX, 480, 70, c);
	
		Font::StrDraw(L"�G���h���X���[�h", 175 + menuAllButtonX, 220, 56, c);

		wchar_t Score[16];

		//���̂Ƃ��̃X�R�A�\��
		swprintf_s(Score, L"�n�C�X�R�A:%d", ((UserData*)Save::GetData())->ScoreData[16]);
		Font::StrDraw(Score, 2 + menuAllButtonX, 2, 48, c);
	


}

