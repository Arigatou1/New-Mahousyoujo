//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "ClearFadeout.h"
#include "GameL\UserData.h"
#include "GameL\DrawFont.h"
#include "GameL/WinInputs.h"


//�g�p����l�[���x�[�X
using namespace GameL;


//�C�j�V�����C�Y
void Fadeout::Init()
{
	shootDownTime = 0;
}

//�A�N�V����
void Fadeout::Action()
{
	//�c��G�̐���0�ɂȂ����Ƃ�
	if (((UserData*)Save::GetData())->enemyRemain == 0)
	{

		shootDownTime++;

		if (shootDownTime >= 400)
			Scene::SetScene(new CSceneGameClear());
	}
}

//�h���[
void Fadeout::Draw()
{
	if (shootDownTime >= 300)
	{
		//�`��J���[���
		float c[4] = { 0.0f,0.0f,0.0f,(shootDownTime - 300) / 100.0f };

		RECT_F src;//�`�挳�؂���ʒu
		RECT_F dst;//�`���\���ʒu

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 192.0f;
		src.m_right = 192 + 64.0f;
		src.m_bottom = 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//�`��
		Draw::Draw(0, &src, &dst, c, 0.0f);
	}
}