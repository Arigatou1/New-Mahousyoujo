//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "Objbarrier.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBarrier::CObjBarrier(float x, float y)
{
	mb_x = x;
	mb_y = y;
}

//�C�j�V�����C�Y
void CObjBarrier::Init()
{
	b_t = true;
}

//�A�N�V����
void CObjBarrier::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		b_skill = obj_magicalgirl->GetSkill();
		b_mp = obj_magicalgirl->GetMP();
		b_time = obj_magicalgirl->GetBTime();
	}

	if (b_mp >= 30)
	{
		if (Input::GetVKey('D') == true && b_t == true && b_skill == 2)
		{
			b_t = false;
		}
		else if (Input::GetVKey('D') == false && b_time > 300)
		{
			b_t = true;
		}
	}

	if (b_time >= 300)
	{
		this->SetStatus(false);
	}
}
//�h���[
void CObjBarrier::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top    = 256.0f;
	src.m_left   = 128.0f;
	src.m_right  = 192.0f;
	src.m_bottom = 320.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = mb_y - 384.0f;
	dst.m_left   = mb_x + 0.0f;
	dst.m_right  = mb_x + 32.0f;
	dst.m_bottom = mb_y + 224.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
float CObjBarrier::GetBX()
{
	return mb_x;
}