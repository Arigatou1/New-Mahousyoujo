#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjEndlessResult : public CObj
{
public:
	CObjEndlessResult() {};
	~CObjEndlessResult() {};
	void Init();
	void Action();
	void Draw();
private:
	float Score;
	bool m_key_flag;//�L�[�t���O

};