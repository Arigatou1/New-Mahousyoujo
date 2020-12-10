#pragma once
//使用するヘッダーファイル
#include "GameL\SceneObjManager.h"

//使用するネームスペース
using namespace GameL;

class CObjDamegeDisplay : public CObj
{
public:

	/// <summary>
	/// ダメージディスプレイ　変更
	/// 12/10 舟瀬
	/// 
	/// 方向、種類の引数は完全に要らなくて、
	/// 各オブジェクトからこのオブジェクトを作成するときに
	/// ダメージ数値と色を指定すればいいんじゃないの？と思い
	/// 変更してみた。
	/// 
	/// </summary>
	/// <param name="x"></param>
	/// <param name="y"></param>
	/// <param name="posture"></param>
	/// <param name="atk"></param>
	/// <param name="damage"></param>
	CObjDamegeDisplay(float x, float y,int damage=0,int color=0);
	~CObjDamegeDisplay() {};
	void Init();
	void Action();
	void Draw();
private:
	float m_Damege;//受けたor与えたダメージ
	float Damege_x;//ダメージ表記するX軸
	float Damege_y;//ダメージ表記するY軸

	int d_time;
	int color_type;
};