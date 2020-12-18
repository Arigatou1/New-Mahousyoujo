//STL�f�o�b�O�@�\OFF�ɂ���

#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/Audio.h"
#include "UtilityModule.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMenu.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMenu::CSceneMenu(int mode)
{
	loadMode = mode;
}
//�f�X�g���N�^
CSceneMenu::~CSceneMenu()
{

}
//���������\�b�h
void CSceneMenu::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"Game Menu");

	//�O���t�B�b�N�̓ǂݍ���
	Draw::LoadImageW(L"Graphics/Menu.png", 0, TEX_SIZE_512);
	//�w�i�ǂݍ���
	for (int i = 0; i <= 10; i++)
	{
		wchar_t bgid[128];

		swprintf_s(bgid, L"BackGrounds/bg_%02d.png", i);

		Draw::LoadImageW(bgid, i + 50, TEX_SIZE_512);
	}
	
	switch (loadMode)
	{
	case 0:
	{
		//���[�h�Z���N�g�I�u�W�F�N�g�쐬
		CObjModeSelect* obj = new CObjModeSelect();
		Objs::InsertObj(obj, OBJ_MODESELECT, 3);
		break;
	}
	case 1:
	{
		//���[�h�Z���N�g�I�u�W�F�N�g�쐬
		CObjStageSelect* obj2 = new CObjStageSelect();
		Objs::InsertObj(obj2, OBJ_STAGESELECT, 3);
		break;
	}
	case 2:
	{
		//�G���h���X���j���[�I�u�W�F�N�g�쐬
		CObjMenuEndless* obj2 = new CObjMenuEndless();
		Objs::InsertObj(obj2, OBJ_STAGEENDLESS, 3);
		break;
	}

	}
	
	CObjBackGround* obj_bg = new CObjBackGround(0);
	Objs::InsertObj(obj_bg, OBJ_BG, 1);

	//�t�F�[�h�C��
	Fadeout* obj_Fadeout = new Fadeout(3, true);
	Objs::InsertObj(obj_Fadeout, FADEOUT, 151);

	//���y���̓ǂݍ���
	Audio::LoadAudio(8, L"Sounds/menuBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"Sounds/kakuteiSE.wav", EFFECT);
	Audio::LoadAudio(10, L"Sounds/sentakuSE.wav", EFFECT);
	Audio::LoadAudio(11, L"Sounds/cancelSE.wav", EFFECT);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(0);
	Audio::Start(8);

	
}
//���s�����\�b�h
void CSceneMenu::Scene()
{
	
}