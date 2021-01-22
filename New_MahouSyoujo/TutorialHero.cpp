//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\DrawFont.h"

#include "GameHead.h"
#include "TutorialHero.h"
#include "ObjSword.h"
#include "GameL\UserData.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

TutorialHero::~TutorialHero()
{

}

//�C�j�V�����C�Y
void TutorialHero::Init()
{
	m_px = 200;
	m_py = 200;
	m_vx = 0;
	m_vy = 0;
	m_posture = 1;
	m_anime = 0;
	m_anitime = 0;
	atk_anime = 0;
	atk_anitime = 0;
	atk_time = 0;

	m_time = 0;
	m_num = 100;
	
	m_f = true;
	isJump = true;
	//�ő�HP
	max_hp = 20.0f;
	m_hp = max_hp;
	//���G���Ԓ����p
	mtk_max = 130 - ((UserData*)Save::GetData())->Diffculty * 30;
	mtk_jkn = mtk_max;
	m_mtk = false;

	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_px + 8, m_py + 8, 56, 56, ELEMENT_PLAYER, OBJ_HERO, 1);

	Weapon = ((UserData*)Save::GetData())->weapon;
	damage = ((UserData*)Save::GetData())->Diffculty * 0.5;
	AllDamage = 0;

	shootDownTime = 0;

	clear_check = false;

}

//�A�N�V����
void TutorialHero::Action()
{

	CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
	if (obj_tutorial != nullptr)
	{
		m_order = obj_tutorial->GetOrder();
	}

	m_time++;
	if (m_time >= m_num)
		m_time = 0;
	//-------------------------------------
	//�L�[����

	if (!clear_check)
	{
		if (m_order == 1)
		{
			m_num = 320;
			//�E�Ɉړ�
			if (m_time <= 80 && m_time >= 0)
			{
				m_vx += 0.1f;
				m_posture = 1;

				m_anitime += 1;
			}
			else if (m_time <= 240 && m_time >= 160)//���Ɉړ�
			{
				m_vx -= 0.1f;
				m_posture = -1;

				m_anitime += 1;
			}
			else
			{
				//�ǂ���������Ă��Ȃ��ꍇ�͌���������B
				m_anime = 1;
				m_anitime = 0;
				m_vx = m_vx * 0.9;
			}
		}
		else if (m_order == 2)
		{
			m_num = 180;
			m_vx = m_vx * 0.9;

			m_posture = 1;
			m_anime = 1;

			if(m_time >=88 && m_time <=92)
			m_py -= 20.0f;
		}
		else if (m_order == 3)//�U���p
		{
			if (m_time == 50)
				Weapon = 1;
			else if (m_time == 100)
				Weapon = 2;
			else
			{
				Weapon = 0;
				atk_anime = 0;
			}

			if (Weapon == 1)
			{
				atk_anime = 2;

				CObjBullet* obj_bullet = new CObjBullet(m_px + (m_posture * 48), m_py, m_posture, false);
				Objs::InsertObj(obj_bullet, OBJ_BULLET, 51);
			}
			else if(Weapon == 2)
			{
				atk_anime = 1;

				CObjSword* obj_b = new CObjSword(m_px + (m_posture * 48.0f), m_py, m_posture, false);
				Objs::InsertObj(obj_b, OBJ_SWORD, 51);
			}
		}

		
		//��
		if (Input::GetVKey('D') == true)
		{
			CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
			if (obj_magicalgirl != nullptr)
			{
				m_hp = obj_magicalgirl->GetHP();
			}
		}

	}
	//�L�[����
	//--------------------------------------------------

	//�������̃A�j���[�V���� anitime��10�ɂȂ����Ƃ��A�R�}��1�i�߂�
	if (m_anitime >= 8)
	{
		m_anime++;

		m_anitime = 0;
	}

	if (m_anime >= 4)
		m_anime = 0;


	//---------------------------------------

	//��ʊO�ɍs���Ȃ��悤��
	if (m_px > 600)
	{
		m_px = 600;
		m_vx = 0;
	}
	else if (m_px < 200)
	{
		m_px = 200;
		m_vx = 0;
	}
	if (m_py > 400)
	{
		m_py = 400;
		m_vy = 0;
	}
	else if (m_py < 200)
	{
		m_py = 200;
		m_vy = 0;
	}

	//���G���Ԃ������ɂȂ����� �G�Ƃ̂����蔻����s��
	if (m_mtk == false)
	{
		//HitBox�̓��e�����ɖ߂�
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_px + 4.0f, m_py + 4.0f);

		if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
		{
			//�_���[�W
			m_mtk = true;
			m_hp -= 1.0f + damage;//�G�̍U����
			AllDamage += 1.0f + damage;
			m_vx = 0.0f;
		}
	}
	//���G��true�ɂȂ�����
	else if (m_mtk == true)
	{
		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(m_px + 9999, m_py);
		//���G���Ԃ����炷
		mtk_jkn -= 1;

		if (mtk_jkn <= 0)//���G���Ԃ�0�ɂȂ����Ƃ�
		{
			m_mtk = false;
			mtk_jkn = mtk_max;
		}

	}

	//--------------------------
	//�ŏI�I�ȑ��x

	//�ō����x����
	if (m_vx >= 6)
		m_vx = 6;
	if (m_vx <= -6)
		m_vx = -6;

	//���R�����^��
	m_vy += 9.8 / (16.0f);

	//�x�N�g��������W�ɕϊ�
	m_px += m_vx;
	m_py += m_vy;

	//----------------------------
}
//�h���[
void TutorialHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,mtk_jkn % 3 };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	if (!clear_check)
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = (atk_anime * 64) + 0.0f;
		src.m_left = (AniData[m_anime] * 64) + 0.0f;
		src.m_right = (AniData[m_anime] * 64) + 64.0f;
		src.m_bottom = (atk_anime * 64) + 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = (32.0f * m_posture) + m_px + 32.0f;
		dst.m_right = (-32.0f * m_posture) + m_px + 32.0f;
		dst.m_bottom = 64.0f + m_py;

		//�`��
		Draw::Draw(3, &src, &dst, c, 0.0f);
	}
	else
	{
		//�؂���ʒu�̐ݒ�
		src.m_top = 192.0f;
		src.m_left = 128.0f;
		src.m_right = src.m_left + 64.0f;
		src.m_bottom = src.m_top + 64.0f;
		//�\���ʒu�̐ݒ�
		dst.m_top = 0.0f + m_py;
		dst.m_left = m_px + 0.0f;
		dst.m_right = dst.m_left + 64.0f;
		dst.m_bottom = 64.0f + dst.m_top;

		//�`��
		Draw::Draw(3, &src, &dst, c, 0.0f);
	}


}