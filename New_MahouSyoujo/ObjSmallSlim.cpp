//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjSmallSlim.h"
#include "GameL\UserData.h"
#include "GameL\Audio.h"


//�g�p����l�[���x�[�X
using namespace GameL;

//�R���X�g���N�^
CObjSmallSlim::CObjSmallSlim(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
//�C�j�V�����C�Y
void CObjSmallSlim::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;
	
	e_hp = 1;

	//e_jkn = 100;
	e_time = 0;
	e_mtk = false;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_xsize = 32;
	//����ȏ㉺����ƃu���b�N�Ɉ���������..?

	e1_ysize = 32+12;

	e_damege = 0;

	ss_t = true;
	ss_anime = 1;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 24, 16, ELEMENT_ENEMY, OBJ_SMALLSLIM, 10);

	m_posture = 0;

}

//�A�N�V����
void CObjSmallSlim::Action()
{
	//�G4�̎���
	e_time++;

	//�}�i�̈ʒu�Œ�~
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();

		if (m_mx + 50.0f <= m_ex)
			m_posture = 1;
		else if (m_mx - 52.0f >= m_ex)
			m_posture = 0;

		if (m_mx + 50.0f <= m_ex)
			m_vx = -2.0f;
		else if (m_mx - 52.0f >= m_ex)
			m_vx = 2.0f;
		else
		{
			if (e_time % 120 >= 100 || e_time % 120 <= 20)
				ss_anime = 3;
			else
				ss_anime = 1;
			m_vx = 0;
			ss_t = false;
		}

		//�}�i�̎�O�ɒ�~���čU������Ԋu
				//120���ƂɍU������(�}�i���E��)
		if (m_mx <= m_ex && ss_t == false)
		{
			if (e_time % 120 == 0)
				m_ex = m_ex - 5.0f;
			else
				m_ex = m_mx + 50.0f;
		}
		//120���ƂɍU������(�}�i��荶��)
		else if (m_mx >= m_ex && ss_t == false)
		{
			if (e_time % 120 == 0)
				m_ex = m_ex + 5.0f;
			else
				m_ex = m_mx - 52.0f;
		}

		//�W�����v
		if (e1_hit_right == true)
		{
			m_vx = -1.0f;
			m_vy = -8.0f;
		}
		else if (e1_hit_left == true)
		{
			m_vx = +1.0f;
			m_vy = -8.0f;
		}

		//�o���A�o�Ă鎞�����~�܂�
		CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
		if (obj_barrier != nullptr)
		{
			b_mx = obj_barrier->GetBX();

			if (m_ex >= b_mx - 48.0f && m_ex <= b_mx)
			{
				m_vx = 0;
				m_ex = b_mx - 48.0f;
			}
			else if (m_ex <= b_mx + 112.0f && m_ex >= b_mx)
			{
				m_vx = 0;
				m_ex = b_mx + 112.0f;
			}

		}
	}

	//m_vx�̑��x�ňړ�
	m_ex += m_vx;
	m_ey += m_vy;

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex + 16.0f, m_ey +47.0f);

	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);

	//�d��
	m_vy += 9.8 / (16.0f);


	//�e��������Ώ���
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{

		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_hp -= obj_all->GetZ_ATK();

		//Amount++;
	}

	//���ɓ�����Ό��炷
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e_hp -= obj_sword->GetAttackPower();
	}

	//�e�ɓ������HP���炷
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e_hp -= obj_bullet->GetAttackPower();
	}


	//HP�O�ɂȂ����Ƃ�
	if (e_hp <= 0)
	{
		Audio::Start(2);

		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		((UserData*)Save::GetData())->enemyRemain -= 1;
	}
}

//�h���[
void CObjSmallSlim::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 320.0f;
	src.m_left = ss_anime * 64.0f - 64.0f;
	src.m_right = ss_anime * 64.0f;
	src.m_bottom = 384.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top    = m_ey + 32.0f;
	dst.m_left   = m_ex + 16.0f + (m_posture * 32.0f);
	dst.m_right  = m_ex + 48.0f - (m_posture * 32.0f);
	dst.m_bottom = m_ey + 64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

