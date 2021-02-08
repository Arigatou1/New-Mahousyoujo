#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include <math.h>

//MenuBlockDraw�֐�
//�\���ʒudst�̒l���󂯎���āA�`�悾���ł���B
void MenuBlockDraw(float x, float y, float width, float height, float r, float g, float b, float a, int type)
{
	float c[4] = { r,g,b,a };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = type*64;
	src.m_right = src.m_left+ 64;
	src.m_bottom = 64;

	dst.m_top = y;
	dst.m_left = x;
	dst.m_right = dst.m_left + width;
	dst.m_bottom = dst.m_top + height;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}

bool UnitVec(float* vx, float* vy)
{
	//�x�N�g���̐��K�����s��
	float r = 0.0f;
	r = (*vx) * (*vx) + (*vy) * (*vy);
	r = sqrt(r);

	//�����O���ǂ������ׂ�
	if (r == 0.0f)
	{
		//0�Ȃ�v�Z���s
		return false;
	}
	else
	{
		//���K�����s���Avx��vy�̎Q�Ɛ�̒l��ύX
		(*vx) = 3.0f / r * (*vx);
		(*vy) = 3.0f / r * (*vy);
	}

	//�v�Z����
	return true;
}

//�̈�`�F�b�N
bool CheckWindow(float pos_x, float pos_y, float window_x, float window_y, float window_w, float window_h)
{
	if (pos_x < window_x)
	{
		return false;//�̈�O
	}
	if (pos_x > window_w)
	{
		return false;//�̈�O
	}
	if (pos_y < window_y)
	{
		return false;//�̈�O
	}
	if (pos_y > window_h)
	{
		return false;//�̈�O
	}

	return true;
}

//�Q�[�W�x�[�X��`��ł���悤�ɂ��܂��B
void DrawGaugeBase(float x, float y,int id)
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	switch (id)
	{
	case 1:

		//�؂���ʒu�̐ݒ�
		src.m_top = 48.0f;
		src.m_left = 26.0f;
		src.m_right = 320.0f;
		src.m_bottom = 72.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top =y;
		dst.m_left = x;
		dst.m_right = dst.m_left + 294.0f;
		dst.m_bottom = dst.m_top + 24;


		//�`��
		Draw::Draw(1, &src, &dst, c, 0.0f);
		break;
	}
}