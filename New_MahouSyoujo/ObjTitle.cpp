//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjTitle.h"
#include "GameL\MultiThread.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjTitle::Init()
{

	//----------------------------------------------------------
	//�Z�[�u�f�[�^�֘A

	m_key_flag = false;//�L�[�t���O

	//static �O���[�o���ϐ��ł͂Ȃ����A���̂悤�ȋL������������
	static bool init_stage = false;
	if (!init_stage)
	{
		//�v���O��������񂾂����s����
		((UserData*)Save::GetData())->Stage = 1;
		

		for (int i = 0; i < 20; i++)
		{
			((UserData*)Save::GetData())->ScoreData[i] = 0;
			((UserData*)Save::GetData())->Clear_Flag[i] = false;
		
		}
		
		//�v���O��������񂾂����s����
		((UserData*)Save::GetData())->Diffculty = 1;
		((UserData*)Save::GetData())->DamageDraw = true;


		//--------------------------------------------------------

		//���[�h
		Save::Open();//���t�H���_[UserData����f�[�^�擾]

		//�|�[�Y��ԏ�����
		//���[�h�̌�ɏ��������Ă��邽�߁A�O��̏I�����Ƀ|�[�Y��ʂł�
		//�e�����󂯂Ȃ��B
		((UserData*)Save::GetData())->PauseMenu = false;
		((UserData*)Save::GetData())->enemyRemain = 1;


		init_stage = true;

	}

	if (init_stage)
	{
		Save::Seve();
	}

	//-------------------------------------------

	shootDownTime = 0;
	nowLoading = false;
}

//�A�N�V����
void CObjTitle::Action()
{
	//----------------------------
	//�Z�[�u�f�[�^�֘A
	//�G���^�[�L�[�������ăV�[��:�Q�[��Menu�Ɉڍs����
	//�L�[����
	if (!nowLoading)
	{
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Audio::Start(9);
				nowLoading = true;
				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}





		//----------------------------------
		//�f�o�b�O�p�̋@�\

		//�f�o�b�O�p �Z�[�u�f�[�^�폜
		if (Input::GetVKey('3') == true)
		{
			if (m_key_flag == true)
			{
				for (int i = 0; i < 20; i++)
				{
					((UserData*)Save::GetData())->ScoreData[i] = 0;
					((UserData*)Save::GetData())->Clear_Flag[i] = false;

				}

				((UserData*)Save::GetData())->Diffculty = 1;
				((UserData*)Save::GetData())->DamageDraw = true;

				Save::Seve();

				m_key_flag = false;
			}
		}
		//�f�o�b�O�p�@�S�X�e�[�W�J��
		else if (Input::GetVKey('4') == true)
		{
			if (m_key_flag == true)
			{
				for (int i = 0; i < 20; i++)
					((UserData*)Save::GetData())->Clear_Flag[i] = true;

				Save::Seve();

				m_key_flag = false;
			}
		}
		else
		{
			m_key_flag = true;
		}
	}

	//----------------------------------------------------
	//���j���[�s��
	else if (nowLoading)
	{
		shootDownTime++;

		if (shootDownTime == 1)
		{
			Fadeout* obj_Fadeout = new Fadeout(2);
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}

		else if (shootDownTime == 50)
		{
			Scene::SetScene(new CSceneMenu());
		}



	}

	//-----------------------------------------------
	//0�͐�΂�true�ɂ���
	((UserData*)Save::GetData())->Clear_Flag[0] = true;
	//-----------------------------------------------

	




}

//�h���[
void CObjTitle::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top =  0.0f;
	src.m_left =  0.0f;
	src.m_right = 900.0f;
	src.m_bottom = 600.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f ;
	dst.m_left =0.0f;
	dst.m_right =900.0f;
	dst.m_bottom = 600.0f ;
	
	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
	


	if (Input::GetVKey('3') == true)
	{
		Font::StrDraw(L"�Z�[�u�f�[�^���폜���܂���", 0, 0, 32, c);
	}
	else if (Input::GetVKey('4') == true)
	{
		Font::StrDraw(L"�S�X�e�[�W�J�����܂����B", 0, 0, 32, c);
	}
}