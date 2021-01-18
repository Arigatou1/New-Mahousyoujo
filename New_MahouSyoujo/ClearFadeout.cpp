//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "ClearFadeout.h"
#include "GameL\UserData.h"
#include "GameL\DrawFont.h"
#include "GameL/WinInputs.h"
#include "GameL/Audio.h"


//�g�p����l�[���x�[�X
using namespace GameL;

Fadeout::Fadeout(int speed,bool fadeIn)
{
	fadeSpeed = speed;
	pfadeIn = fadeIn;
}

//�C�j�V�����C�Y
void Fadeout::Init()
{

	if (pfadeIn)//�t�F�[�h�C��
		shootDownTime = 100;
	else//�t�F�[�h�A�E�g
		shootDownTime = 1;
}

//�A�N�V����
void Fadeout::Action()
{
	if (pfadeIn)
	{
		//�t�F�[�h�C��
		shootDownTime -= fadeSpeed;
	}
	else
	{
	
		//�t�F�[�h�A�E�g
		shootDownTime += fadeSpeed;
	}

	if (shootDownTime <= 0)
	{
		//�t�F�[�h�C���Ƃ��A0�ȉ��ɂȂ�ƍ폜
		this->SetStatus(false);
	}
}

//�h���[
void Fadeout::Draw()
{
	
		//�`��J���[���
		float c[4] = { 0.0f,0.0f,0.0f,shootDownTime / 100.0f };

		RECT_F src;//�`�挳�؂���ʒu
		RECT_F dst;//�`���\���ʒu

		//�؂���ʒu�̐ݒ�
		src.m_top = 0.0f;
		src.m_left = 0.0f;
		src.m_right = 64.0f;
		src.m_bottom = 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f;
		dst.m_left = 0.0f;
		dst.m_right = 800.0f;
		dst.m_bottom = 600.0f;

		//�`��
		Draw::Draw(50, &src, &dst, c, 0.0f);
	
}

