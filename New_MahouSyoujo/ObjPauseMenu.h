#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjPauseMenu : public CObj
{
public:
	CObjPauseMenu() {};
	~CObjPauseMenu() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_key_flag;//�L�[�t���O
	float cursor_x;
	float cursor_y;
	int nowSelect;
	float cursor_sx;
	float cursor_sy;
};