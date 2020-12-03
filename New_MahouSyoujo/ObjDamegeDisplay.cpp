//使用するヘッダーファイル
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjDamegeDisplay.h"

//イニシャライズ
void CObjDamegeDisplay::Init()
{
	CObjSword* obj_sword = (CObjSword*)Objs::GetObj(OBJ_SWORD);
	Sword_ATK = obj_sword->GetAttackPower();
	d_time = 0;
}

//アクション
void CObjDamegeDisplay::Action()
{
	d_time++;

	if (d_time == 60)
		this->SetStatus(false);

}
//ドロー
void CObjDamegeDisplay::Draw()
{
	//描画カラー情報
	float c[4] = { 1.0f,0.0f,0.0f,1.0f };

	//描画
	wchar_t str[128];
	swprintf_s(str, L"%.0lf", Sword_ATK);//整数を文字列か
	Font::StrDraw(str, 0, 500, 24, c);
}
