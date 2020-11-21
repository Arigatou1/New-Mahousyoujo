//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeMana.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjGaugeMANAHP::CObjGaugeMANAHP(float x, float y)
{

	if (x < 113.0f)
		x = 113.0f;
	if (x > 687.0f)
		x = 687.0f;

	gb_x = x;
	gb_y = y;

}
//�C�j�V�����C�Y
void CObjGaugeMANAHP::Init()
{
	
}

//�A�N�V����
void CObjGaugeMANAHP::Action()
{
	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj_mana != nullptr)
	{


		HP = obj_mana->GetHP();
	

		//MAXHP��100%�Ƃ���

		GaugePercent = (HP / 100.0) * 292.0f;

	}

}
//�h���[
void CObjGaugeMANAHP::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	wchar_t str[128];
	swprintf_s(str, L"%.3lf", HP);//�����𕶎���
	Font::StrDraw(str, 2, 48, 24, c);

	//�؂���ʒu�̐ݒ�
	src.m_top = 144.0f;
	//0%�ʒu
	src.m_left = 27.0f;
	//100%�ʒu
	src.m_right = GaugePercent + src.m_left;
	src.m_bottom = 168.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = gb_y + 96.0f;
	//0%�ʒu
	dst.m_left =gb_x - 112.0f;
	//100%�ʒu
	dst.m_right = dst.m_left+GaugePercent;
	dst.m_bottom = gb_y + 120.0f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}


//int CObjGaugeMANAHP::GetPercent()
//{
//	if(0)
//	return GaugePercent;
//}
