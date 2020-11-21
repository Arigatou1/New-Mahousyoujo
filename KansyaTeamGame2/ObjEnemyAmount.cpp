//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "ObjEnemyAmount.h"
#include "GameL\UserData.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjEnemyAmount::Init()
{
	EnemyAmount = 0;
}

//アクション
void CObjEnemyAmount::Action()
{
//	CObjEnemy* obj1 = (CObjEnemy*)Objs::GetObj(OBJ_ENEMY);
//	if(obj1!=nullptr)
//	EnemyAmount = obj1->EneAmo();
}



//ドロー
void CObjEnemyAmount::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];
	swprintf_s(str, L"残り敵の数:%d", ((UserData*)Save::GetData())->enemyRemain);//整数を文字列か
	//swprintf_s(str, L"操作方法:←→移動 Spaceジャンプ F攻撃 D魔法攻撃");//整数を文字列か
	
	
	//swprintf_s(str, L"スコア:%d", ((UserData*)Save::GetData())->Score);//整数を文字列か
	
	Font::StrDraw(str, 2, 96, 24, c);

}