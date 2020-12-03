//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjDamegeDisplay.h"

//�C�j�V�����C�Y
void CObjDamegeDisplay::Init()
{
	CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
	Sword_ATK = obj_sword->GetAttackPower();
	d_time = 0;
}

//�A�N�V����
void CObjDamegeDisplay::Action()
{
	d_time++;

	if (d_time == 60)
		this->SetStatus(false);

}
//�h���[
void CObjDamegeDisplay::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };

	//�`��
	wchar_t str[128];
	swprintf_s(str, L"%.0lf", Sword_ATK);//�����𕶎���
	Font::StrDraw(str, 0, 500, 24, c);
}
