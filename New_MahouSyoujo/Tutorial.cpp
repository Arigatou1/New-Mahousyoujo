//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

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
}

//アクション
void CTutorial::Action()
{
	switch (Order)
	{
	case 1:
		if (Input::GetVKey(VK_LEFT) == true)
			cond1 = true;
		if (Input::GetVKey(VK_RIGHT) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
			Order++;
		break;
	case 2:
		cond1 = false; cond2 = false;

		if (Input::GetVKey(' ') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 3:
		cond1 = false;

		if (Input::GetVKey('F') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 4:
		cond1 = false;

		if (Input::GetVKey(VK_UP) == true)
			cond1 = true;
		if (Input::GetVKey(VK_DOWN) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
			Order++;
		break;
	case 5:
		cond1 = false; cond2 = false;

		if (Input::GetVKey('D') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 6:
		cond1 = false;

		if (Input::GetVKey('D') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	case 7:
		cond1 = false;

		if (Input::GetVKey('D') == true)
			cond1 = true;

		if (cond1 == true)
			Order++;
		break;
	default:
		break;
	}
}

//ドロー
void CTutorial::Draw()
{

}