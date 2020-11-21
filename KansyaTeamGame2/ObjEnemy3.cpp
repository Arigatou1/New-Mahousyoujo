//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL\UserData.h"

#include"ObjEnemy3.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjEnemy3::CObjEnemy3(float x,float y)
{
	m_ex = x;
	m_ey = y;
	
}

//�C�j�V�����C�Y
void CObjEnemy3::Init()
{

	m_vx = 1.0f;
	m_vy = 0.0f;
	e_hp = 5;
	e_damege = 0;

	e3_hit_up = false;
	e3_hit_down = false;
	e3_hit_left = false;
	e3_hit_right = false;

	jump = 0;

	e3_xsize = 64;
	e3_ysize = 64;
	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_ENEMY3, 1);

	e_hp = 6.0f;

}

//�A�N�V����
void CObjEnemy3::Action()
{
	//���C
	//m_vx += -(m_vx * 0.098);

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex , m_ey);
	
	m_ex += m_vx;
	m_ey += m_vy;

	CObjBlock* obj_block3 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block3->BlockHit(&m_ex, &m_ey,
		&e3_hit_up, &e3_hit_down, &e3_hit_left, &e3_hit_right,
		& m_vx, &m_vy);


	//�W�����v
	if (obj_block3 != nullptr)
	{
		
		
	}

	//���R�����^��
	m_ey += 9.8 / (16.0f);

	
	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if (obj != nullptr)
	{
		float m_mx = obj->GetX();

		if (m_mx <= m_ex)
			m_vx = -1.0f;
		else if (m_mx >= m_ex)
			m_vx = 1.0f;
		else
			m_vx = 0;
	}


	//�o���A�o�Ă鎞�����~�܂�
	CObjBarrier* obj_barrier = (CObjBarrier*)Objs::GetObj(OBJ_BARRIER);
	if (obj_barrier != nullptr)
	{
		b_mx = obj_barrier->GetBX();

		if (m_ex == b_mx - 48.0f)
		{
			m_vx = 0;
		}
		else if (m_ex == b_mx + 160.0f)
		{
			m_vx = 0;
		}

	}

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e_hp -= 1;
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_damege = obj_all->GetZ_ATK();

		e_hp <= 0;
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		//Amount++;
	}

	//�e�ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_HOMINGBULLET) != nullptr)
	{
		e_hp -= 1;
		CObjHomingBullet* obj_homing = (CObjHomingBullet*)Objs::GetObj(OBJ_HOMINGBULLET);
		e_damege = obj_homing->GetM_ATK();

		//Amount++;
	}

	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		e_hp -= 10;
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_damege = obj_all->GetZ_ATK();
	}

	//���ɓ�����Ώ���
	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e_hp -= obj_sword->GetAttackPower();
	}

	//hp��0�ɂȂ�Ə���
	if (e_hp <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
		((UserData*)Save::GetData())->enemyRemain -= 1;
		//Amount++;
	}

}

//�h���[
void CObjEnemy3::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 384.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 448.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top =m_ey;
	dst.m_left = m_ex;
	dst.m_right =  m_ex+64.0f;
	dst.m_bottom =  m_ey+64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}