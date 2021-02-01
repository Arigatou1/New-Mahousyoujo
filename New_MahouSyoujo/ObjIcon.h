#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjIcon : public CObj
{
public:
	CObjIcon(int size , float x , float y,int g, bool s);
	~CObjIcon() {};
	void Init();   //イニシャライズ
	void Action(); //アクション
	void Draw();   //ドロー
private:
	int b_skill;//魔法少女のスキル選択

	int icon_size;//表示するアイコンの大きさ
	float i_x;//表示する画像の左上のX座標
	float i_y;//表示する画像の左上のY座標
	int Graphic_Serct;//画像の変更用
	int i_order;//チュートリアルの順番

	bool serect;//true = チュートリアル用 false = メイン


	int size_spare;//サイズのバックアップ
	float x_spare;// X座標のバックアップ
	float y_spare;// Y座標のバックアップ
};