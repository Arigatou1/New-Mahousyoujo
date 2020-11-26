//�g�p����w�b�_�[�t�@�C��
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"

#include "ObjShockWave.h"
#include "GameL\UserData.h"
#include "UtilityModule.h"

//�g�p����l�[���x�[�X
using namespace GameL;

//�R���X�g���N�^
CObjShockWave::CObjShockWave(float x, float y, float vx, float vy)
{
	m_ex = x;
	m_ey = y;
	m_vx = vx;
	m_vy = vy;
}
//�C�j�V�����C�Y
void CObjShockWave::Init()
{

	//block�Ƃ̏Փˏ�Ԋm�F�p
	e1_hit_up = false;
	e1_hit_down = false;
	e1_hit_left = false;
	e1_hit_right = false;

	e1_t = true;

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ex, m_ey, 64, 64, ELEMENT_ENEMY, OBJ_SHOCKWAVE, 10);


	//��l���@�Ŋp�x���Ƃ�

	CObjMana* obj = (CObjMana*)Objs::GetObj(OBJ_MANA);
	float x = obj->GetX() - m_ex;
	float y = obj->GetY() - m_ey;
	float ar = atan2(-y, x) * 180.0f / 3.14f;

	if (ar < 0)
		ar = 360 - abs(ar);

	//m_vx�̑��x�ňړ�

	m_vx = cos(3.14 / 180 * ar);

	m_vy = -sin(3.14 / 180 * ar);
}

//�A�N�V����
void CObjShockWave::Action()
{


	m_ex += m_vx;
	m_ey += m_vy;

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ex, m_ey);




	
	//�ړ��x�N�g���̐��K��
	UnitVec(&m_vx, &m_vy);
}

//�h���[
void CObjShockWave::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 192.0f;
	src.m_right = 256.0f;
	src.m_bottom = 256.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = m_ey;
	dst.m_left = m_ex;
	dst.m_right = m_ex + 64.0f;
	dst.m_bottom = m_ey + 64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}
