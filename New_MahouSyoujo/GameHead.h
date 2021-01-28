#pragma once

//�I�u�W�F�N�g�l�[��------------------------------
enum OBJ_NAME
{
	OBJ_NO_NAME,	//�I�u�W�F�N�g������(�֎~)
	//�Q�[���Ŏg���I�u�W�F�N�g�̖��O
	//OBJ_�����ƕ\�L
	OBJ_HERO,
	OBJ_MAGICALGIRL,
	OBJ_HOMINGBULLET,
	OBJ_ALLBULLET,
	OBJ_SWORD,
	OBJ_ENEMY,
	OBJ_ENEMY2,
	OBJ_ENEMY3,
	OBJ_ENEMY4,
	OBJ_GAUGEBASE,
	OBJ_GAUGEHP,
	OBJ_GAUGEMP,
	OBJ_BLOCK,
	OBJ_MANA,
	OBJ_MANABASE,
	OBJ_MANA_HP,
	OBJ_TITLE,
	OBJ_GAME_OVER,
	OBJ_BG,
	OBJ_GAME_CLEAR,
	OBJ_ENEMYAMOUNT,
	OBJ_STAGESELECT,
	OBJ_BULLET,
	OBJ_MODESELECT,
	OBJ_BARRIER,
	OBJ_CUSTOMIZE,
	OBJ_SMALLSLIM,
	OBJ_PAUSEMENU,
	OBJ_SETTING,
	OBJ_BOSS1,
	OBJ_SLIMEBALL,
	OBJ_APPEAR,
	OBJ_GAUGEBASEBOSS,
	OBJ_GAUGEBOSS,
	OBJ_FIREBALL,
	OBJ_DRAGON,
	OBJ_SHOCKWAVE,
	OBJ_STAGEENDLESS,
	FADEOUT,
	OBJ_ENDLESSRESULT,
	OBJ_DAMEGEDISPLAY,
	OBJ_CAUTION,
	OBJ_TUTORIAL,
	OBJ_TUTORIALHERO,
	OBJ_ICON,
	OBJ_PHOTO,
};
//------------------------------------------------

//�����蔻�葮��----------------------------------
enum HIT_ELEMENTS
{
	ELEMENT_NULL,//�������� �S�Ă̑����Ɠ����蔻�肪���s�����
	//�ȉ��@�����������m�ł͓����蔻��͎��s����Ȃ�
	//�����͒ǉ��\�����A�f�o�b�N���̐F�͏����ݒ蕪��������
	ELEMENT_PLAYER,
	ELEMENT_ENEMY,
	ELEMENT_ITEM,
	ELEMENT_MAGIC,
	ELEMENT_FIELD,
	ELEMENT_RED,
	ELEMENT_GREEN,
	ELEMENT_BLUE,
	ELEMENT_BLACK,
	ELEMENT_WHITE,
};
//------------------------------------------------

//------------------------------------------------
//�Z�[�u�����[�h�ƃV�[���Ԃ̂���肷��f�[�^
struct UserData
{

	//�ݒ�ŕύX�ł��Ȃ��f�[�^------------------------
	int mSeveData;	//�T���v���Z�[�u�f�[�^
	//�X�e�[�WID���擾����
	int Stage;
	//�X�e�[�W�̃X�R�A�f�[�^
	int ScoreData[20];
	//�ő�X�e�[�W����20�����A�Q�O�̃N���A��������邽��
	bool Clear_Flag[21];
	//�|�[�Y���j���[�p�ϐ�
	bool PauseMenu;
	//�X�R�A�̌v�Z���邽�߂̂���
	float HeroHP;
	float ManaHP;
	//�c��G�̐��̕\��
	int enemyRemain;
	bool HPZeroCheck;
	bool tutorialDone;

	//---------------------------------------------
	//�ݒ�ŕύX�ł���f�[�^

	//��l���̕���B�� 0 �e 1
	int weapon;
	//��Փx
	int Diffculty;

	bool DamageDraw;
	int masterVolume;
};
//------------------------------------------------


//�Q�[�����Ŏg�p�����O���[�o���ϐ��E�萔�E��--



//------------------------------------------------
//�Q�[�����Ŏg�p����N���X�w�b�_------------------


//------------------------------------------------

//�Q�[���V�[���I�u�W�F�N�g�w�b�_-----------------
#include "ObjHero.h"
#include "ObjMagicalGirl.h"
#include "CObjHomingBullet.h"
#include "ObjAllBullet.h"
#include "ObjEnemy.h"
#include "ObjEnemy2.h"
#include "ObjEnemy3.h"
#include "ObjEnemy4.h"
#include "ObjBlock.h"
#include "ObjGaugeHP.h"
#include "ObjGaugeMana.h"
#include "ObjMana.h"
#include "ObjTitle.h"
#include "ObjGameOver.h"
#include "ObjBackGround.h"
#include "ObjGameClear.h"
#include "ObjEnemyAmount.h"
#include "ObjStageSelect.h"
#include "ObjBullet.h"
#include "ObjModeSelect.h"
#include "Objbarrier.h"
#include "ObjCustomize.h"
#include "ObjSmallSlim.h"
#include "ObjPauseMenu.h"
#include "ObjSetting.h"
#include "ObjBoss1.h"
#include "ObjSlimeBall.h"
#include "ObjSword.h"
#include "EnemyAppear.h"
#include "ObjMenuEndless.h"
#include "ObjEndlessResult.h"

#include "ObjGaugeBoss.h"
#include "ObjFireBall.h"
#include "ObjDragon.h"
#include "ObjShockWave.h"
#include "ClearFadeout.h"
#include "ObjCaution.h"

#include "ObjDamegeDisplay.h"
#include "Tutorial.h"
#include "TutorialHero.h"
#include "ObjIcon.h"
#include "ObjPhoto.h"


//------------------------------------------------

//�Q�[���V�[���N���X�w�b�_------------------------
#include "SceneMain.h"
#include "SceneTitle.h"
#include "SceneGameOver.h"
#include "SceneGameClear.h"
#include "SceneMenu.h"
//-----------------------------------------------

//�V�[���X�^�[�g�N���X---------------------------
//�Q�[���J�n���̃V�[���N���X�o�^
#define SET_GAME_START CSceneTitle
//-----------------------------------------------