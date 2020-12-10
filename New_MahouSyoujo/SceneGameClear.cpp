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
#include "SceneGameClear.h"
#include "GameHead.h"

//�R���X�g���N�^
CSceneGameClear::CSceneGameClear()
{

}
//�f�X�g���N�^
CSceneGameClear::~CSceneGameClear()
{

}
//���������\�b�h
void CSceneGameClear::InitScene()
{
	//�o�͂����镶���̃O���t�B�b�N���쐬
	Font::SetStrTex(L"GAME CLEAR");
	
	Draw::LoadImageW(L"Graphics/Stage Clear.png", 0, TEX_SIZE_512);


	//���y���̓ǂݍ���
	Audio::LoadAudio(13, L"Sounds/gameclearBGM.wav", SOUND_TYPE::EFFECT);

	float Volume = Audio::VolumeMaster(0);
	Audio::Start(13);


	//�Q�[���I�[�o�[�I�u�W�F�N�g�쐬
	CObjGameClear* obj = new CObjGameClear();
	Objs::InsertObj(obj, OBJ_GAME_CLEAR, 10);
}
//���s�����\�b�h
void CSceneGameClear::Scene()
{

}