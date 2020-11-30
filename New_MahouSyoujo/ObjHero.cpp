//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"

#include "GameHead.h"
#include "ObjHero.h"
#include "ObjSword.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"


//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjHero::~CObjHero()
{

}

//�C�j�V�����C�Y
void CObjHero::Init()
{
	m_px = 0;
	m_py = 0;
	m_vx = 0;
	m_vy = 0;
	m_posture = 1;
	m_anime = 0;
	m_anitime = 0;
	atk_anime = 0;
	atk_anitime = 0;
	atk_time = 0;
	m_f = true;
	isJump = true;
	//�ő�HP
	max_hp = 20.0f;
	m_hp = max_hp;
	//���G���Ԓ����p
	mtk_max = 130-((UserData*)Save::GetData())->Diffculty * 30;
	mtk_jkn = mtk_max;
	m_mtk = false;
	
	//block�Ƃ̏Փˏ�Ԋm�F�p
	m_hit_up = false;
	m_hit_down = false;
	m_hit_left = false;
	m_hit_right = false;


	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, m_px+8, m_py+8, 56, 56, ELEMENT_PLAYER, OBJ_HERO, 1);

	Weapon = ((UserData*)Save::GetData())->weapon;
	damage = ((UserData*)Save::GetData())->Diffculty * 0.5;
	AllDamage = 0;
	((UserData*)Save::GetData())->HPZeroCheck = false;
}

