#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjGaugeBoss :public CObj
{
public:
	CObjGaugeBoss(float x,float y) ;

	~CObjGaugeBoss() {};
	void Init();
	void Action();
	void Draw();
	int GetPercent();
	void GaugePosTweak();
private:
	float HP;
	float MAXHP;
	float GaugePercent;

	float pos_x;
	float pos_y;
};

