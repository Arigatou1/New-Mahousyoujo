//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjDamegeDisplay.h"

//�R���X�g���N�^
CObjDamegeDisplay::CObjDamegeDisplay(float x, float y, int posture)
{
	Damege_x = x;
	Damege_y = y;
	Sword_posture = posture;
}

//�C�j�V�����C�Y
void CObjDamegeDisplay::Init()
{
	CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
	if (obj_sword != nullptr)
	{
		Sword_ATK = obj_sword->GetAttackPower();
		appear_type = 0;
	}

	Mana_Damege = 0.0f;

	d_time = 0;
}

//�A�N�V����
void CObjDamegeDisplay::Action()
{
	d_time++;

	if (d_time == 30)
		this->SetStatus(false);

}

//�h���[
void CObjDamegeDisplay::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };
	float d[4] = { 1.0f,1.0f,1.0f,1.0f };

	//�`��
	wchar_t str[128];
	if (appear_type == 0)
	{
		swprintf_s(str, L"%.0lf", Sword_ATK);//�����𕶎���
		if (Sword_posture == -1)
		{
			Font::StrDraw(str, Damege_x - 20.0f, Damege_y, 24, c);
		}
		else if (Sword_posture == 1)
		{
			Font::StrDraw(str, Damege_x + 84.0f, Damege_y, 24, c);
		}
	}
	else if (appear_type == 1)
	{
		swprintf_s(str, L"%.0lf", Mana_Damege);//�����𕶎���
		Font::StrDraw(str, Damege_x + 0.0f, Damege_y, 24, d);
	}
}
