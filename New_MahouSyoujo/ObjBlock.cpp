#include"GameL/DrawTexture.h"
#include"GameL/WinInputs.h"
#include"GameL/SceneManager.h"
#include"GameL/SceneObjManager.h"

#include"GameHead.h"
#include"ObjBlock.h"

using namespace GameL;

CObjBlock::CObjBlock(int map[10][13])
{
	//�}�b�v�f�[�^���R�s�[
	memcpy(m_map, map, sizeof(int) * (10 * 13));
}
//�C�j�V�����C�Y
void CObjBlock::Init()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			//��̒�����6��T��
			if (m_map[i][j]==6)
			{
				CObjMana* obj_mana = new CObjMana(j * 64.0f, i * 64.0f);
				Objs::InsertObj(obj_mana, OBJ_MANA, 55);
			}

		}

	}
}

void CObjBlock::Action()
{
	//��l���̈ʒu����
	CObjHero* hero = (CObjHero*)Objs::GetObj(OBJ_HERO);
	float hx = hero->GetX();
	float hy = hero->GetY();
}
//�h���[
void CObjBlock::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	
	RECT_F src;
	RECT_F dst;
		
	

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0)
			{
				//�\���ʒu�̐ݒ�
				dst.m_top = i * 64.0f;
				dst.m_left = j * 64.0f;
				dst.m_right = dst.m_left + 64.0f;
				dst.m_bottom = dst.m_top + 64.0f;

				//�u���b�N2
				if (m_map[i][j] == 2)
				{
					BlockDraw(64.0f, 256.0f, &dst, c);
				}
				//�u���b�N3
				else if (m_map[i][j] == 3)
				{
					BlockDraw(128.0f, 256.0f, &dst, c);
				}
				//�u���b�N4
				else if (m_map[i][j] == 4)
				{
					BlockDraw(192.0f, 256.0f, &dst, c);
				}
				//�u���b�N5
				else if (m_map[i][j] == 5)
				{
					BlockDraw(256.0f, 256.0f, &dst, c);
				}
				//�u���b�N6
				else if (m_map[i][j] == 6)
				{
					;//�}�i�z�u�p�ԍ�
				}
				//�u���b�N1
				else
				{
					BlockDraw(0.0f, 256.0f, &dst, c);
				}
			}
		}
	}
}

//BlockDrawMethod�֐�
//����1 float x :���\�[�X�؂���ʒuX
//����2 float y :���\�[�X�؂���ʒuY
//����3 RECT_F* dst �`��ʒu
//����4 float c[]�J���[���
//�u���b�N��64*64����`��p�@���\�[�X�؂���ʒu�̂�xy�Őݒ肷��
void CObjBlock::BlockDraw(float x, float y, RECT_F* dst, float c[])
{
	RECT_F src;
	src.m_top = y;
	src.m_left = x;
	src.m_right = src.m_left + 64.0f;
	src.m_bottom = src.m_top + 64.0f;
	//�`��
	Draw::Draw(0, &src, dst, c, 0.0f);
}

