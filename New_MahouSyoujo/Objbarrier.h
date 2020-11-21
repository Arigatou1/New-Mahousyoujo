#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjBarrier : public CObj
{
public:
	CObjBarrier(float x, float y);
	~CObjBarrier() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
	float GetBX();//バリアのx座標
private:
	float mb_x;
	float mb_y;
	float b_time;//バリアの出てる時間

	int b_skill;//魔法少女のスキル選択

	bool b_t;//バリアの間隔(仮)
};