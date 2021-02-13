//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "Tutorial.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CTutorial::Init()
{

	cond1 = false;
	cond2 = false;

	condreset = false;

	Order = 1;

	//�`���[�g���A��l���I�u�W�F�N�g�쐬
	TutorialHero* obj = new TutorialHero();
	Objs::InsertObj(obj, OBJ_TUTORIALHERO, 60);

	shootDownTime = 0;
}

//�A�N�V����
void CTutorial::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_skill = obj_magicalgirl->GetSkill();
	}

	if      (Order == 1)//���E�ړ�
	{
		
		if (Input::GetVKey(VK_LEFT) == true)
			cond1 = true;
		if (Input::GetVKey(VK_RIGHT) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 2)//�W�����v
	{
		if (condreset == true)
		{
			cond1 = false; cond2 = false;
			condreset = false;
		}

		if (Input::GetVKey(' ') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 3)//�U��
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
		}

		if (Input::GetVKey('F') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 4)
	{
		TutorialHero* obj_tutorialhero = (TutorialHero*)Objs::GetObj(OBJ_TUTORIALHERO);
		if (obj_tutorialhero != nullptr)
		{
			Time = obj_tutorialhero->GetTime();
		}

		if (Time >= 400)
			Order++;
	}
	else if (Order == 5)//�X�L���ύX
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey(VK_UP) == true)
			cond1 = true;
		if (Input::GetVKey(VK_DOWN) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 6)//�q�[��
	{
		if (condreset == true)
		{
			cond1 = false; cond2 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 1)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 7)//�o���A
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 2)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 8)//���e�I
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 3)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 9)
	{
		((UserData*)Save::GetData())->tutorialDone = true;
		Save::Seve();
		//HP���[���ɂȂ�����A�ҋ@���Ԃ𑝉�������B
		shootDownTime++;

		if (shootDownTime == 1)
		{
		
			Audio::Start(13);
		
		}
		else if (shootDownTime == 200)
		{
			//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout();
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}
		else if (shootDownTime == 300)
		{
			Scene::SetScene(new CSceneMenu());
		}
	}
}

