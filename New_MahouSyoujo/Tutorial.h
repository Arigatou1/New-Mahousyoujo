#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CTutorial :public CScene
{
public:
	CTutorial() {};
	~CTutorial() {};
	void Init();
	void Action();
	void Draw();
private:
	bool cond1;//�����P
	bool cond2;//�����Q

	int Order;//����
};