#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjCaution : public CObj
{
public:
	CObjCaution() {};
	~CObjCaution() {};
	void Init();
	void Action();
	void Draw();
private:
	int m_time;
	int Opacity;
};