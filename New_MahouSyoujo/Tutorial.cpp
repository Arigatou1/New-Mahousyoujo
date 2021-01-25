//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"

#include "GameL\UserData.h"
#include "GameHead.h"
#include "Tutorial.h"
#include "GameL\Audio.h"

//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CTutorial::Init()
{

	cond1 = false;
	cond2 = false;

	condreset = false;

	Order = 1;

	//チュートリアる主人公オブジェクト作成
	TutorialHero* obj = new TutorialHero();
	Objs::InsertObj(obj, OBJ_TUTORIALHERO, 60);

	shootDownTime = 0;
}

//アクション
void CTutorial::Action()
{
	CObjMagicalGirl* obj_magicalgirl = (CObjMagicalGirl*)Objs::GetObj(OBJ_MAGICALGIRL);
	if (obj_magicalgirl != nullptr)
	{
		m_skill = obj_magicalgirl->GetSkill();
	}

	if (Order == 1)//左右移動
	{
		
		if (Input::GetVKey(VK_LEFT) == true)
			cond1 = true;
		if (Input::GetVKey(VK_RIGHT) == true)
			cond2 = true;

		if (cond1 == true && cond2 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 2)//ジャンプ
	{
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
	}
	else if (Order == 3)//攻撃
	{
		if (condreset == true)
		{
			cond1 = false;
			condreset = false;
			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
		}

		if (Input::GetVKey('F') == true)
			cond1 = true;

		if (cond1 == true)
		{
			Order++;
			condreset = true;
		}
	}
	else if (Order == 4)
	{
		TutorialHero* obj_tutorialhero = (TutorialHero*)Objs::GetObj(OBJ_TUTORIALHERO);
		if (obj_tutorialhero != nullptr)
		{
			Time = obj_tutorialhero->GetTime();
		}

		if (Time >= 400)
			Order++;
	}
	else if (Order == 5)//スキル変更
	{
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
	}
	else if (Order == 6)//ヒール
	{
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
	}
	else if (Order == 7)//バリア
	{
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
	}
	else if(Order == 8)//メテオ
	{
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
	}
	else if (Order == 9)
	{
	((UserData*)Save::GetData())->tutorialDone = true;
	Save::Seve();
	//HPがゼロになったら、待機時間を増価させる。
	shootDownTime++;

	if (shootDownTime == 1)
	{
		
		Audio::Start(13);
		
	}
	else if (shootDownTime == 200)
	{
		//EnemyAppear
		Fadeout* obj_Fadeout = new Fadeout();
		Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
	}

	else if (shootDownTime == 300)
	{
		Scene::SetScene(new CSceneMenu());
	}
	}
}

//ドロー
void CTutorial::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,0.9f };

	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = 192;
	src.m_right = 256;
	src.m_bottom = 64;

	dst.m_top = 100;
	dst.m_left = 100;
	dst.m_right = 700;
	dst.m_bottom = 300;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	wchar_t str[128];

	for (int i = 0; i < 4; i++)
	{
		c[i] = 1.0f;
	}

	if (Order == 1)
	{
		swprintf_s(str, L"「←」・「→」キーで左右に移動できます");//整数を文字列か
		Font::StrDraw(str, 200, 200, 20, c);
	}
	else if(Order == 2)
	{
		swprintf_s(str, L"「スペース」キーでジャンプできます");//整数を文字列か
		Font::StrDraw(str, 250, 200, 20, c);
	}
	else if (Order == 3)
	{
		swprintf_s(str, L"「F」キーで攻撃します");//整数を文字列か
		Font::StrDraw(str, 300, 200, 20, c);
	}
	else if (Order == 4)
	{
		swprintf_s(str, L"[?]");//整数を文字列か
		Font::StrDraw(str, 300, 200, 20, c);
	}
	else if (Order == 5)
	{
		swprintf_s(str, L"「↑」・「↓」キーで魔法の変更ができます");//整数を文字列か
		Font::StrDraw(str, 200, 200, 20, c);
	}
	else if (Order == 6)
	{
		swprintf_s(str, L"「D」キーで魔法ヒール");//整数を文字列か
		Font::StrDraw(str, 350, 200, 20, c);
	}
	else if (Order == 7)
	{
		swprintf_s(str, L"「D」キーで魔法バリア");//整数を文字列か
		Font::StrDraw(str, 350, 200, 20, c);
	}
	else if (Order == 8)
	{
		swprintf_s(str, L"「D」キーで魔法メテオ");//整数を文字列か
		Font::StrDraw(str, 350, 200, 20, c);
	}
	else if (Order == 9)
	{
		swprintf_s(str, L"終わり");//整数を文字列か
		Font::StrDraw(str, 350, 200, 20, c);
	}
}