#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjStageSelect : public CObj
{
public:
	CObjStageSelect() {};
	~CObjStageSelect() {};
	void Init();
	void Action();
	void Draw();
	int GetStageID();
private:
	bool m_key_flag;//�L�[�t���O
	float cursor_x;
	float cursor_y;
	float cursor_sx,
		cursor_sy;
	int StageID;
	int PageID;
	int MaxPage;

	bool nowLoading;
	//���j���[�{�^���S�ړ�
	float menuAllButtonX;

	int waitTime;
};