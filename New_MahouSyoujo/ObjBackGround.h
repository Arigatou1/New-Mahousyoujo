#pragma once 
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F�^�C�g��
class CObjBackGround : public CObj
{
public:
	CObjBackGround(int id=1,float scale=1.0f) ;
	~CObjBackGround() {};
	void Init();
	void Action();
	void Draw();
private:
	int BackGroundID;
	float bgScale;
};