//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBaseBoss.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjGaugeBaseBoss::Init()
{

}

//�A�N�V����
void CObjGaugeBaseBoss::Action()
{



}
//�h���[
void CObjGaugeBaseBoss::Draw()
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
	dst.m_top = 552.0f;
	dst.m_left = 480.0f;
	dst.m_right = dst.m_left+294.0f;
	dst.m_bottom = dst.m_top+24;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}