//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "ObjDamegeDisplay.h"

//�R���X�g���N�^

CObjDamegeDisplay::CObjDamegeDisplay(float x, float y, int damage ,int color)
{
	Damege_x = x;
	Damege_y = y;
	m_Damege = damage;
	color_type = color;
}

//�C�j�V�����C�Y
void CObjDamegeDisplay::Init()
{
	d_time = 0;

	if (!((UserData*)Save::GetData())->DamageDraw)
		d_time = 30;
}

//�A�N�V����
void CObjDamegeDisplay::Action()
{
	

	if (d_time == 30)
		this->SetStatus(false);
	d_time++;
}

//�h���[
void CObjDamegeDisplay::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,(30.0f-d_time)/30.0f };

	if (color_type == 1)
	{
		c[1] = 0.0f;
		c[2] = 0.0f;
	}



	//�`��
	wchar_t str[128];
		swprintf_s(str, L"%.0lf", m_Damege);//�����𕶎���
		Font::StrDraw(str, Damege_x - 20.0f, Damege_y - d_time, 24, c);

}
