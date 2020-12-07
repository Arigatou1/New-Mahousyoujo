//STL�f�o�b�O�@�\OFF�ɂ���

#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"
#include "GameL/Audio.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�g�p�w�b�_�[
#include "SceneMenu.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneMenu::CSceneMenu()
{

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
	Draw::LoadImageW(L"Menu.png", 0, TEX_SIZE_512);

	
	//���[�h�Z���N�g�I�u�W�F�N�g�쐬
	CObjModeSelect* obj = new CObjModeSelect();
	Objs::InsertObj(obj, OBJ_MODESELECT, 0);

	//���y���̓ǂݍ���
	Audio::LoadAudio(8, L"Sounds/menuBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"Sounds/kakuteiSE.wav", EFFECT);
	Audio::LoadAudio(10, L"Sounds/sentakuSE.wav", EFFECT);
	Audio::LoadAudio(11, L"Sounds/cancelSE.wav", EFFECT);

	//�o�b�N�~���[�W�b�N�X�^�[�g
	float Volume = Audio::VolumeMaster(-0.05f);
	Audio::Start(8);


}
//���s�����\�b�h
void CSceneMenu::Scene()
{

}