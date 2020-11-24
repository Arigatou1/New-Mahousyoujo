//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjMana.h"
#include "GameHead.h"
#include "GameL\UserData.h"
//#include "ObjGaugeBaseMana.h"

//�e�X�g�p
#include "GameL\WinInputs.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

CObjMana::~CObjMana()
{
	
}

CObjMana::CObjMana(float x, float y)
{
	Mana_x = x;
	Mana_y = y;
}



//�C�j�V�����C�Y
void CObjMana::Init()
{
	
	Mana_HP = 100;


	//MANA�Q�[�W�x�[�X�I�u�W�F�N�g�쐬
	CObjGaugeMANABase* obj_managb = new CObjGaugeMANABase(Mana_x,Mana_y);
	Objs::InsertObj(obj_managb, OBJ_MANABASE, 50);

	//MANA�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeMANAHP* obj_manahp = new CObjGaugeMANAHP(Mana_x, Mana_y);
	Objs::InsertObj(obj_manahp, OBJ_MANA_HP, 51);

	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, Mana_x , Mana_y, 64, 64, ELEMENT_WHITE, OBJ_MANA, 1);


	mana_damege = ((UserData*)Save::GetData())->Diffculty * 0.5;
}

//�A�N�V����
void CObjMana::Action()
{

	if (Mana_HP <= 0)
	{
		Mana_HP = 0;
	}


	//HitBox�̓��e
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(Mana_x,Mana_y);


	if (hit->CheckObjNameHit(OBJ_ENEMY) != nullptr)
	{
		Mana_HP -= 0.40 + mana_damege * 0.20;
	}

	//�G2�ɓ������HP������
	if (hit->CheckObjNameHit(OBJ_ENEMY2) != nullptr)
	{
		Mana_HP -= 0.80 + mana_damege * 0.20;
	}

	//�G3�ɓ������HP������
	if (hit->CheckObjNameHit(OBJ_ENEMY3) != nullptr)
	{
		Mana_HP -= 0.05;

	}
	
	//�G4�ɓ������HP������
	if (hit->CheckObjNameHit(OBJ_ENEMY4) != nullptr)
	{
		Mana_HP -= 0.05;

	}

	//�������X���C���ɓ������HP������
	if (hit->CheckObjNameHit(OBJ_SMALLSLIM) != nullptr)
	{
		Mana_HP -= 0.20 + mana_damege * 0.20;

	}

	//�}�i��HP�������Ȃ������A���ł�����
	if (Mana_HP <= 0)
	{
		this->SetStatus(false);
		Hits::DeleteHitBox(this);

		Scene::SetScene(new CSceneGameOver());
	}

	((UserData*)Save::GetData())->ManaHP = Mana_HP;
}
//�h���[
void CObjMana::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,Mana_HP/100,Mana_HP/100,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 192.0f;
	src.m_left = 0.0f;
	src.m_right = 64.0f;
	src.m_bottom = 256.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = Mana_y;
	dst.m_left = Mana_x;
	dst.m_right = Mana_x+64;
	dst.m_bottom = Mana_y+64;

	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);
}


float CObjMana::GetHP()
{
	return Mana_HP;
}

//�ʒu���X�擾�p
float CObjMana::GetX()
{
	return Mana_x;
}

//�ʒu���Y�擾�p
float CObjMana::GetY()
{
	return Mana_y;
}