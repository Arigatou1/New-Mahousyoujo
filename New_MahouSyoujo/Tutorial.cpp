//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameL\UserData.h"
#include "GameHead.h"
#include "Tutorial.h"

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CTutorial::Init()
{
	
	//外部データの読み込み
	unique_ptr<wchar_t>p;//ステージ情報ポインター
	/*int size;
	int StageID = ((UserData*)Save::GetData())->Stage + 1;

	//マップデータを読み込む。
	wchar_t s[128];

	if (StageID >= 9 && StageID != 17)
		swprintf_s(s, L"Stage/Stage8.csv", StageID);

	else
		swprintf_s(s, L"Stage/Stage%d.csv", StageID);

	p = Save::ExternalDataOpen(s, &size);//外部データ読み込み
	*/
	int map[10][13];
	int count = 1;
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int w = 0;
			swscanf_s(&p.get()[count], L"%d", &w);

			map[i][j] = w;
			count += 2;
		}
	}

	Order = 1;
	cond1 = false;
	cond2 = false;

	condreset = false;
}

//アクション
void CTutorial::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_skill = obj_magicalgirl->GetSkill();
	}

	switch (Order)
	{
	case 1://左右移動
		if (Input::GetVKey(VK_LEFT) == true)
			cond1 = true;
		if (Input::GetVKey(VK_RIGHT) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 2://ジャンプ
		if (condreset == true)
		{
			cond1 = false; cond2 = false;
			condreset = false;
		}

		if (Input::GetVKey(' ') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 3://攻撃
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('F') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 4://スキル変更
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey(VK_UP) == true)
			cond1 = true;
		if (Input::GetVKey(VK_DOWN) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 5://回復
		if (condreset == true)
		{
			cond1 = false; cond2 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 1)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 6://バリア
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 2)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	case 7://メテオ
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
		}

		if (Input::GetVKey('D') == true && m_skill == 3)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
		break;
	default:
		break;
	}
}

//ドロー
void CTutorial::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	wchar_t str[128];

	switch (Order)
	{
	case 1:
		swprintf_s(str, L"条件1");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 2:
		swprintf_s(str, L"条件2");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 3:
		swprintf_s(str, L"条件3");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 4:
		swprintf_s(str, L"条件4");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 5:
		swprintf_s(str, L"条件5");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 6:
		swprintf_s(str, L"条件6");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 7:
		swprintf_s(str, L"条件7");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	case 8:
		swprintf_s(str, L"終わり");//整数を文字列か
		Font::StrDraw(str, 150, 336, 36, c);
		break;
	}
	
}