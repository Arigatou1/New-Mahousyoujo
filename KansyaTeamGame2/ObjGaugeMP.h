#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�\�[�h
class CObjGaugeMP :public CObj
{
public:
	CObjGaugeMP() {};
	~CObjGaugeMP() {};
	void Init();
	void Action();
	void Draw();
private:
	float MP;
	float MaxMP;
	float GaugePercent;
	float gm_x;
	float gm_y;

};