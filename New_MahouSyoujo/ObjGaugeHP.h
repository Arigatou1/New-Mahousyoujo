#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjGaugeHP :public CObj
{
public:
	CObjGaugeHP() {};

	~CObjGaugeHP() {};
	void Init();
	void Action();
	void Draw();
	int GetPercent();
private:
	float HP;
	float MAXHP;
	float GaugePercent[2];
	float MP;
	float MaxMP;

};

