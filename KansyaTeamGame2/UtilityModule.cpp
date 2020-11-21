#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameHead.h"
#include <math.h>
//MenuBlockDraw�֐�
//�\���ʒudst�̒l���󂯎���āA�`�悾���ł���B
void MenuBlockDraw(float x, float y, float width, float height, float r, float g, float b, float a)
{
	float c[4] = { r,g,b,a };
	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = 0;
	src.m_right = 64;
	src.m_bottom = 64;

	dst.m_top = y;
	dst.m_left = x;
	dst.m_right = dst.m_left + width;
	dst.m_bottom = dst.m_top + height;

	Draw::Draw(0, &src, &dst, c, 0.0f);

}
/*
//�u���b�N�����蔻��
bool Gravity(float *x ,float* y,float* b_x,float* b_y)
{
	//��l���̃u���b�N�̓����蔻��
	if ((*x + 64.0f > *b_x) && (*x < *b_x + 64.0f) && (*y + 64.0f > *b_y) && (*y < *b_y + 64.0f))
	{
		//vector�̍쐬
		float vx = *x - *b_x;
		float vy = *y - *b_y;

		//���������߂�
		float len = sqrt(vx * vx + vy * vy);

		//�p�x�����߂�
		float r = atan2(vy, vx);
		r = r * 180.0f / 3.14f;

		if (r <= 0.0f)
			r = abs(r);
		else
			r = 360.0f - abs(r);
	
		if (len < 88.0f)
		{
			//�p�x�ŏ㉺���E����
			if ((r < 40 && r>0) || r > 320)
			{
				//�E
				hero->SetX(*b_x + 64.0f);//�u���b�N�̈ʒu-��l���̕�
				hero->SetRight(true);//��l���̍������Փ�
				hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
			}
			if (r > 45 && r < 135)
			{
				//��
				hero->SetDown(true);//��l�����猩�āA���̕������Փ˂��Ă���
				hero->SetY(*b_y - 64.0f);//�u���b�N�̈ʒu-��l���̕�
				hero->SetVY(0.0f);
			}
			if (r > 140 && r < 220)
			{
				//��
				hero->SetX(*b_x - 64.0f);//�u���b�N�̈ʒu-��l���̕�
				hero->SetLeft(true);//��l���̍������Փ�
				hero->SetVX(-hero->GetVX() * 0.1f);//-VX*�����W��
			}
			if (r > 225 && r < 315)
			{
				//��
				hero->SetUp(true);
				hero->SetY(*b_y + 64.0f);//�u���b�N�̈ʒu-��l���̕�

				if (hero->GetVY() < 0)
				{
					hero->SetVY(0.0f);
				}
			}
		}
		
	}
}*/
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