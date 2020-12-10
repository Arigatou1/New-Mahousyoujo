//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjModeSelect.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjModeSelect::Init()
{
	m_key_flag = false;//�L�[�t���O
	cursor_x = 40;
	cursor_y = 96;
	nowSelect = 0;
	cursor_sx = 320;
	cursor_sy = 256;
	countStage = 0;

	Save::Seve();
}

//�A�N�V����
void CObjModeSelect::Action()
{
	//���[�h�I�����
	//������J�[�\���̏ꏊ����ʒu���擾���A
	//���[�h�ݒ肷��

	//nowSelect = ((cursor_x - 40) / 400) ;

	//cursor_x = 40,440
	//�J�[�\���̏����ʒu��40�Ȃ̂ŁA
	//440����40�������A400���o���A400�Ŋ��邱�Ƃ�1���o�Ă���B
	

	if (Input::GetVKey(VK_RETURN) == true)
	{
		if (m_key_flag == true)
		{
			Audio::Start(9);

			this->SetStatus(false);
			switch (nowSelect)
			{
			case 0:
			{
				//���j���[�I�u�W�F�N�g�쐬
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT, 2);

				break;
			}
			case 1:
			{
				//�G���h���X���j���[�I�u�W�F�N�g�쐬
				CObjMenuEndless* obj2 = new CObjMenuEndless();
				Objs::InsertObj(obj2, OBJ_STAGEENDLESS, 2);

				break;
			}
			case 2:
			{
				//���ݒ�
				CObjSetting* sett = new CObjSetting();
				Objs::InsertObj(sett, OBJ_SETTING, 2);

				break;
			}
			default:
			{
				//���j���[�I�u�W�F�N�g�쐬
				CObjStageSelect* obj = new CObjStageSelect();
				Objs::InsertObj(obj, OBJ_STAGESELECT,2);
				break;
			}
			}
			m_key_flag = false;
		}
	}
	else if (Input::GetVKey(VK_LEFT) == true)
	{
	
	
		if (m_key_flag == true)
		{

			Audio::Start(10);

			//�ǂ��ɂ��Ă��X�e�[�W�Z���N�g�ɃJ�[�\�������킹��B
			nowSelect=0;
			cursor_x = 40;
			cursor_y = 96;
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_RIGHT)==true)
	{
		
		if (m_key_flag == true)
		{
			Audio::Start(10);
			//�ǂ��ɂ��Ă��G���h���X���[�h�ɃJ�[�\�������킹��B
			nowSelect=1;
			cursor_x = 440;
			cursor_y = 96;
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_DOWN) == true)
	{
	
		if (m_key_flag == true)
		{

			Audio::Start(10);
			//�ǂ��ɂ��Ă��ݒ�ɃJ�[�\�������킹��B
			nowSelect = 2;
			cursor_x = 200;
			cursor_y = 450;
		}
		m_key_flag = false;
	}
	else if (Input::GetVKey(VK_UP) == true)
	{
	
		
		if (cursor_y >= 450)
		{
			if (m_key_flag == true)
			{
				Audio::Start(10);
				//���ɂ���Ƃ������X�e�[�W�Z���N�g�ɃJ�[�\�������킹��B
				nowSelect = 0;
				cursor_x = 40;
				cursor_y = 96;
			}
			m_key_flag = false;
		}
		
	}
	else if (Input::GetVKey(VK_ESCAPE) == true)
	{

			if (m_key_flag == true)
			{
				Audio::Start(11);
				Scene::SetScene(new CSceneTitle());
			}
			m_key_flag = false;


	}
	else
	{
		m_key_flag = true;
	}

	//�J�[�\������ʔ����s���Ȃ�����
	if (cursor_x > 440)
	{
		cursor_x = 40;
	}
	else if (cursor_x < 40)
	{
		cursor_x = 40;
	}

	if (cursor_x == 200 && cursor_y == 450)
	{
		cursor_sx = 400;
		cursor_sy = 72;
	}
	else
	{
		cursor_sx = 320;
		cursor_sy = 256;
	}
}

//�h���[
void CObjModeSelect::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�X�e�Z���E�G���h���{�^��
	for (int i = 0; i < 2; i++)
		MenuBlockDraw(40 + (i * 400), 96, 320, 256, 1, 0, 0, 1);


	//�ݒ�{�^��
	MenuBlockDraw(200, 450, 400, 72, 0.5f, 0, 1, 1);

	MenuBlockDraw(cursor_x, cursor_y, cursor_sx, cursor_sy, 1, 0.8, 0, 1);
	
	Font::StrDraw(L"�X�e�[�W�Z���N�g", 72, 200, 32, c);

	Font::StrDraw(L"�G���h���X���[�h", 472, 200, 32, c);

	Font::StrDraw(L"�ݒ�", 360, 460, 48, c);

	switch (nowSelect)
	{
	case 0:

		countStage = 0;
		//ClearFlag��0�͂��Ȃ炸true.
		//false������ȊO�ɂȂ�܂ő�����B
		for (int i = 0; ((UserData*)Save::GetData())->Clear_Flag[i] != false; i++)
		{
			countStage++;
		}


		wchar_t str[128];
		swprintf_s(str, L"���݂̃X�e�[�W���B��:%d", countStage - 1);
		Font::StrDraw(str, 2, 2, 32, c);
		
		break;
	
	case 1:
		wchar_t Score[16];

		//���̂Ƃ��̃X�R�A�\��
		swprintf_s(Score, L"�X�R�A:%d", ((UserData*)Save::GetData())->ScoreData[16]);
		Font::StrDraw(Score, 2, 2, 32, c);

		break;

	default:

		Font::StrDraw(L"�Q�[���Ɋւ���ݒ��ύX���܂��B", 2, 2, 32, c);
	
		break;

	}

	
}
