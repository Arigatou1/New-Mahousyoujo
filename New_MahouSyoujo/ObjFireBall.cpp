//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjFireBall.h"
#include "GameL\UserData.h"
#include "UtilityModule.h"

//�g�p����l�[���x�[�X
using namespace GameL;

//�R���X�g���N�^
CObjFireBall::CObjFireBall(float x, float y, float vx, float vy)
{
	m_ex = x;
	m_ey = y;
	m_vx = vx;
	m_vy = vy;
}
//�C�j�V�����C�Y
void CObjFireBall::Init()
{

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_xsize = 64.0f;
	e1_ysize = 64.0f;

	e1_t = true;

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_FIREBALL, 10);

	m_vx = -14.0f;
	m_vy = 20.0f;

	hitGround = false;
	hitTime = 100.0f;
}

//�A�N�V����
void CObjFireBall::Action()
{


	m_ex += m_vx;
	m_ey += m_vy;

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);




	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);



	if (e1_hit_down == true)
	{
		hitGround = true;
	}

	if (hitGround == true)
	{
		hitTime -= 1.0f;
		m_vx = -14.0f;
		m_vy = -2.0f;
	}
	//hitTime��0��
	if (hitTime <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vx, &m_vy);
}

//�h���[
void CObjFireBall::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,hitTime / 100.0f};

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 256.0f;
	src.m_right = 320.0f;
	src.m_bottom = 256.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 64.0f;
	dst.m_bottom = m_ey + 64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
