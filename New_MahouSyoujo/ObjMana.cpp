//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\SceneManager.h"
#include "GameL\HitBoxManager.h"
#include "ObjMana.h"
#include "GameHead.h"
#include "GameL\UserData.h"
#include "GameL/Audio.h"
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


	//MANA�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeMANAHP* obj_manahp = new CObjGaugeMANAHP(Mana_x, Mana_y);
	Objs::InsertObj(obj_manahp, OBJ_MANA_HP, 51);

	//�����蔻��pHitbox���쐬
	Hits::SetHitBox(this, Mana_x , Mana_y, 64, 64, ELEMENT_WHITE, OBJ_MANA, 1);


	mana_damege = ((UserData*)Save::GetData())->Diffculty * 0.5;

	shootDownTime = 0;
}

//�A�N�V����
void CObjMana::Action()
{

	//HitBox�̓��e
	CHitBox* hit = Hits::GetHitBox(this);
	hit->SetPos(Mana_x,Mana_y);

	//�����蔻����s���I�u�W�F�N�g���
	int database[8] =
	{
		OBJ_ENEMY,
		OBJ_ENEMY2,
		OBJ_ENEMY3,
		OBJ_ENEMY4,
		OBJ_SMALLSLIM,
		OBJ_SHOCKWAVE,
		OBJ_FIREBALL,
		OBJ_SLIMEBALL,
	};

	for (int i = 0; i < 8; i++)
	{
		//�G�̍U����
		if (hit->CheckObjNameHit(database[i]) != nullptr)
		{
			Audio::Start(25);
			if (i == 0)
				MANA_damege = 2.0 + mana_damege * 0.20;
			else if (i == 1)
				MANA_damege = 4.0 + mana_damege * 0.20;
			else if (i == 2)
				MANA_damege = 0.5;
			else if (i == 3)
				MANA_damege = 0.5;
			else if (i == 4)
				MANA_damege = 1.0 + mana_damege * 0.20;
			else if (i == 5)
				MANA_damege = 2.0 + mana_damege * 0.10;
			else if (i == 6)
				MANA_damege = 0.1 + mana_damege * 0.10;
			else if (i == 7)
				MANA_damege = 0.1 + mana_damege * 0.20;

			Mana_HP -= MANA_damege;

		}

		if (hit->CheckObjNameHit(database[i]) != nullptr)
		{
			//�_���[�W�\�L�쐬
			CObjDamegeDisplay* obj_dd = new CObjDamegeDisplay(Mana_x+13+32, Mana_y-32, MANA_damege,1);
			Objs::InsertObj(obj_dd, OBJ_DAMEGEDISPLAY, 60);
		}
	}

	//HP0�ɂȂ����Ƃ�
	if (Mana_HP <= 0)
	{
		//0�Œ�
		Mana_HP = 0;
		//HP���[���ɂȂ�����A�ҋ@���Ԃ𑝉�������B
		shootDownTime++;
		((UserData*)Save::GetData())->HPZeroCheck = true;

		if (shootDownTime == 50)
		{
			Audio::Start(20);
		}

		if (shootDownTime == 200)
		{
			//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout();
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}

		else if (shootDownTime > 300)
		{
			this->SetStatus(false);
			Hits::DeleteHitBox(this);
			Scene::SetScene(new CSceneGameOver());
		}

	}

	//�G���h���X���[�h�ł͂Ȃ��ꍇ
	if(((UserData*)Save::GetData())->Stage!=16)
	((UserData*)Save::GetData())->ManaHP = 100.0f - Mana_HP;
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