//BlockHit�֐�
//����1 float* x     :������s��object��x�ʒu�@�@�@�@�@�@�@�@�@�@�@
//����2 float* y     :������s��object��y�ʒu�@�@
//����3 bool* up     :�㉺���E����̏㕔���ɓ������Ă��邩�ǂ�����Ԃ�
//����4 boll* down   :�㉺���E����̉������ɓ������Ă��邩�ǂ�����Ԃ�
//����5 bool* left   :�㉺���E����̍������ɓ������Ă��邩�ǂ�����Ԃ�
//����6 bool* right  :�㉺���E����̉E�����ɓ������Ă��邩�ǂ�����Ԃ�
//����7 float* vx    :���E���莞�̔����ɂ��ړ������E�͂̒l��ς��ĕԂ�
//����8 float* vy    :�㉺���񎦂ɂ�鎩�R�����^���̈ړ������E�͂̒l�ς��ĕԂ�
//����9 int* bt      :���������莞�A����ȃu���b�N�̃^�C�v��Ԃ�
//������s��object�ƃu���b�N64�~64����ŁA�����蔻��Ə㉺������s��
//���̌��ʂ͈���4�`10�ɕԂ�
void CObjBlock::BlockHit(float* x, float* y,
	bool* up, bool* down, bool* left, bool* right,
	float* vx, float* vy)
{
	//�G�Փˏ�Ԋm�F�p�t���O�̏�����
	*up = false;
	*down = false;
	*left = false;
	*right = false;

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 6)
			{
				//�v�f�ԍ������W�ɕύX
				float bx = j * 64.0f;
				float by = i * 64.0f;

				//��l���̃u���b�N�̓����蔻��
				if ((*x + 64 > bx) && (*x < bx + 64) && (*y + 64 > by) && (*y < by + 64))
				{
					//�㉺���E����

					//vector�̍쐬
					float rvx = *x - bx;
					float rvy = *y - by;

					//���������߂�
					float len = sqrt( rvx * rvx + rvy * rvy );

					//�p�x�����߂�
					float r = atan2(rvy, rvx);
					r = r * 180.0f / 3.14f;

					if (r <= 0.0f)
						r = abs(r);
					else
						r = 360.0f - abs(r);

					if (len < 88.0f)
					{
						//�p�x�ŏ㉺���E����
						if ((r < 45 && r>0) || r > 315)
						{
							//�E
							*right = true;//��l���̍������Փ�
							*x     = bx +64;//�u���b�N�̈ʒu-��l���̕�
							*vx    = -(*vx) * 0.1f;//-VX*�����W��
						}
						if (r > 45 && r < 135)
						{
							//��
							*down = true;//�I�u�W�F�N�g���猩�āA���̕������Փ˂��Ă���
							*y    = by - 64;//�u���b�N�̈ʒu-��l���̕�
							*vy   = 0.0f;
						}
						if (r > 135 && r < 225)
						{
							//��
							*left = true;//�I�u�W�F�N�g�̑����Փ�
							*x    = bx -64;//�u���b�N�̈ʒu-��l���̕�
							*vx   = -(*vx) * 0.1f;//-VX*�����W��
						}
						if (r > 225 && r < 315)
						{
							//��
							*up = true;//�I�u�W�F�N�g�̉������Փ�
							*y = by + 64;//�u���b�N�̈ʒu-��l���̕�

							if (*vy < 0)
							{
								*vy = 0.0f;
							}
						}
					}
				}
			}
		}
	}
}

//���ϊ֐�
//����1,2 float ax, ay :A�x�N�g��
//����3,4 float bx ,by :B�x�N�g��
//�߂�l�@ float :�ˉe
//���e�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float CObjBlock::Dot(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * bx + ay * by;

	return t;
}
//�O�ϊ֐�
//����1,2 float ax, ay :A�x�N�g��
//����3,4 float bx ,by :B�x�N�g��
//�߂�l�@ float :�ˉe
//���e�@A�x�N�g����B�x�N�g���œ��ς��s���ˉe�����߂�
float CObjBlock::Cross(float ax, float ay, float bx, float by)
{
	float t = 0.0f;

	t = ax * by - ay * bx;

	return t;
}

//���������߂�}�N��
#define SGN(x) 1 - (x <= 0) - (x < 0)

