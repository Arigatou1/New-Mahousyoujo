#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjMenuEndless : public CObj
{
public:
	CObjMenuEndless() {};
	~CObjMenuEndless() {};
	void Init();
	void Action();
	void Draw();
	int GetStageID();
private:
	bool m_key_flag;//�L�[�t���O
	bool nowLoading;
	//���j���[�{�^���S�ړ�
	float menuAllButtonX;

	int waitTime;
	//�J�[����|�W�V����
	float cursor_x;
	float cursor_y;
	//�J�[�\���X�P�[��
	float cursor_sx;
	float cursor_sy;
};