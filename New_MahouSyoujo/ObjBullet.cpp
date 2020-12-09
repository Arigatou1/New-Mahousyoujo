//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "ObjBullet.h"
#include "UtilityModule.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�R���X�g���N�^
CObjBullet::CObjBullet(float x, float y, int posture, bool m_f)
{
	px = x;
	py = y;

	b_posture = posture;
	b_f = m_f;
}

//�C�j�V�����C�Y
void CObjBullet::Init()
{
	Hits::SetHitBox(this, px, py+24, 64, 16, ELEMENT_PLAYER, OBJ_BULLET, 1);
	
	atk_power = 5 - ((UserData*)Save::GetData())->Diffculty;

	hitCheck = false;

}

//�A�N�V����
void CObjBullet::Action()
{
	

	//HitBOx�̓��e��ύX
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(px, py+24);


	if (b_posture == 1)
		px += 36;
	else
		px -= 36;
	

	//�����蔻����s���I�u�W�F�N�g���
	int database[6] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ENEMY3,
		OBJ_ENEMY4,
		OBJ_SMALLSLIM,
		OBJ_BOSS1,
	};

	for(int i=0;i<6;i++)
	{

		if (hit->CheckObjNameHit(database[i])!=nullptr)
		{
			hitCheck = true;
			hit->SetInvincibility(true);
		}

		//Amount++;
	}

	//�̈�O�ɏo����폜����

	bool check = CheckWindow(px, py, -64.0f, -64.0f, 800.0f, 600.0f);
	if (check == false || hitCheck==true)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);
	}

}

//�h���[
void CObjBullet::Draw()
{
	//�`��J���[
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src; //�`�挳ff���؂���ʒu
	RECT_F dst; //�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 128.0f;
	src.m_right = 192.0f;
	src.m_bottom = 256.0f;

	//�\���ʒu�̐ݒ�
	dst.m_top =py+0.0f;
	dst.m_left = (b_posture*32)+px+32.0f;
	dst.m_right = (b_posture*-32)+px+32.0f;
	dst.m_bottom = py+64.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

//�U���͂�Ԃ��֐�
float CObjBullet::GetAttackPower()
{
	return atk_power;
}