#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjHeelIcon : public CObj
{
public:
	CObjHeelIcon() {};
	~CObjHeelIcon() {};
	void Init();   //�C�j�V�����C�Y
	void Action(); //�A�N�V����
	void Draw();   //�h���[
private:
	int b_skill;//���@�����̃X�L���I��

	int Graphic_Serct;//�摜�̕ύX�p
};