#pragma once 
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：タイトル
class CObjBackGround : public CObj
{
public:
	CObjBackGround() {};
	~CObjBackGround() {};
	void Init();
	void Action();
	void Draw();
private:

};