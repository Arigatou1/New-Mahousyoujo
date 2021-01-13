//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "Tutorial.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CTutorial::Init()
{
	Order = 1;
	cond1 = false;
	cond2 = false;
}

//�A�N�V����
void CTutorial::Action()
{
	switch (Order)
	{
	case 1:
		if (Input::GetVKey(VK_LEFT) == true)
			cond1 = true;
		if (Input::GetVKey(VK_RIGHT) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
			Order++;
		break;
	case 2:
		cond1 = false; cond2 = false;

		if (Input::GetVKey(' ') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 3:
		cond1 = false;

		if (Input::GetVKey('F') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 4:
		cond1 = false;

		if (Input::GetVKey(VK_UP) == true)
			cond1 = true;
		if (Input::GetVKey(VK_DOWN) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
			Order++;
		break;
	case 5:
		cond1 = false; cond2 = false;

		if (Input::GetVKey('D') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 6:
		cond1 = false;

		if (Input::GetVKey('D') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 7:
		cond1 = false;

		if (Input::GetVKey('D') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	default:
		break;
	}
}

//�h���[
void CTutorial::Draw()
{

}