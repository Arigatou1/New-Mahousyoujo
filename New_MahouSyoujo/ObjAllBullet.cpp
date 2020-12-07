//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjAllBullet.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjAllBullet::CObjAllBullet(float x, float y)
{
	m_ax = x;
	m_ay = y;
}

//�C�j�V�����C�Y
void CObjAllBullet::Init()
{
	m_avy = 10.0f;
	//�U����
	z_atk = 10;

	//�����蔻��p��HITBOX���쐬
	Hits::SetHitBox(this, m_ax + 32.0f, m_ay, 64, 64, ELEMENT_PLAYER, OBJ_ALLBULLET, 10);
}

//�A�N�V����
void CObjAllBullet::Action()
{

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(m_ax + 32.0f, m_ay);

	//���ɓ���
	m_ay += m_avy;

	//�̈�O�ɏo����e�ۂ�j������
	if (m_ax > 775.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_ax < -25.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

	if (m_ay > 575.0f)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}
}

//�h���[
void CObjAllBullet::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳�؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 64.0f;
	src.m_right = 128.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top    = -32.0f + m_ay;
	dst.m_left   = 32.0f + m_ax;
	dst.m_right  = 96.0f + m_ax;
	dst.m_bottom = 96.0f + m_ay;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

int CObjAllBullet::GetZ_ATK()
{
	return z_atk;
}