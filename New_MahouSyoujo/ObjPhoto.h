#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjPhoto : public CObj
{
public:
	CObjPhoto(float src_top, float src_left,float src_right,float src_bottom,
				float x_size, float y_size, float dst_top, float dst_left, int g,int n);
	~CObjPhoto() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	float size_x;//表示するアイコンの大きさ
	float size_y;
	float s_t;//top
	float s_l;//left
	float s_r;//right
	float s_b;//bottom
	float d_t;//表示top
	float d_l;//表示left
	int Graphic_Serct;//画像の変更用

	int p_num;//現在の番号（？）
	int p_order;//チュートリアルの順番
};