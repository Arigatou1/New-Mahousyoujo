//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"


#include "GameHead.h"
#include "ObjGaugeBoss.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\UserData.h"
#include "UtilityModule.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjGaugeBoss::CObjGaugeBoss(float x,float y)
{
	pos_x = x;
	pos_y = y;
}
//�C�j�V�����C�Y
void CObjGaugeBoss::Init()
{
	HP = 0;
	MAXHP = 0;
	GaugePercent = 0;
	GaugePosTweak();
}

//�A�N�V����
void CObjGaugeBoss::Action()
{
	if (((UserData*)Save::GetData())->Stage + 1 == 4 || ((UserData*)Save::GetData())->Stage + 1 == 17)
	{
		CObjBoss1* obj = (CObjBoss1*)Objs::GetObj(OBJ_BOSS1);

		if (obj != nullptr)
		{


			HP = obj->GetHP();
			MAXHP = obj->GetMAXHP();

			//MAXHP��100%�Ƃ���

			GaugePercent = (HP / MAXHP) * 292;

		}
	}
	else if (((UserData*)Save::GetData())->Stage + 1 == 8)
	{
		CObjDragon* obj = (CObjDragon*)Objs::GetObj(OBJ_DRAGON);

		if (obj != nullptr)
		{


			HP = obj->GetHP();
			MAXHP = obj->GetMAXHP();

			//MAXHP��100%�Ƃ���

			GaugePercent = (HP / MAXHP) * 292;

		}
	}
	
	if (GaugePercent <= 0.0f)
	{
		this->SetStatus(false);
	}


}
//�h���[
void CObjGaugeBoss::Draw()
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
		dst.m_top =pos_y;
		dst.m_left = pos_x;
		dst.m_right = dst.m_left + 294.0f;
		dst.m_bottom = dst.m_top + 24;


		//�`��
		Draw::Draw(1, &src, &dst, c, 0.0f);

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	//0%�ʒu
	src.m_left = 27.0f;
	//100%�ʒu
	src.m_right = GaugePercent + 27.0f;
	src.m_bottom = 216.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = pos_y;
	dst.m_left = pos_x;
	dst.m_right = dst.m_left+ GaugePercent;
	dst.m_bottom = dst.m_top+24.0f;

	//�`��
	Draw::Draw(1, &src, &dst, c, 0.0f);

}

//�e�N�X�`����294 �E�B���h�E�T�C�Y800
//�Q�[�W�ʒu�����p�֐��B
//��ʂ���͂ݏo�����Ȃ��ƋC�Ɏg���B
void CObjGaugeBoss::GaugePosTweak()
{
	if (pos_x < 294)
	{
		pos_x = 294;
	}
	else if (pos_x > 800-294)
	{
		pos_x = 800 - 294;
	}
}