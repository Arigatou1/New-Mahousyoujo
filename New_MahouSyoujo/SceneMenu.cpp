//STL�f�o�b�O�@�\OFF�ɂ���

#define _SECURE_SCL (O)
#define _HAS_ITERATOR_DEBUGGING(O)

//GameL�Ŏg�p����w�b�_�[
#include "GameL\SceneObjManager.h"
#include "GameL\DrawFont.h"

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


}
//���s�����\�b�h
void CSceneMenu::Scene()
{

}