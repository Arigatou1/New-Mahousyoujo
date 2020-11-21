//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeHP.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;


//�C�j�V�����C�Y
void CObjGaugeHP::Init()
{
	
}

//�A�N�V����
void CObjGaugeHP::Action()
{
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		

		HP = obj->GetHP();
		MAXHP = obj->GetMAXHP();

		//MAXHP��100%�Ƃ���

		GaugePercent = (HP / MAXHP) * 250;

	}



}
//�h���[
void CObjGaugeHP::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	wchar_t str[128];
	swprintf_s(str, L"%.0lf/%.0lf", HP,MAXHP);//�����𕶎���
	Font::StrDraw(str, 330, 2, 24, c);

	//�؂���ʒu�̐ݒ�
	src.m_top = 72.0f;
	//0%�ʒu
	src.m_left = 69.0f;
	//100%�ʒu
	src.m_right = GaugePercent+69.0f;
	src.m_bottom = 96.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	//0%�ʒu
	dst.m_left = 69.0f;
	//100%�ʒu
	dst.m_right = GaugePercent+69.0f;
	dst.m_bottom = 24.0f;


	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

//int CObjGaugeHP::GetPercent()
//{
//	return GaugePercent;
//}