#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

class CTutorial :public CObj
{
public:
	CTutorial() {};
	~CTutorial() {};
	void Init();
	void Action();
	void Draw();
	int GetOrder() { return Order; };
	void SkillIconsDraw(int id);
private:
	bool cond1;//�����P
	bool cond2;//�����Q

	bool condreset;//�������Z�b�g
	int shootDownTime;

	int Order;//����
	int m_skill;//���@�����̃X�L������
	int Time;
};