#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjCustomize : public CObj
{
public:
	CObjCustomize(int mode = 0) { Mode = mode; };
	~CObjCustomize() {};
	void Init();
	void Action();
	void Draw();

private:
	bool m_key_flag;//�L�[�t���O
	float cursor_x;
	float cursor_y;
	int nowSelect;
	int Mode;
	
	void cursorUp();
	void cursorDown();
	void CustomizeClose();
};