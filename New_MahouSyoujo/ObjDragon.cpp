//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjDragon.h"
#include "GameL\UserData.h"

//�g�p����l�[���x�[�X
using namespace GameL;

//�R���X�g���N�^
CObjDragon::CObjDragon(float x, float y)
{
	m_ex = x;
	m_ey = y;
}
//�C�j�V�����C�Y
void CObjDragon::Init()
{


	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	a_time = 0;

	maxhp = 1800;
	e_hp = maxhp;

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 256, 256, ELEMENT_ENEMY, OBJ_DRAGON, 10);



	//�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeBoss* obj_gboss = new CObjGaugeBoss();
	Objs::InsertObj(obj_gboss, OBJ_GAUGEBOSS, 51);

	shootDownTime = 0;
}

//�A�N�V����
void CObjDragon::Action()
{



	//time��500�ɂȂ����Ƃ��㏸����
	if (a_time >= 500 && a_time <= 600)
	{
		m_ey -= 2;
	}


//Y���W��100�ɂȂ�܂ŏ㏸����
	if (a_time >= 600 && a_time <= 650)
	{
		m_ey += 1;
	}
	if (a_time >= 650 && a_time <= 700)
	{
		m_ey -= 1;
	}
	if (a_time >= 700 && a_time <= 750)
	{
		m_ey += 1;
	}
	if (a_time >= 750 && a_time <= 800)
	{
		m_ey -= 1;
	}
	if (a_time >= 800 && a_time <= 900)
	{
		m_ey += 2;
	}


	//100�ɓ��B������A100->200->100�����΂炭�J��Ԃ�


	//�܂�������



	//�d��
	m_vy += 9.8 / (16.0f);


	CObjBlock* obj_block1 = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
	obj_block1->BlockHit(&m_ex, &m_ey,
		&e1_hit_up, &e1_hit_down, &e1_hit_left, &e1_hit_right,
		&m_vx, &m_vy);
	//


		//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);

	a_time++;
	if (a_time >= 600 && a_time<=800)
	{
		if (a_time % 10 == 0)
		{

			CObjFireBall* obj = new CObjFireBall(m_ex, m_ey + 50.0f, -15.0f, 4.0f);
			Objs::InsertObj(obj, OBJ_FIREBALL, 49);
		}
	}

	if (a_time >= 900)
	{
		a_time = 0;
	}


	if (hit->CheckObjNameHit(OBJ_SWORD) != nullptr)
	{
		CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
		e_hp -= obj_sword->GetAttackPower();
	}
	if (hit->CheckObjNameHit(OBJ_BULLET) != nullptr)
	{
		CObjBullet* obj_bullet = (CObjBullet*)Objs::GetObj(OBJ_BULLET);
		e_hp -= obj_bullet->GetAttackPower();
	}
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr)
	{
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_hp -= obj_all->GetZ_ATK();
	}

	//hp��0�ɂȂ�Ə���
	if (e_hp <= 0)
	{
		((UserData*)Save::GetData())->enemyRemain = 0;
		return;

	}
}

//�h���[
void CObjDragon::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = 128.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey-128;
	dst.m_left = m_ex-96;
	dst.m_right = dst.m_left + 512.0f;
	dst.m_bottom = dst.m_top + 512.0f;

	//�`��
	Draw::Draw(4, &src, &dst, c, 0.0f);
}

int CObjDragon::GetHP()
{
	return e_hp;
}

int CObjDragon::GetMAXHP()
{
	return maxhp;
}

