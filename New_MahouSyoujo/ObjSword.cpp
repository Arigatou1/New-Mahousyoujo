//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "GameL\WinInputs.h"
#include "GameHead.h"
#include "ObjSword.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;


//�R���X�g���N�^
CObjSword::CObjSword(float x, float y,int posture,bool m_f)
{
	a_px = x;
	a_py = y;

	a_posture = posture;
	a_f = m_f;
}

//�C�j�V�����C�Y
void CObjSword::Init()
{
	
	Hits::SetHitBox(this, a_px + (a_posture * 60), a_py, 56, 56, ELEMENT_PLAYER, OBJ_SWORD, 1);
	atk_time = 0;

	atk_power = 10 - ((UserData*)Save::GetData())->Diffculty;
}

//�A�N�V����
void CObjSword::Action()
{

	//m_f����^�U���󂯎��
	if (a_f == false)
	{

		//HitBox�̓��e���X�V
		CHitBox* hit = Hits::GetHitBox(this);
		hit->SetPos(a_px + (a_posture * 60), a_py);

		atk_time++;
	}

	//if (atk_time>=2)
	//{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

	//}

}
//�h���[
void CObjSword::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top =0.0f;
	src.m_left =0.0f;
	src.m_right = 0.0f;
	src.m_bottom = 0.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 0.0f;
	dst.m_bottom = 0.0f;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}

//�U���͂�Ԃ��֐�
float CObjSword::GetAttackPower()
{
	return atk_power;
}