//�A�N�V����
void CObjHero::Action()
{
	
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_mp = obj_magicalgirl->GetMP();
		m_Skill = obj_magicalgirl->GetSkill();
	}

		//Space�L�[�������ƃW�����v���鏈��
		if (Input::GetVKey(' ') == true && m_hit_down == true && isJump == true)
		{
			//jump
			Audio::Start(6);
			m_vy = -15;
			isJump = false;
		}
		else if (Input::GetVKey(' ') == false)
		{
			isJump = true;
		}

		//���R�����^��
		m_vy += 9.8 / (16.0f);

		CObjBlock* obj_block = (CObjBlock*)Objs::GetObj(OBJ_BLOCK);
		obj_block->BlockHit(&m_px, &m_py,
			&m_hit_up, &m_hit_down, &m_hit_left, &m_hit_right,
			&m_vx, &m_vy);

		//�L�[�������ƈړ�
		if (Input::GetVKey(VK_LEFT) == true)
		{
			m_vx -= 0.1;
			m_posture = -1;

			m_anitime += 1;

		}
		else if (Input::GetVKey(VK_RIGHT) == true)
		{
			m_vx += 0.1;
			m_posture = 1;

			m_anitime += 1;


		}
		//�ǂ���������Ă��Ȃ��ꍇ�͌���������B
		else
		{

			m_anime = 1;
			m_anitime = 0;
			m_vx = m_vx * 0.9;
		}

		//�������̃A�j���[�V���� anitime��10�ɂȂ����Ƃ��A�R�}��1�i�߂�
		if (m_anitime >= 8)
		{
			m_anime++;

			m_anitime = 0;
		}

		if (m_anime >= 4)
			m_anime = 0;

		//�ō����x����
		if (m_vx >= 6)
			m_vx = 6;
		if (m_vx <= -6)
			m_vx = -6;

		//�x�N�g��������W�ɕϊ�
		m_px += m_vx;
		m_py += m_vy;

		
		//�U���p
		if (Input::GetVKey('F') == true && m_f == true)
		{
			
		
			if (Weapon == 1)
			{
				m_f = false;
				atk_anime = 2;
				//�e��
				Audio::Start(5);

				CObjBullet* obj_bullet = new CObjBullet(m_px+(m_posture*48), m_py, m_posture, m_f);
				Objs::InsertObj(obj_bullet, OBJ_BULLET, 51);
			}

			else
			{
				m_f = false;
				atk_anime = 1;


				//����U�鉹
				Audio::Start(0);

				CObjSword* obj_b = new CObjSword(m_px, m_py, m_posture, m_f);
				Objs::InsertObj(obj_b, OBJ_SWORD, 1);
			}
			

		}

		if (m_f == false)
			atk_time++;

		//�U�����Ă��炵�΂炭�A�U�����肪���Ȃ��悤�ɂ��Ă���B
		//��莞�Ԃ��ƁA����悤�ɂ��Ă���B
		if (atk_time >= 8)
		{
			atk_anime = 0;
			if (Input::GetVKey('F') == false)
			{
				m_f = true;
				atk_time = 0;

			}
		}





		//��ʊO�ɍs���Ȃ��悤��
		if (m_px > 744)
		{
			m_px = 744;
			m_vx = 0;
		}
		else if (m_px < 0)
		{
			m_px = 0;
			m_vx = 0;
		}


		//�G�ɓ����������ɍs���悤�ɂ���B

		//���G���Ԃ������ɂȂ����� �G�Ƃ̂����蔻����s��
		if (m_mtk == false)
		{ 
			//HitBox�̓��e�����ɖ߂�
			CHitBox* hit = Hits::GetHitBox(this);
			hit->SetPos(m_px + 4.0f, m_py + 4.0f);

			if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.0f + damage;//�G�̍U����
				AllDamage += 1.0f + damage;
			}

			if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.2f + damage;//�G�̍U����
				AllDamage += 1.2f + damage;

			}

			if (hit->CheckObjNameHit(OBJ_ENEMY3) != nullptr)
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 2.0f+damage;//�G�̍U����
				AllDamage += 2.0f + damage;
			}

			if (hit->CheckObjNameHit(OBJ_ENEMY4) != nullptr)
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 2.3f+damage;//�G�̍U����
				AllDamage += 2.3f + damage;
			}

			if (hit->CheckObjNameHit(OBJ_SMALLSLIM))
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.0f + damage;//�G�̍U����
			}

			if (hit->CheckObjNameHit(OBJ_SLIMEBALL))
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 0.5f + damage;
				AllDamage += 0.5f + damage;//�G�̍U����
			}


			if (hit->CheckObjNameHit(OBJ_FIREBALL))
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.0f + damage;
				AllDamage += 1.0f + damage;//�G�̍U����
			}

			if (hit->CheckObjNameHit(OBJ_BOSS1) != nullptr)
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.0f + damage;//�G�̍U����
				AllDamage += 1.0f + damage;
			}

			if (hit->CheckObjNameHit(OBJ_DRAGON) != nullptr)
			{
				//�_���[�W
				Audio::Start(4);
				m_mtk = true;
				m_hp -= 1.5f + damage;//�G�̍U����
				AllDamage += 1.5f + damage;
			}

		}
		//���G��true�ɂȂ�����
		if (m_mtk == true)
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

		//���@�����̉񕜖��@
		if (m_mp >= 20)
		{
			if (m_hp < max_hp)
			{
				if (Input::GetVKey('D') == true && h_t == true && m_Skill == 1)
				{
					h_t = false;
					m_hp += 3.0f;
					m_mp -= 20;
					if (m_hp > max_hp)
					{
						m_hp = max_hp;
					}
				}
				else if (Input::GetVKey('D') == false)
				{
					h_t = true;
				}
			}
		}

		//��l����HP�������Ȃ������A���ł�����
		if (m_hp <= 0)
		{
		//	this->SetStatus(false);
		//	Hits::DeleteHitBox(this);

			((UserData*)Save::GetData())->HPZeroCheck = true;

		//	Scene::SetScene(new CSceneGameOver());
		}

		//�e�X�g�p
		if (Input::GetVKey('O')==true)
		{
		
			Scene::SetScene(new CSceneGameClear());
		}

		//�e�X�g�p
		if (Input::GetVKey('P') == true)
		{

			Scene::SetScene(new CSceneMain());
		}

		if(((UserData*)Save::GetData())->Stage==16)

		//�N���A�V�[���ɃX�R�A��^����
		((UserData*)Save::GetData())->HeroHP = AllDamage;
		
	
}
//�h���[
void CObjHero::Draw()
{
	int AniData[4] =
	{
		1,0,2,0,
	};
		//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,mtk_jkn%3};

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top =(atk_anime*64)+0.0f;
	src.m_left =(AniData[m_anime]*64)+0.0f;
	src.m_right =(AniData[m_anime] *64)+64.0f;
	src.m_bottom = (atk_anime * 64) + 64.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f+m_py;
	dst.m_left =(32.0f*m_posture)+m_px+32.0f;
	dst.m_right = (-32.0f*m_posture )+ m_px+32.0f;
	dst.m_bottom = 64.0f+m_py;

	//�`��
	Draw::Draw(3, &src, &dst, c, 0.0f);
}

int CObjHero::GetHP()
{
	return m_hp;
}

int CObjHero::GetMAXHP()
{
	return max_hp;
}

int CObjHero::GetMP()
{
	return m_mp;
}