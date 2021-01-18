//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjPauseMenu.h"
#include "GameL\WinInputs.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"
#include "GameL\DrawTexture.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjPauseMenu::Init()
{
	m_key_flag = false;//�L�[�t���O
	cursor_x = 40;
	cursor_y = 96;
	nowSelect = 0;
	cursor_sx = 320;
	cursor_sy = 256;
}

//�A�N�V����
void CObjPauseMenu::Action()
{
	
}

//�h���[
void CObjPauseMenu::Draw()
{
	//�`��J���[���
	float c[4] = { 0.0f,0.0f,0.0f,0.5f };

	RECT_F src;
	RECT_F dst;

	if (((UserData*)Save::GetData())->PauseMenu == true)
	{

		src.m_top = 0;
		src.m_left = 0;
		src.m_right = 64;
		src.m_bottom = 64;

		dst.m_top = 0;
		dst.m_left = 0;
		dst.m_right = 800;
		dst.m_bottom = 600;

		Draw::Draw(50, &src, &dst, c, 0.0f);


		for (int i = 0; i < 4; i++)
			c[i] = 1.0f;
		Font::StrDraw(L"PAUSE", 336, 268, 64, c);

		Font::StrDraw(L"[Esc]:���[�h�Z���N�g", 236, 368, 32, c);
		Font::StrDraw(L"[Enter]:�Q�[���ɖ߂�", 236, 468, 32, c);
	
	}
}

//MenuBlockDraw�֐�
