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
#include "SceneGameOver.h"
#include "GameHead.h"
#include "GameL\UserData.h"

//�R���X�g���N�^
CSceneGameOver::CSceneGameOver()
{

}
//�f�X�g���N�^
CSceneGameOver::~CSceneGameOver()
{

}
//���������\�b�h
void CSceneGameOver::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬

	Draw::LoadImageW(L"Graphics/GameOver.png", 0, TEX_SIZE_512);
	Draw::LoadImageW(L"Graphics/GameOver11.png", 1, TEX_SIZE_512);



	//���y���̓ǂݍ���
	Audio::LoadAudio(12, L"Sounds/gameoverBGM.wav", SOUND_TYPE::BACK_MUSIC);
	Audio::LoadAudio(9, L"Sounds/kakuteiSE.wav", EFFECT);
	Audio::LoadAudio(11, L"Sounds/cancelSE.wav", EFFECT);

	float Volume = Audio::VolumeMaster(0);
	Audio::Start(12);


	if (((UserData*)Save::GetData())->Stage!=16)
	{
		//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
		CObjGameOver* obj = new CObjGameOver();
		Objs::InsertObj(obj, OBJ_GAME_OVER, 10);
	}
	else
	{
		CObjEndlessResult* obj = new CObjEndlessResult();
		Objs::InsertObj(obj, OBJ_ENDLESSRESULT, 10);
	}

}
//���s�����\�b�h
void CSceneGameOver::Scene()
{

}