//�h���[
void CTutorial::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,0.9f };

	RECT_F src;
	RECT_F dst;
	src.m_top    =   0;
	src.m_left   = 192;
	src.m_right  = 256;
	src.m_bottom =  64;

	dst.m_top    = 100;
	dst.m_left   = 100;
	dst.m_right  = 700;
	dst.m_bottom = 430;

	Draw::Draw(0, &src, &dst, c, 0.0f);


	wchar_t str[128];

	for (int i = 0; i < 4; i++)
	{
		c[i] = 1.0f;
	}

	if (Order == 1)
	{
		swprintf_s(str, L"�`���[�g���A���ւ悤����!!");//�����𕶎���
		Font::StrDraw(str, 140, 160, 40, c);
		swprintf_s(str, L"�܂��́u���v�E�u���v�L�[�ō��E�Ɉړ����Ă݂܂��傤");//�����𕶎���
		Font::StrDraw(str, 145, 270, 20, c);
	}
	else if(Order == 2)
	{
		swprintf_s(str, L"���Ɂu�X�y�[�X�v�L�[�ŃW�����v�ł��܂�");//�����𕶎���
		Font::StrDraw(str, 120, 200, 30, c);
		swprintf_s(str, L"�X�e�[�W�̒i���╂���Ă���G�ɗL���ł�");//�����𕶎���
		Font::StrDraw(str, 120, 240, 30, c);
	}
	else if (Order == 3)
	{
		swprintf_s(str, L"�����āuF�v�L�[�ōU�����܂�");//�����𕶎���
		Font::StrDraw(str, 120, 200, 30, c);
		swprintf_s(str, L"���܂��ԍ���������ēG��|���܂��傤");//�����𕶎���
		Font::StrDraw(str, 120, 240, 30, c);
	}
	else if (Order == 4)
	{
		swprintf_s(str, L"��l����}�i�͓G�ɓ���������");//�����𕶎���
		Font::StrDraw(str, 120, 200, 30, c);
		swprintf_s(str, L"�U�����󂯂�ƃ_���[�W���󂯂܂�");//�����𕶎���
		Font::StrDraw(str, 120, 240, 30, c);
	}
	else if (Order == 5)
	{
		swprintf_s(str, L"�E��̖��@��");//�����𕶎���
		Font::StrDraw(str, 130, 140, 30, c);
		swprintf_s(str, L"�u���v�E�u���v�L�[�ŕύX���ł��܂�");//�����𕶎���
		Font::StrDraw(str, 130, 180, 30, c);
		swprintf_s(str, L"�g���������@�ɉ��F�̘g�����킹�悤");//�����𕶎���
		Font::StrDraw(str, 130, 250, 30, c);
	}
	else if (Order == 6)
	{
		//swprintf_s(str, L"�ł͖��@���g�p���Ă݂܂��傤");//�����𕶎���
		//Font::StrDraw(str, 150, 140, 20, c);
		//swprintf_s(str, L"���@�́u���v�E�u���v�L�[�ŕύX���ł��܂�");//�����𕶎���
		//Font::StrDraw(str, 150, 180, 20, c);
		swprintf_s(str, L"�܂��͈�ԏ�̃q�[��");//�����𕶎���
		Font::StrDraw(str, 150, 140, 30, c);
		swprintf_s(str, L"��l���̗̑͂�3�񕜂��܂�");//�����𕶎���
		Font::StrDraw(str, 170, 220, 30, c);
		swprintf_s(str, L"�E��̉��F�̘g�����킹�悤");//�����𕶎���
		Font::StrDraw(str, 300, 330, 25, c);
		swprintf_s(str, L"���@�́uD�v�L�[�Ŏg�p���܂�");//�����𕶎���
		Font::StrDraw(str, 400, 400, 20, c);
	}
	else if (Order == 7)
	{
		//swprintf_s(str, L"���@�́u���v�E�u���v�L�[�ŕύX���ł��܂�");//�����𕶎���
		//Font::StrDraw(str, 150, 140, 20, c);
		//swprintf_s(str, L"�uD�v�L�[�Ŗ��@���g�p���܂�");//�����𕶎���
		//Font::StrDraw(str, 150, 180, 20, c);
		swprintf_s(str, L"���ɐ^�񒆂̃o���A");//�����𕶎���
		Font::StrDraw(str, 150, 140, 30, c);
		swprintf_s(str, L"�}�i�̎���ɃV�[���h��");//�����𕶎���
		Font::StrDraw(str, 170, 200, 30, c); 
			swprintf_s(str, L"�W�J���ēG�̍U����h���܂�");//�����𕶎���
		Font::StrDraw(str, 170, 240, 30, c); 
		swprintf_s(str, L"�E��̉��F�̘g�����킹�悤");//�����𕶎���
		Font::StrDraw(str, 300, 330, 25, c);
		swprintf_s(str, L"���@�́uD�v�L�[�Ŏg�p���܂�");//�����𕶎���
		Font::StrDraw(str, 400, 400, 20, c);
	}
	else if (Order == 8)
	{
		//swprintf_s(str, L"���@�́u���v�E�u���v�L�[�ŕύX���ł��܂�");//�����𕶎���
		//Font::StrDraw(str, 150, 140, 20, c);
		//swprintf_s(str, L"�uD�v�L�[�Ŗ��@���g�p���܂�");//�����𕶎���
		//Font::StrDraw(str, 150, 180, 20, c);
		swprintf_s(str, L"�Ō�͈�ԉ��̃��e�I");//�����𕶎���
		Font::StrDraw(str, 150, 140, 30, c);
		swprintf_s(str, L"��ʑS�̂ɖ�����覐΂ōU�����܂�");//�����𕶎���
		Font::StrDraw(str, 170, 220, 30, c);
		swprintf_s(str, L"�E��̉��F�̘g�����킹�悤");//�����𕶎���
		Font::StrDraw(str, 300, 330, 25, c);
		swprintf_s(str, L"���@�́uD�v�L�[�Ŏg�p���܂�");//�����𕶎���
		Font::StrDraw(str, 400, 400, 20, c);
	}
	else if (Order == 9)
	{
		swprintf_s(str, L"����Ń`���[�g���A���͏I���ł�");//�����𕶎���
		Font::StrDraw(str, 160, 240, 30, c);
	}
}

void CTutorial::SkillIconsDraw(int id)
{
	RECT_F src;
	RECT_F dst;
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//�؂���ʒu�̐ݒ�
	src.m_top = (id*128.0f);
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = src.m_top+128.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top = 100.0f;
	dst.m_left = 100.0f;
	dst.m_right = dst.m_left + 96.0f;
	dst.m_bottom = dst.m_top + 96.0f;

	//�`��
	Draw::Draw(10, &src, &dst, c, 0.0f);
}