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
	//��l��HP
	CObjHero* obj = (CObjHero*)Objs::GetObj(OBJ_HERO);
	if (obj != nullptr)
	{
		HP = obj->GetHP();
		MAXHP = obj->GetMAXHP();

		/// <summary>
		/// �Ⴆ�΁AHP��100��MaxHP��100�Ƃ���B
		/// HP��maxHP�Ŋ����1�͏o�Ă���̂ŁA����Ƀe�N�X�`���T�C�Y�������Ă�B
		/// HP�������̎���,0.5���o�Ă���̂ŁA�����̃e�N�X�`�������\������Ȃ��B
		/// </summary>
		GaugePercent[0] = (HP / MAXHP) * 250;

	}

	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		//��Ɠ����B
		MP = obj_magicalgirl->GetMP();
		MaxMP = obj_magicalgirl->GetMaxMP();

		GaugePercent[1] = (MP / MaxMP) * 250;

	}

}
//�h���[
void CObjGaugeHP::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//--------------�Q�[�W�̓y��̕`��B----------------------
	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 320.0f;
	src.m_bottom = 48.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 320.0f;
	dst.m_bottom = 48.0f;
	Draw::Draw(1, &src, &dst, c, 0.0f);
	//--------------------------------------------------------

	wchar_t str[128];
	swprintf_s(str, L"%.0lf/%.0lf", HP,MAXHP);//�����𕶎���
	Font::StrDraw(str, 330, 2, 24, c);

	swprintf_s(str, L"%.0lf/%.0lf", MP, MaxMP);//�����𕶎���
	Font::StrDraw(str, 330, 26, 24, c);


	for (int i = 0; i < 2; i++)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 72.0f + 24.0f * i;
		//0%�ʒu
		src.m_left = 69.0f;
		//100%�ʒu
		src.m_right = GaugePercent[i] + 69.0f;
		src.m_bottom = src.m_top + 24.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + 24.0f * i;
		//0%�ʒu
		dst.m_left = 69.0f;
		//100%�ʒu
		dst.m_right = GaugePercent[i] + 69.0f;
		dst.m_bottom = dst.m_top + 24.0f;


		//�`��
		Draw::Draw(1, &src, &dst, c, 0.0f);

	}
}
