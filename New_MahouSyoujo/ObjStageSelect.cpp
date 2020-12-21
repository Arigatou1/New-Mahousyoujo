//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "UtilityModule.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjStageSelect::Init()
{
	m_key_flag = false;//�L�[�t���O
	cursor_x = 140;
	cursor_y = 64;
	 
	PageID = ((UserData*)Save::GetData())->Stage / 4;
	if (PageID >= 2)
		PageID = 0;
	MaxPage = 1;

	((UserData*)Save::GetData())->ManaHP = 0;
	((UserData*)Save::GetData())->HeroHP = 0;

	((UserData*)Save::GetData())->enemyRemain = 1;
	nowLoading=false;
	menuAllButtonX = 0.0f;
	waitTime = 0;
}

//�A�N�V����
void CObjStageSelect::Action()
{
	//�X�e�[�W�I�����
	//������J�[�\���̏ꏊ����ʒu���擾���A
	//�X�e�[�WID���v�Z���ݒ肷��ɂ́H�H

	if(cursor_y<512)
		((UserData*)Save::GetData())->Stage = ((cursor_y - 32) / 112) +(PageID*4);

	//cursor_y = 16,96,176,256,336,416,496
	//�J�[�\���̏����ʒu��16�Ȃ̂ŁA
	//96����16�������A80���o���A80�Ŋ��邱�Ƃ�1���o�Ă���B
	//�����1�𑫂��B

	//------------------------------------------------
	//�L�[����
	if (!nowLoading)
	{

		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Audio::Start(9);

				if (((UserData*)Save::GetData())->Clear_Flag[((UserData*)Save::GetData())->Stage] == true)
				{
					nowLoading = true;
				}
				if (cursor_y >= 512)
				{
					this->SetStatus(false);
					//���j���[�I�u�W�F�N�g�쐬
					CObjCustomize* obj = new CObjCustomize();
					Objs::InsertObj(obj, OBJ_CUSTOMIZE, 2);
				}
				m_key_flag = false;
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

				if (PageID > 0)
					PageID -= 1;
				m_key_flag = false;
			}
		}

		else if (Input::GetVKey(VK_RIGHT) == true)
		{


			if (m_key_flag == true)
			{
				Audio::Start(10);

				if (PageID < MaxPage)
					PageID += 1;

				m_key_flag = false;

			}



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
	
	//----------------------------------------------
	//�J�[�\���ʒu����
	if (cursor_y < 512)
	{
		cursor_x = 140;
	}
	else//�J�X�^�}�C�Y�ɍ��킹��ꂽ�Ƃ�
	{
		cursor_x = 20;
	}

}

//�h���[
void CObjStageSelect::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

		//�X�e�[�W�Z���N�g
		for (int i = 0; i < 4; i++)
		{
			MenuBlockDraw(140+ menuAllButtonX, i * 112.0f + 64.0f, 512.0f, 96.0f, 1.0f, 0.0f, 0.0f, 1.0f);

		}

		MenuBlockDraw(20 + menuAllButtonX, 512.0f, 512.0f, 96.0f, 1.0f, 0.2f, 1.0f, 1.0f);

		//�J�[�\���`��
		MenuBlockDraw(cursor_x + menuAllButtonX, cursor_y, 512.0f, 96.0f, 1.0f, 0.8f, 0.0f, 1.0f);

		//���{�^��
		for (int i = 0; i < 2; i++)
			MenuBlockDraw(16 + i * 674.0f + menuAllButtonX, 200.0f, 96.0f, 200.0f, 0.0f, 0.0f, 1.0f, 1.0f);


		Font::StrDraw(L"��", 40 + menuAllButtonX, 284, 48, c);
		Font::StrDraw(L"��", 712 + menuAllButtonX, 284, 48, c);



		for (int i = 0; i < 4; i++)
		{
			wchar_t str[128];
			swprintf_s(str, L"�X�e�[�W%d", i + 1 + (PageID * 4));

			Font::StrDraw(str, 196 + menuAllButtonX, 64 + (i * 112) + 8, 80, c);
		}

		

		Font::StrDraw(L"�J�X�^�}�C�Y", 36 + menuAllButtonX, 512, 80, c);
		
		MenuBlockDraw(-32, 0.0f, 864.0f, 56.0f, 0.1f, 0.6f, 0.1f, 0.7f);
		if (cursor_y < 512)
		{

			//���̂Ƃ��̃X�R�A�\��
			wchar_t Score[16];
			swprintf_s(Score, L"�n�C�X�R�A:%d", ((UserData*)Save::GetData())->ScoreData[((UserData*)Save::GetData())->Stage]);
			Font::StrDraw(Score, 2 + menuAllButtonX, 2, 48, c);
		}

			//�V�ׂ邩�V�ׂȂ����̕\��
			if(cursor_y==512)
				Font::StrDraw(L"����̕ύX�Ȃǂ��s�����Ƃ��ł��܂��B", 360, 2, 24, c);
			else if (((UserData*)Save::GetData())->Clear_Flag[((UserData*)Save::GetData())->Stage] == true)
				Font::StrDraw(L"���̃X�e�[�W�͗V�Ԃ��Ƃ��ł��܂��B", 400, 2, 24, c);
			else
				Font::StrDraw(L"���̃X�e�[�W�͂܂��V�ׂ܂���B", 400, 2, 24, c);


			

			MenuBlockDraw(0, 560.0f, 800.0f, 48.0f, 0.1f, 0.1f, 0.1f, 0.7f);

			Font::StrDraw(L"�����L�[:�ړ�  Enter:����  Esc:�߂�", 200, 566, 26, c);
		

}


void CObjStageSelect::cursorUp()
{
	if (m_key_flag == true)
	{
		//�����Đ�����
		Audio::Start(10);
		//�J�[�\���ړ�
		cursor_y -= 112;

		m_key_flag = false;
	}

	//�J�[�\������ʂ��s���Ȃ�����(��)
	if (cursor_y < 64)
		cursor_y = 512;

}

void CObjStageSelect::cursorDown()
{

	if (m_key_flag == true)
	{
		//�����Đ�����
		Audio::Start(10);
		//�J�[�\���ړ�
		cursor_y += 112;

		m_key_flag = false;
	}

	//�J�[�\���̈ړ�����
	if (cursor_y > 512)
		cursor_y = 64;

}