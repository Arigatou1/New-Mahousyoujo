#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�Q�[���I�[�o�[
class CObjEnemyAmount : public CObj
{
public:
	CObjEnemyAmount() {};
	~CObjEnemyAmount() {};
	void Init();
	void Action();
	void Draw();
private:
	int EnemyAmount;
	int shootDownTime;
};