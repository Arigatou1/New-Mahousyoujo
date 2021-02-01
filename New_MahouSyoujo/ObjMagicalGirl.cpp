//使用するヘッダーファイル
#include "GameL\DrawTexture.h"
#include "GameL\DrawFont.h"
#include "GameL\WinInputs.h"
#include "GameL\SceneObjManager.h"

#include "GameHead.h"
#include "ObjMagicalGirl.h"
#include "GameL/Audio.h"

//#include <stdlib.h">

//使用するネームスペース
using namespace GameL;

//イニシャライズ
void CObjMagicalGirl::Init()
{
	m_maxmp = 100;
	m_mp =m_maxmp;//MP総量100
	
	m_postrue = 1.0f;//右向き0.0f 左向き1.0f
	m_atk_animation = 0;//0=棒立ちの画像

	m_mtime = 1;
	
	m_skill = 1;//1なら回復 2ならバリア 3なら全体

	m_key_flag = false;
}

//アクション
void CObjMagicalGirl::Action()
{
	m_mtime++;
	
	//主人公のHPとマックスHPとってくる
	CObjHero* obj_hero = (CObjHero*)Objs::GetObj(OBJ_HERO);

	CObjMana* obj_mana = (CObjMana*)Objs::GetObj(OBJ_MANA);
	if(obj_mana != nullptr)
	{
		m_gx = obj_mana->GetX();
		m_gy = obj_mana->GetY();
	}

	CTutorial* obj_tutorial = (CTutorial*)Objs::GetObj(OBJ_TUTORIAL);
	
	//(おそらく1秒に1)MP回復
	if (m_mp < 100)
	{

		if (m_mtime % 60 == 0)
		{
			//チュートリアルの時
			if (obj_tutorial != nullptr)
				m_mp += 10;
			else                          //チュートリアル以外
				m_mp++;
			m_mtime = 0;
		}
	}
	
	//キーを押すと向き変更
	if (Input::GetVKey(VK_LEFT) == true)
	{
		m_postrue = 0.0f;
	}
	else if (Input::GetVKey(VK_RIGHT) == true)
	{
		m_postrue = 1.0f;
	}

	//上下キーを押すとスキル変更
	if (Input::GetVKey(VK_UP) == true && s_t == true)
	{
		Audio::Start(1);
	
		m_skill += 1;
		s_t = false;

		if (m_skill == 4)
			{
				m_skill = 1;
			}
	}
	else if (Input::GetVKey(VK_DOWN) == true && s_t == true)
	{
		Audio::Start(1);

		m_skill -= 1;
		s_t = false;

		if (m_skill == 0)
			{
				m_skill = 3;
			}
	}
	else if(Input::GetVKey(VK_UP) == false && Input::GetVKey(VK_DOWN) == false)
	{
		s_t = true;
	}
	
	
	// 2021 01 28 舟瀬 変更----------------------------------
	m_atk_animation = 0;//棒立ちの姿になる

	if (Input::GetVKey('D') == true)
	{
		if (m_key_flag == true)
		{
			switch (m_skill)
			{
			case 1:
			
				if (obj_hero != nullptr)
				{
					//HP満タン？MPが20以上の場合
					if (m_mp >= 20 && obj_hero->GetHP() < obj_hero->GetMAXHP())
					{
						//回復魔法
						Audio::Start(22);
						m_mp -= 20;
						obj_hero->AddHP(3);
					}
				}
				break;
			case 2:
				//バリア
				if (m_mp >= 30 && (CObjBarrier*)Objs::GetObj(OBJ_BARRIER)==nullptr)
				{
					Audio::Start(23);
					//Barrierオブジェクト
					CObjBarrier* objbarrier;
					objbarrier = new CObjBarrier(m_gx + 64.0f);
					Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
					objbarrier = new CObjBarrier(m_gx - 32.0f);
					Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);

					m_mp -= 30;
				}
				break;
			case 3:
				//全体攻撃
				if (m_mp >= 50)
				{
					Audio::Start(21);
					m_mp -= 50;

					float z_x[] = { 0,700,200,500,736,100,300,600,400,64 };

					for (int i = 0; i < 10;i++ )
					{
						//魔法少女魔法玉作成
						CObjAllBullet* obj_allbullet = new CObjAllBullet(z_x[i],(i*-64)-64);//ホーミング弾作成
						Objs::InsertObj(obj_allbullet, OBJ_ALLBULLET, 60);//オブジェクトマネーに登録
					
					}
				}

				break;
			default:
				break;
			}
			m_key_flag = false;
		}

		m_atk_animation = 3;//杖持った姿になる
	}
	else
	{
		m_key_flag = true;
	}

	//----ここまで-----------------------------------------

	//魔法少女の回復魔法
	//
	//		if (Input::GetVKey('D') == true && h_t == true && m_skill == 1)
	//		{
	//			Audio::Start(22);
	//			m_atk_animation = 3;//杖持った姿になる
	//			h_t = false;
	//			m_mp -= 20;
	//			if (h_hp > 20)
	//				h_hp = 20;
	//		}
	//		else if (Input::GetVKey('D') == false)
	//		{
	//			h_t = true;
	//		}

	////魔法少女のバリア
	//if (Input::GetVKey('D') == true && b_t == true && m_skill == 2)
	//	{
	//		Audio::Start(23);
	//		m_atk_animation = 3;//杖持った姿になる
	//		m_btime = 0;
	//		b_t = false;
	//		m_mp -= 30;
	//		if (m_btime == 0)
	//		{
	//			//Barrierオブジェクト
	//			CObjBarrier* objbarrier;
	//			objbarrier = new CObjBarrier(m_gx + 64.0f);
	//			Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
	//			objbarrier = new CObjBarrier(m_gx - 32.0f);
	//			Objs::InsertObj(objbarrier, OBJ_BARRIER, 48);
	//		}
	//	}
	//	else if (Input::GetVKey('D') == false && m_btime > 300)
	//	{
	//		b_t = true;
	//	}
	//

	////魔法少女の全体攻撃
	//
	//	if (Input::GetVKey('D') == true && z_t == true && m_skill == 3)
	//	{
	//		Audio::Start(21);
	//		m_atk_animation = 3;//杖持った姿になる
	//		z_t = false;
	//		m_mp -= 50;
	//		for (int i = 0; i< 10; )
	//		{
	//			switch (i)
	//			{
	//			case 0:
	//				z_x = 0.0f;
	//				z_y = 0.0f;
	//				break;
	//			case 1:
	//				z_x = 700.0f;
	//				z_y = -64.0f;
	//				break;
	//			case 2:
	//				z_x = 200.0f;
	//				z_y = -128.0f;
	//				break;
	//			case 3:
	//				z_x = 500.0f;
	//				z_y = -192.0f;
	//				break;
	//			case 4:
	//				z_x = 736.0f;
	//				z_y = -256.0f;
	//				break;
	//			case 5:
	//				z_x = 100.0f;
	//				z_y = -320.0f;
	//				break;
	//			case 6:
	//				z_x = 300.0f;
	//				z_y = -384.0f;
	//				break;
	//			case 7:
	//				z_x = 600.0f;
	//				z_y = -448.0f;
	//				break;
	//			case 8:
	//				z_x = 400.0f;
	//				z_y = -512.0f;
	//				break;
	//			case 9:
	//				z_x = 64.0f;
	//				z_y = -576.0f;
	//				break;
	//			}
	//			//魔法少女魔法玉作成
	//			CObjAllBullet* obj_allbullet = new CObjAllBullet(z_x, z_y);//ホーミング弾作成
	//			Objs::InsertObj(obj_allbullet, OBJ_ALLBULLET, 60);//オブジェクトマネーに登録
	//			i++;
	//			if (z_x >= 800)
	//			{
	//				break;
	//			}
	//		}
	//	}
	//	else if (Input::GetVKey('D') == false)
	//	{
	//		z_t = true;
	//	}
	//

		
}

//ドロー
void CObjMagicalGirl::Draw()
{
	//描画カラー
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };
	float d[4] = { 0.0f,1.0f,0.0f,1.0f };

	RECT_F src; //描画元切り取り位置
	RECT_F dst; //描画先表示位置

	//切り取り位置の設定
	src.m_top    = 128.0f;
	src.m_left   = (m_atk_animation * 64.0f) + 0.0f;
	src.m_right  = (m_atk_animation * 64.0f) + 64.0f;
	src.m_bottom = 192.0f;

	//表示位置の設定
	dst.m_top	 =0.0f  + m_gy;
	dst.m_left   =0.0f  + (m_gx + 64.0f * m_postrue);
	dst.m_right  =64.0f + (m_gx - 64.0f * m_postrue);
	dst.m_bottom =64.0f + m_gy;

	//描画
	Draw::Draw(0,&src,&dst,c,0.0f);
}

int CObjMagicalGirl::GetMP()
{
	return m_mp;
}

int CObjMagicalGirl::GetMaxMP()
{
	return m_maxmp;
}

int CObjMagicalGirl::GetSkill()
{
	return m_skill;
}

int CObjMagicalGirl::GetHP()
{
	return h_hp;
}
