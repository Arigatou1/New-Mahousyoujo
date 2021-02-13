//使用するヘッダーファイル
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\Audio.h"
#include "GameL\UserData.h"
#include "GameHead.h"
#include "Tutorial.h"


//使用するネームスペース
using namespace GameL;


//イニシャライズ
void CTutorial::Init()
{

	cond1 = false;
	cond2 = false;

	condreset = false;

	Order = 1;

	//チュートリア主人公オブジェクト作成
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

	if      (Order == 1)//左右移動
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
	else if (Order == 8)//メテオ
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
	src.m_top    =   0;
	src.m_left   = 192;
	src.m_right  = 256;
	src.m_bottom =  64;

	dst.m_top    = 100;
	dst.m_left   = 100;
	dst.m_right  = 700;
	dst.m_bottom = 430;

	Draw::Draw(0, &src, &dst, c, 0.0f);


	wchar_t str[128];

	for (int i = 0; i < 4; i++)
	{
		c[i] = 1.0f;
	}

	if (Order == 1)
	{
		swprintf_s(str, L"チュートリアルへようこそ!!");//整数を文字列か
		Font::StrDraw(str, 140, 160, 40, c);
		swprintf_s(str, L"まずは「←」・「→」キーで左右に移動してみましょう");//整数を文字列か
		Font::StrDraw(str, 145, 270, 20, c);
	}
	else if(Order == 2)
	{
		swprintf_s(str, L"次に「スペース」キーでジャンプできます");//整数を文字列か
		Font::StrDraw(str, 120, 200, 30, c);
		swprintf_s(str, L"ステージの段差や浮いている敵に有効です");//整数を文字列か
		Font::StrDraw(str, 120, 240, 30, c);
	}
	else if (Order == 3)
	{
		swprintf_s(str, L"そして「F」キーで攻撃します");//整数を文字列か
		Font::StrDraw(str, 120, 200, 30, c);
		swprintf_s(str, L"うまく間合いを取って敵を倒しましょう");//整数を文字列か
		Font::StrDraw(str, 120, 240, 30, c);
	}
	else if (Order == 4)
	{
		swprintf_s(str, L"主人公やマナは敵に当たったり");//整数を文字列か
		Font::StrDraw(str, 120, 200, 30, c);
		swprintf_s(str, L"攻撃を受けるとダメージを受けます");//整数を文字列か
		Font::StrDraw(str, 120, 240, 30, c);
	}
	else if (Order == 5)
	{
		swprintf_s(str, L"右上の魔法は");//整数を文字列か
		Font::StrDraw(str, 130, 140, 30, c);
		swprintf_s(str, L"「↑」・「↓」キーで変更ができます");//整数を文字列か
		Font::StrDraw(str, 130, 180, 30, c);
		swprintf_s(str, L"使いたい魔法に黄色の枠を合わせよう");//整数を文字列か
		Font::StrDraw(str, 130, 250, 30, c);
	}
	else if (Order == 6)
	{
		//swprintf_s(str, L"では魔法を使用してみましょう");//整数を文字列か
		//Font::StrDraw(str, 150, 140, 20, c);
		//swprintf_s(str, L"魔法は「↑」・「↓」キーで変更ができます");//整数を文字列か
		//Font::StrDraw(str, 150, 180, 20, c);
		swprintf_s(str, L"まずは一番上のヒール");//整数を文字列か
		Font::StrDraw(str, 150, 140, 30, c);
		swprintf_s(str, L"主人公の体力を3回復します");//整数を文字列か
		Font::StrDraw(str, 170, 220, 30, c);
		swprintf_s(str, L"右上の黄色の枠を合わせよう");//整数を文字列か
		Font::StrDraw(str, 300, 330, 25, c);
		swprintf_s(str, L"魔法は「D」キーで使用します");//整数を文字列か
		Font::StrDraw(str, 400, 400, 20, c);
	}
	else if (Order == 7)
	{
		//swprintf_s(str, L"魔法は「↑」・「↓」キーで変更ができます");//整数を文字列か
		//Font::StrDraw(str, 150, 140, 20, c);
		//swprintf_s(str, L"「D」キーで魔法を使用します");//整数を文字列か
		//Font::StrDraw(str, 150, 180, 20, c);
		swprintf_s(str, L"次に真ん中のバリア");//整数を文字列か
		Font::StrDraw(str, 150, 140, 30, c);
		swprintf_s(str, L"マナの周りにシールドを");//整数を文字列か
		Font::StrDraw(str, 170, 200, 30, c); 
			swprintf_s(str, L"展開して敵の攻撃を防ぎます");//整数を文字列か
		Font::StrDraw(str, 170, 240, 30, c); 
		swprintf_s(str, L"右上の黄色の枠を合わせよう");//整数を文字列か
		Font::StrDraw(str, 300, 330, 25, c);
		swprintf_s(str, L"魔法は「D」キーで使用します");//整数を文字列か
		Font::StrDraw(str, 400, 400, 20, c);
	}
	else if (Order == 8)
	{
		//swprintf_s(str, L"魔法は「↑」・「↓」キーで変更ができます");//整数を文字列か
		//Font::StrDraw(str, 150, 140, 20, c);
		//swprintf_s(str, L"「D」キーで魔法を使用します");//整数を文字列か
		//Font::StrDraw(str, 150, 180, 20, c);
		swprintf_s(str, L"最後は一番下のメテオ");//整数を文字列か
		Font::StrDraw(str, 150, 140, 30, c);
		swprintf_s(str, L"画面全体に無数の隕石で攻撃します");//整数を文字列か
		Font::StrDraw(str, 170, 220, 30, c);
		swprintf_s(str, L"右上の黄色の枠を合わせよう");//整数を文字列か
		Font::StrDraw(str, 300, 330, 25, c);
		swprintf_s(str, L"魔法は「D」キーで使用します");//整数を文字列か
		Font::StrDraw(str, 400, 400, 20, c);
	}
	else if (Order == 9)
	{
		swprintf_s(str, L"これでチュートリアルは終了です");//整数を文字列か
		Font::StrDraw(str, 160, 240, 30, c);
	}
}

void CTutorial::SkillIconsDraw(int id)
{
	RECT_F src;
	RECT_F dst;
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	//切り取り位置の設定
	src.m_top = (id*128.0f);
	src.m_left = 0.0f;
	src.m_right = 128.0f;
	src.m_bottom = src.m_top+128.0f;

	//表示位置の設定
	dst.m_top = 100.0f;
	dst.m_left = 100.0f;
	dst.m_right = dst.m_left + 96.0f;
	dst.m_bottom = dst.m_top + 96.0f;

	//描画
	Draw::Draw(10, &src, &dst, c, 0.0f);
}