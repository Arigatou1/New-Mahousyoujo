#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeMP.h"
#include "GameL\DrawFont.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGaugeMP::Init()
{
	
}

//�A�N�V����
void CObjGaugeMP::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{


		MP = obj_magicalgirl->GetMP();
		MaxMP = obj_magicalgirl->GetMaxMP();


		//MAXMP��100%�Ƃ���

		GaugePercent = (MP / MaxMP) * 250;

	}
}
//�h���[
void CObjGaugeMP::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	wchar_t str[128];
	swprintf_s(str, L"%.0lf", MP);//�����𕶎���
	Font::StrDraw(str, 330, 26, 24, c);

	//�؂���ʒu�̐ݒ�
	src.m_top = 96.0f;
	//0%�ʒu
	src.m_left = 69.0f;
	//100%�ʒu
	src.m_right = GaugePercent + 69.0f;
	src.m_bottom = 120.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = 24.0f;
	//0%�ʒu
	dst.m_left   = 69.0f;
	//100%�ʒu
	dst.m_right  = GaugePercent + 69.0f;
	dst.m_bottom = 48.0f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}