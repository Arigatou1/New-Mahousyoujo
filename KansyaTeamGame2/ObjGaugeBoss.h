#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjGaugeBoss :public CObj
{
public:
	CObjGaugeBoss() {};

	~CObjGaugeBoss() {};
	void Init();
	void Action();
	void Draw();
	int GetPercent();
private:
	float HP;
	float MAXHP;
	float GaugePercent;


};