//���Ɛ��Ƃ̌�������
//���� float 1,2 a1x , a1y  :���x�N�g��A�̎n�_
//���� float 3,4 a2x , a2y  :���x�N�g��A�̏I�_
//���� float 5,6 b1x , b1y  :�x�N�g��B�̎n�_
//���� float 7,8 b2x , b2y  :�x�N�g��B�̏I�_
//�߂�l�@bool  :true = ��_�L��@false = ��_����
//���e�@:�@������A�EB�x�N�g���̌�_�������Aout_px��out_py�ɕԂ�
bool CObjBlock::LineCrossPoint(
	float a1x, float a1y, float a2x, float a2y,
	float b1x, float b1y, float b2x, float b2y,
	float* out_px, float* out_py)
{
	//�G���[�R�[�h
	*out_px = -99999.0f; *out_py = -99999.0f;

	//A�x�N�g���쐬(a2��a1)
	float ax = a2x - a1x; float ay = a2y - a1y;
	//B�x�N�g���쐬(b2��b1)
	float bx = b2x - b1x; float by = b2y - b1y;
	//C�x�N�g���쐬(b1��a1)
	float cx = b1x - a1x; float cy = b1y - a1y;
	//D�x�N�g���쐬(d2��a1)
	float dx = b2x - a1x; float dy = b2y - a1y;

	//A�~C�̎ˉe��A�~B�̎ˉe�����߂�
	float t1 = Cross(ax, ay, cx, cy);
	float t2 = Cross(ax, ay, dx, dy);

	//���������������ɂȂ��Ă��邩�ǂ������`�F�b�N
	if (SGN(t1) == SGN(t2))
		return false; //��_����
	
	//�ˉe���Βl��
	t1 = abs(t1); t2 = abs(t2);

	//��_�����߂�
	float px = bx * (t1 / (t1 + t2)) + b1x; 
	float py = by * (t1 / (t1 + t2)) + b1y;

	//AP�x�N�g��(p��a1)
	float apx = px - a1x; float apy = py - a1y;

	//BP�x�N�g��(p��a2)
	float bpx = px - a2x; float bpy = py - a2y;

	//A�EAP�̎ˉe��A�EBP�̎ˉe�����߂�
	float v1 = Dot(ax, ay, apx, apy);
	float v2 = Dot(bx, by, bpx, bpy);

	//�����`�F�b�N
	if (SGN(v1) == SGN(v2))
		return false; //��_���O

	//��_��Ԃ�
	*out_px = px; *out_py = py;

	return true;
}

//�I�u�W�F�N�g�ƕǂ̌�������֐�
//����1,2 float x,y  :��l���̈ʒu
//����3,4 float vx,vy  :��l���̈ړ��x�N�g��
//����5,6 float* out_px , out_py  :Block�Ƃ̌�_
//��l���̈ʒu+�ړ��x�N�g���Ɗe�u���b�N�̕ӂŌ���������s��
//�ł��߂���_�̈ʒu�Ƌ�����Ԃ�
bool CObjBlock::BlockCrossPoint(
	float x, float y, float vx, float vy,
	float* out_px, float* out_py, float* out_len)
{
	bool pb = false; //��_�m�F�p
	float len = 99999.0f;//��_�Ƃ̋���
	//�u���b�N�̕Ӄx�N�g��
	float edgo[4][4] =
	{
		{  0,  0, 64,  0},//��
		{ 64,  0, 64, 64},//��
		{ 64, 64,  0, 64},//��
		{  0, 64,  0,  0},//����
	};

	//m_map�̑S�v�f�ɃA�N�Z�X
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			if (m_map[i][j] > 0 && m_map[i][j] != 4)
			{
				//�u���b�N��4�ӂ����_��T��
				for (int k = 0; k < 4; k++)
				{
					//��_��T��
					float px,py;
					bool b;
					float l = 0.0f;
					b = LineCrossPoint(
						x, y, x + vx, y + vy,
						j * 64, i * 64, j * 64 + edgo[k][0], i * 64 + edgo[k][1],
						&px, &py);
					
					//��_�`�F�b�N
					if (b == true)
					{
						//��_�Ƃ̋��������߂�
						l = sqrt((px - x) * (px - x) + (py - y) * (py - y));

						//��������_�̒��ōł��������Z�����m��T��
						if (len > l)
						{
							len = l;
							*out_px = px;
							*out_py = py;
							pb = true;
						}
					}
				}
			}
		}
	}
	*out_len = len;
	return pb;
}