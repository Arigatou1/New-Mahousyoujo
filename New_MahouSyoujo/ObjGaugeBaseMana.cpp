//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBaseMana.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjGaugeMANABase::CObjGaugeMANABase(float x, float y)
{
	if (x < 113.0f)
		x = 113.0f;
	if (x > 687.0f)
		x = 687.0f;


	gb_x = x;
	gb_y = y;

}


//�C�j�V�����C�Y
void CObjGaugeMANABase::Init()
{
	
}

//�A�N�V����
void CObjGaugeMANABase::Action()
{



}
//�h���[
void CObjGaugeMANABase::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top = 48.0f;
	src.m_left = 26.0f;
	src.m_right = 320.0f;
	src.m_bottom = 72.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = gb_y+96.0f;
	dst.m_left = gb_x-113.0f;
	dst.m_right = dst.m_left + 294;
	dst.m_bottom = gb_y+120.0f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}