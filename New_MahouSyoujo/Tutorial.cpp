//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\UserData.h"
#include "GameHead.h"
#include "Tutorial.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CTutorial::CTutorial()
{
	
}


//�C�j�V�����C�Y
void CTutorial::Init()
{

	cond1 = false;
	cond2 = false;

	condreset = false;

	Order = 1;
}

//�A�N�V����
void CTutorial::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_skill = obj_magicalgirl->GetSkill();
	}

	if (Order == 1)//���E�ړ�
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
	else if (Order == 4)//�X�L���ύX
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
	else if (Order == 5)//�q�[��
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
	else if (Order == 6)//�o���A
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
	else if(Order == 7)//���e�I
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
}

//�h���[
void CTutorial::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	if (Order == 1)
	{
		swprintf_s(str, L"����1");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if(Order == 2)
	{
		swprintf_s(str, L"����2");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 3)
	{
		swprintf_s(str, L"����3");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 4)
	{
		swprintf_s(str, L"����4");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 5)
	{
		swprintf_s(str, L"����5");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 6)
	{
		swprintf_s(str, L"����6");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 7)
	{
		swprintf_s(str, L"����7");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
	else if (Order == 8)
	{
		swprintf_s(str, L"�I���");//�����𕶎���
		Font::StrDraw(str, 350, 336, 36, c);
	}
}