//STL�f�o�b�O�@�\��OFF�ɂ���
#define _SECURE_SCL(O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMain.h"
#include "GameHead.h"
#include "GameL\WinInputs.h"
#include "GameL/Audio.h"

//�R���X�g���N�^
CSceneMain::CSceneMain()
{

}

//�f�X�g���N�^
CSceneMain::~CSceneMain()
{
	
}

//���������\�b�h
void CSceneMain::InitScene()
{
	((UserData*)Save::GetData())->HPZeroCheck = false;

	//���y�ǂݍ���
	Audio::LoadAudio(0, L"Sounds/swordSE.wav", EFFECT);
	Audio::LoadAudio(1, L"Sounds/girlSE.wav", EFFECT);
	Audio::LoadAudio(2, L"Sounds/bakuhatuSE.wav", EFFECT);
	Audio::LoadAudio(3, L"Sounds/menuSE.wav", EFFECT);
	Audio::LoadAudio(4, L"Sounds/herodamageSE.wav", EFFECT);
	Audio::LoadAudio(5, L"Sounds/bulletSE.wav", EFFECT);
	Audio::LoadAudio(6, L"Sounds/herojumpSE.wav", EFFECT);
	Audio::LoadAudio(13, L"Sounds/gameclearBGM.wav", SOUND_TYPE::EFFECT);
	Audio::LoadAudio(14, L"Sounds/danjonBGM1.wav", BACK_MUSIC);
	Audio::LoadAudio(15, L"Sounds/danjonBGM2.wav", BACK_MUSIC);
	Audio::LoadAudio(16, L"Sounds/bossBGM1.wav", BACK_MUSIC);
	Audio::LoadAudio(17, L"Sounds/wahuBGM.wav", BACK_MUSIC);
	Audio::LoadAudio(18, L"Sounds/danjonBGM3.wav", BACK_MUSIC);
	Audio::LoadAudio(19, L"Sounds/bossBGM2.wav", BACK_MUSIC);
	Audio::LoadAudio(20, L"Sounds/herodownSE.wav", EFFECT);
	Audio::LoadAudio(21, L"Sounds/girlattackSE.wav", EFFECT);
	Audio::LoadAudio(22, L"Sounds/kaihukuSE.wav", EFFECT);
	Audio::LoadAudio(23, L"Sounds/bariaSE.wav", EFFECT);
	Audio::LoadAudio(25, L"Sounds/manadamageSE.wav", EFFECT);
	Audio::LoadAudio(26, L"Sounds/dragonjampSE.wav", EFFECT);
	Audio::LoadAudio(27, L"Sounds/firebreathSE.wav", EFFECT);
	Audio::LoadAudio(28, L"Sounds/bossattackSE2.wav", EFFECT);
	Audio::LoadAudio(29, L"Sounds/bossskillSE1.wav", EFFECT);
	Audio::LoadAudio(30, L"Sounds/endlessBGM.wav", BACK_MUSIC);
	
	//�O���f�[�^�̓ǂݍ���

	unique_ptr<wchar_t>p;//�X�e�[�W���|�C���^�[
	int size;
	int StageID =((UserData*)Save::GetData())->Stage+1;

	
	//�}�b�v�f�[�^��ǂݍ��ށB
	wchar_t s[128];

	if (StageID >= 9 && StageID!=17)
	swprintf_s(s, L"Stage/Stage8.csv", StageID);

	else
		swprintf_s(s, L"Stage/Stage%d.csv", StageID);

	p = Save::ExternalDataOpen(s, &size);//�O���f�[�^�ǂݍ���
	
	int map[10][13];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	//HP�pFont�쐬
	Font::SetStrTex(L"1234567890/.+-�c��G�̐�:");


	//�O���t�B�b�N�̓ǂݍ���
	Draw::LoadImageW(L"Graphics/image.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/Gauge.png", 1, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/BackGround.png", 2, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/Hero.png", 3, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/Dragon.png", 4, TEX_SIZE_128);
	Draw::LoadImageW(L"Graphics/Baria.png", 5, TEX_SIZE_128);
	Draw::LoadImageW(L"Graphics/Caution.png", 6, TEX_SIZE_128);
	Draw::LoadImageW(L"Graphics/1.B�A�C�R������.png", 10, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/1.B�A�C�R����������.png", 11, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/2.H�A�C�R������.png", 12, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/2.H�A�C�R����������.png", 13, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/3.M�A�C�R������.png", 14, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/3.M�A�C�R����������.png", 15, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/block.png", 63, TEX_SIZE_64);

	//�w�i�ǂݍ���
	for (int i = 1; i <= 10; i++)
	{
		wchar_t bgid[128];

		swprintf_s(bgid, L"BackGrounds/bg_%02d.png", i);

		Draw::LoadImageW(bgid, i+50, TEX_SIZE_512);
	}
	


	//��l���I�u�W�F�N�g�쐬
	CObjHero* obj = new CObjHero();
	Objs::InsertObj(obj, OBJ_HERO, 60);

	//���@�����I�u�W�F�N�g�쐬
	CObjMagicalGirl* obj_magicalgirl = new CObjMagicalGirl();
	Objs::InsertObj(obj_magicalgirl, OBJ_MAGICALGIRL, 61);

	//HP�Q�[�W�I�u�W�F�N�g�쐬
	CObjGaugeHP* obj_ghp = new CObjGaugeHP();
	Objs::InsertObj(obj_ghp, OBJ_GAUGEHP, 51);
	
	//Block�I�u�W�F�N�g
	CObjBlock* objb = new CObjBlock(map);
	Objs::InsertObj(objb, OBJ_BLOCK, 11);

	//�G�̐��I�u�W�F�N�g�쐬
	CObjEnemyAmount* obj_eneamo = new CObjEnemyAmount();
	Objs::InsertObj(obj_eneamo, OBJ_ENEMYAMOUNT, 51);

	//PauseMenu�I�u�W�F�N�g�쐬
	CObjPauseMenu* obj_pause = new CObjPauseMenu();
	Objs::InsertObj(obj_pause, OBJ_PAUSEMENU, 100);

	
	//EnemyAppear
	EnemyAppear* obj_appear = new EnemyAppear();
	Objs::InsertObj(obj_appear, OBJ_APPEAR, 101);

	//�t�F�[�h�C��
	Fadeout* obj_Fadeout = new Fadeout(3,true);
	Objs::InsertObj(obj_Fadeout, FADEOUT, 151);

	//���e�I�A�C�R���쐬
	CObjIcon* obj_icon = new CObjIcon(104.0f, 716.0f, -20.0f, 14, false);
	Objs::InsertObj(obj_icon, OBJ_ICON, 60);
	
	//�o���A�A�C�R���쐬
	obj_icon = new CObjIcon(104.0f, 716.0f, 44.0f, 10, false);
	Objs::InsertObj(obj_icon, OBJ_ICON, 60);

	//�q�[���A�C�R���쐬
	obj_icon = new CObjIcon(104.0f, 716.0f, 108.0f, 12, false);
	Objs::InsertObj(obj_icon, OBJ_ICON, 60);



	//�^�C��������
	m_time = 0;

	EnemyAmount = 0;
	shootDownTime = 0;
}

//���s�����\�b�h
void CSceneMain::Scene()
{

	//�|�[�Y���j���[
	if (Input::GetVKey(VK_ESCAPE) == true)
	{
		//�|�[�Y���j���[SE
		Audio::Start(3);
		if (m_key_flag == true)
		{
			((UserData*)Save::GetData())->PauseMenu = true;
			m_key_flag = false;
		}
	}

	else

		m_key_flag = true;


}

