//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameL\UserData.h"
#include "GameHead.h"
#include "Tutorial.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CTutorial::Init()
{
	
	//�O���f�[�^�̓ǂݍ���
	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	/*int size;
	int StageID = ((UserData*)Save::GetData())->Stage + 1;

	//�}�b�v�f�[�^��ǂݍ��ށB
	wchar_t s[128];

	if (StageID >= 9 && StageID != 17)
		swprintf_s(s, L"Stage/Stage8.csv", StageID);

	else
		swprintf_s(s, L"Stage/Stage%d.csv", StageID);

	p = Save::ExternalDataOpen(s, &size);//�O���f�[�^�ǂݍ���
	*/
	int map[10][13];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	Order = 1;
	cond1 = false;
	cond2 = false;

	condreset = false;
}

//�A�N�V����
void CTutorial::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_skill = obj_magicalgirl->GetSkill();
	}

	switch (Order)
	{
	case 1://���E�ړ�
		if (Input::GetVKey(VK_LEFT) == true)
			cond1 = true;
		if (Input::GetVKey(VK_RIGHT) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 2://�W�����v
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
		break;
	case 3://�U��
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('F') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 4://�X�L���ύX
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
		break;
	case 5://��
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
		break;
	case 6://�o���A
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
		break;
	case 7://���e�I
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
		break;
	default:
		break;
	}
}

//�h���[
void CTutorial::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	switch (Order)
	{
	case 1:
		swprintf_s(str, L"����1");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 2:
		swprintf_s(str, L"����2");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 3:
		swprintf_s(str, L"����3");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 4:
		swprintf_s(str, L"����4");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 5:
		swprintf_s(str, L"����5");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 6:
		swprintf_s(str, L"����6");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 7:
		swprintf_s(str, L"����7");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 8:
		swprintf_s(str, L"�I���");//�����𕶎���
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	}
	
}