//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/Audio.h"

#include "ObjDragon.h"
#include "GameL\UserData.h"


#include <stdlib.h>
#include <time.h>

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
	b_posture = 0;

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	a_time = 0;

	maxhp = 1800;
	e_hp = maxhp;

	//�S�̍U����񂾂��_���[�W�^����@�@�^���Ȃ���false   �^���遁true
	AllBullet_Hit = true;

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 256, 256, ELEMENT_ENEMY, OBJ_DRAGON, 10);



	//�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeBoss* obj_gboss = new CObjGaugeBoss(m_ex - 25, m_ey+272);
	Objs::InsertObj(obj_gboss, OBJ_GAUGEBOSS, 51);

	//�����_��
	unsigned int now = (unsigned int)time(0);

	srand(now);

	shootDownTime = 0;

	attack_now = false;

	lastAttack = 1;

	fireBressOn = false;
}

//�A�N�V����
void CObjDragon::Action()
{
	a_time++;

	rand(); rand(); rand();

	if (!attack_now)
	{
		
			if (a_time == 240)
			{
				do {
				AttackPattern = rand() % 4;
				a_time = 0;
				attack_now = true;
				} while (lastAttack == AttackPattern);//�Ō�̍U���ƍ��̍U�����ꏏ�ȏꍇ�A��蒼��
			}
		
			//�Ō�̃A�^�b�N�͍��̃A�^�b�N
		lastAttack = AttackPattern;

	}
	else if (attack_now)
	{
		if (AttackPattern == 1)
		{
			fireBressOn = true;
			if (a_time >= 200)
			{
				a_time = 0;
				attack_now = false;
				fireBressOn = false;
			}
		
		}
		else if (AttackPattern == 0)
		{
			if(a_time<=120)
			{

					m_ey -= 2;
				
			}
			else if (a_time <= 180)
			{
			
				m_ey += 1;

			}
			else if (a_time <= 240)
			{
				m_ey -= 1;
			}
			else if (a_time <= 300)
			{
				m_ey += 1;
			}
			else if (a_time <= 360)
			{
				m_ey -= 1;
			}
			else if (a_time <= 480)
			{
				m_ey += 2;
			}

			if (a_time >= 480)
			{
				a_time = 0;
				attack_now = false;
			}
		}
		else if (AttackPattern == 2)
		{
			if (a_time <= 120)
			{
				m_ey -=5;
			}

			else if (a_time == 240)
			{
				if (b_posture == 0)
				{
					b_posture = 1;
					m_ex = -32;
				}
				else if (b_posture == 1)
				{
					b_posture = 0;
					m_ex = 576;
				}


			}
			else if (a_time >=240&&a_time <= 360)
			{
				m_ey += 5;
			}


		
			if (a_time >= 360)
			{
				a_time = 0;
				attack_now = false;
			}
		}

		else if (AttackPattern == 3)
		{
			if (a_time <= 120)
			{
				m_ey -= 2;
			}
			else if (a_time <= 180)
			{
				m_ey += 1;
				fireBressOn = true;
			}
			else if (a_time <= 240)
			{
				m_ey -= 1;
			

			}
			else if (a_time <= 300)
			{
				m_ey += 1;
				
				
			}
			else if (a_time <= 360)
			{
				m_ey -= 1;
				
			}
			else if (a_time <= 480)
			{
				m_ey += 2;
			}

			if (a_time >= 480)
			{
				a_time = 0;
				attack_now = false;
				fireBressOn = false;
			}
		}
	}

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

	


	if (a_time >= 600)
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
	if (hit->CheckObjNameHit(OBJ_ALLBULLET) != nullptr && AllBullet_Hit == true)
	{
		CObjAllBullet* obj_all = (CObjAllBullet*)Objs::GetObj(OBJ_ALLBULLET);
		e_hp -= obj_all->GetZ_ATK();
		AllBullet_Hit = false;
	}
	else if (hit->CheckObjNameHit(OBJ_ALLBULLET) == nullptr)
		AllBullet_Hit = true;

	//hp��0�ɂȂ�Ə���
	if (e_hp <= 0)
	{
		((UserData*)Save::GetData())->enemyRemain = 0;

		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		return;

	}

	if (fireBressOn)
		FireBress();
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
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey;
	dst.m_left = m_ex+(256.0f*b_posture);
	dst.m_right = dst.m_left + 256.0f-(256.0f*b_posture*2);
	dst.m_bottom = dst.m_top + 256.0f;

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
void CObjDragon::FireBress()
{
	if (a_time % 10 == 0)
	{

		CObjFireBall* obj = new CObjFireBall(m_ex + (256.0f - 64.0f) * b_posture, m_ey + 50.0f, -3.5f + (b_posture * 7.0f), 5.0f);
		Objs::InsertObj(obj, OBJ_FIREBALL, 49);
	}
}
