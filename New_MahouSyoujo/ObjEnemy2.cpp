//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjEnemy2.h"
#include "GameL/Audio.h"
#include "GameL\UserData.h"


//�g�p����l�[���x�[�X
using namespace GameL;


//�R���X�g���N�^
CObjEnemy2::CObjEnemy2(float x, float y)
{
	m_ex = x;
	m_ey = y;
}

//�C�j�V�����C�Y
void CObjEnemy2::Init()
{
	m_vx = 0.0f;
	m_vy = 0.0f;

	e2_hp = 18;
	e2_atk = 0.5;
	e2_damege = 0;
	e2_time = 0;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e2_hit_up = false;
	e2_hit_down = false;
	e2_hit_left = false;
	e2_hit_right = false;

	e2_t = true;
	e2_anime = 1;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 50, 50, ELEMENT_ENEMY, OBJ_ENEMY2, 10);
	//Amount = 0;

}

//�A�N�V����
void CObjEnemy2::Action()
{
	e2_time++;

	//�}�i�̈ʒu�Œ�~
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();
		if (e2_hit_down == true)
		{
			if (m_mx + 64.0f <= m_ex)
				m_vx = -1.5f;
			else if (m_mx - 64.0f >= m_ex)
				m_vx = 1.5f;
			else
			{
				m_vx = 0;
				e2_t = false;
			}
		}

		//�}�i�̎�O�ɒ�~���čU������Ԋu
				//120���ƂɍU������(�}�i���E��)
		if (m_mx <= m_ex && e2_t == false)
		{
			if (e2_time % 120 >= 0 && e2_time % 120 <= 5)
			{
				m_ex = m_ex - 5.0f;
				e2_anime = 3;
			}
			else
			{
				m_ex = m_mx + 66.0f;
				e2_anime = 1;
			}
		}
		//120���ƂɍU������(�}�i��荶��)
		else if (m_mx >= m_ex && e2_t == false)
		{
			if (e2_time % 120 >= 0 && e2_time % 120 <= 5)
			{
				m_ex = m_ex + 5.0f;
				e2_anime = 3;
			}
			else
			{
				m_ex = m_mx - 52.0f;
				e2_anime = 1;
			}
		}
	}

	//�W�����v
	if (e2_hit_right == true)
	{
		m_ex = m_ex - 5.0f;
		m_ey = m_ey - 60.0f;
	}
	else if (e2_hit_left == true)
	{
		m_ex = m_ex + 5.0f;
		m_ey = m_ey - 60.0f;
	}

	//�o���A�o�Ă鎞�����~�܂�
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex == b_mx - 48.0f || m_ex == b_mx + 160.0f)
		{
			m_vx = 0;
		}
	}

	//�d��
	m_vy += 9.8 / (16.0f);

	//m_vx�̑��x�ňړ�
	m_ex += m_vx;
	m_ey += m_vy;

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey + 14);

	
	

	CObjBlock* obj_block2 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block2->BlockHit(&m_ex, &m_ey,
		&e2_hit_up, &e2_hit_down, &e2_hit_left, &e2_hit_right,
		&m_vx, &m_vy);

	//���@�����̒e�ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e2_hp -= 3;
		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e2_damege = obj_homing->GetM_ATK();

	}

	//�S�̍U���̖��@�ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e2_hp -= 10;
		CObjAllBullet* obj_allb = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e2_damege = obj_allb->GetZ_ATK();
		//Amount++;
	}

	//���ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e2_hp -= obj_sword->GetAttackPower();
	}

	//�e(��l��)�ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		e2_hp -= 3;
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e2_hp -= obj_bullet->GetAttackPower();
	}


	//hp��0�ɂȂ�Ə���
	if (e2_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		
			//�����X�^�[���|���ꂽ���̌��ʉ�
			Audio::Start(2);
			((UserData*)Save::GetData())->enemyRemain -= 1;
	}
}


//�h���[
void CObjEnemy2::Draw()
{
	//�`��J���[���
	float c[4] = { 0.4f,1.0f,0.3f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 320.0f;
	src.m_left = e2_anime * 64.0f - 64.0f;
	src.m_right = e2_anime * 64.0f;
	src.m_bottom = 384.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey+14;
	dst.m_left = m_ex+50.0f;
	dst.m_right = m_ex + 0.0f;
	dst.m_bottom = m_ey + 64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}