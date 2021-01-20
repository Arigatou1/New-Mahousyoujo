#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjHeelIcon : public CObj
{
public:
	CObjHeelIcon() {};
	~CObjHeelIcon() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	int b_skill;//魔法少女のスキル選択

	int Graphic_Serct;//画像の変更用
};