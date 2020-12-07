#pragma once
//使用するヘッダーファイル
#include "GameL\SceneManager.h"

//使用するネームスペース
using namespace GameL;

//シーンメイン
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
	//敵殲滅後時間用
	int shootDownTime;
	int fadeSpeed;
	bool pfadeIn;
};