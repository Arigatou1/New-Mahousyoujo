#pragma once
//�g�p����w�b�_�[�t�@�C��
#include "GameL\SceneManager.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�V�[�����C��
class Fadeout :public CObj
{
public:
	Fadeout(int speed = 1,bool fadeIn=false);
	~Fadeout() {};
	void Init();
	void Action();
	void Draw();
	//int GetNUM();
private:
	//�G�r�Ō㎞�ԗp
	int shootDownTime;
	int fadeSpeed;
	bool pfadeIn;
};