#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[�����C��
class EnemyAppear :public CObj
{
public:
	EnemyAppear() {};
	~EnemyAppear() {};
	void Init();
	void Action();
	void Draw();
	//int GetNUM();
	void BossDisappearnce();

private:
	int EnemyAmount;
	int StageID;
	int m_time;
	//�G���h���X�^�C��
	int e_time;
	int enemyAmo;
	//int e_num;//�G�̌̖�
	bool m_key_flag;
	int randomAppearTime;
	float appearEnemyX;

	//�{�X�o�ꒆ
	bool BossAppearRing;
	int enemyCount;

};