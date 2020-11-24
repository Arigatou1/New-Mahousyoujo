//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "EnemyAppear.h"
#include "GameL\UserData.h"
#include "GameL\DrawFont.h"
#include "GameL/WinInputs.h"


//使用するネームベース
using namespace GameL;


//イニシャライズ
void EnemyAppear::Init()
{
	m_time = 0;
	//e_num = 0;
	StageID = ((UserData*)Save::GetData())->Stage + 1;
	

	switch (StageID)
	{
	case 1:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(1);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 21;
		break;
	}
	case 2:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(3);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 38;
		break;
	}
	case 3:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(3);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 32;
		break;
	}
	case 4:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(2);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 99;
		break;
	}
	case 5:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(5);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 36;
		break;
	}
	case 6:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(5);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 45;
		break;
	}
	case 7:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(8);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 49;
		break;
	}
	case 8:
	{
		//背景オブジェクト作成
		CObjBackGround* obj_bg = new CObjBackGround(9);
		Objs::InsertObj(obj_bg, OBJ_BG, 1);

		((UserData*)Save::GetData())->enemyRemain = 99;
		break;
	}
	default:
	{

		((UserData*)Save::GetData())->enemyRemain = 99;
		break;
	}
	}

	m_key_flag = false;
}

//アクション
void EnemyAppear::Action()
{
	//時間経過
	m_time++;
	switch (StageID)
	{


	case 1:
	{
		

		if (m_time == 100)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

			//e_num++;

		}

		else if (m_time == 200)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			//e_num++;
		}
		else if (m_time == 350)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 400)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 500)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 600)
		{

			CObjEnemy* obj = new CObjEnemy(799, 194);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 650)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 750)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 800)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);


		}
		else if (m_time == 850)
		{

			CObjEnemy* obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 950)
		{

			CObjEnemy* obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 1050)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 1100)
		{

			CObjEnemy2* obj = new CObjEnemy2(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		else if (m_time == 1200)
		{

			CObjEnemy2* obj = new CObjEnemy2(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}
		else if (m_time == 1300)
		{

			CObjEnemy2* obj = new CObjEnemy2(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		else if (m_time == 1600)
		{

			CObjEnemy* obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1650)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1700)
		{

			CObjEnemy* obj = new CObjEnemy(799, 190);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1750)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 2100)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		break;
	}

	case 2:
	{
		if (m_time == 100)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 200)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 300)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 500)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 600)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 700)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 900)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 950)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1000)
		{

			CObjEnemy* obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1050)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1150)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			obj = new CObjEnemy(799, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 1250)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			

		}

		else if (m_time == 1300)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			

		}

		else if (m_time == 1350)
		{

			CObjEnemy* obj = new CObjEnemy(1, 480);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			

		}
		else if (m_time == 1400)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);


		}
		else if (m_time == 1450)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);


		}
		else if (m_time == 1500)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);


		}
		else if (m_time == 1600)
		{

		CObjEnemy2* obj = new CObjEnemy2(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		obj = new CObjEnemy2(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);


		}

		else if (m_time == 1700)
		{

		CObjEnemy2* obj = new CObjEnemy2(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		obj = new CObjEnemy2(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);


		}

		else if (m_time == 1800)
		{

		CObjEnemy* obj = new CObjEnemy(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1850)
		{

		CObjEnemy* obj = new CObjEnemy(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
		obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1900)
		{

		CObjEnemy2* obj = new CObjEnemy2(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);
		obj = new CObjEnemy2(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		else if (m_time == 2200)
		{

		CObjEnemy* obj = new CObjEnemy(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);
	
		}
		else if (m_time == 2240)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 2280)
		{

		CObjEnemy* obj = new CObjEnemy(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 2320)
		{

		CObjEnemy* obj = new CObjEnemy(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 2360)
		{

		CObjEnemy2* obj = new CObjEnemy2(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		obj = new CObjEnemy2(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		else if (m_time == 2400)
		{

		CObjEnemy2* obj = new CObjEnemy2(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		obj = new CObjEnemy2(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}

		else if (m_time == 2440)
		{

		CObjEnemy2* obj = new CObjEnemy2(799, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		obj = new CObjEnemy2(1, 480);
		Objs::InsertObj(obj, OBJ_ENEMY2, 49);

		}
		break;
	}

		case 3:
		{
			if (m_time == 100)
			{

				CObjEnemy* obj = new CObjEnemy(-63,350);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 160)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 350);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 220)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 350);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}

			else if (m_time == 340)
			{

				CObjEnemy3* obj = new CObjEnemy3(-63, 350);
				Objs::InsertObj(obj, OBJ_ENEMY3, 49);

			}
			else if (m_time == 400)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 170);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 460)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 170);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 520)
			{

				CObjEnemy2* obj = new CObjEnemy2(-63, 170);
				Objs::InsertObj(obj, OBJ_ENEMY2, 49);
				obj = new CObjEnemy2(-63, 350);
				Objs::InsertObj(obj, OBJ_ENEMY2, 49);

			}
			else if (m_time == 560)
			{

				CObjEnemy* obj = new CObjEnemy(799, 170);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}

			else if (m_time == 680)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 170);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 710)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 350);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 740)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 170);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 770)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 350);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 800)
			{

				CObjEnemy* obj = new CObjEnemy(-63, 170);
				Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}

			else if (m_time == 860)
			{

				CObjEnemy2* obj = new CObjEnemy2(799, 170);
				Objs::InsertObj(obj, OBJ_ENEMY2, 49);

			}
			else if (m_time == 920)
			{

			CObjEnemy3* obj = new CObjEnemy3(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY3, 49);

			}

			else if (m_time == 1040)
			{

			CObjEnemy* obj = new CObjEnemy(-63, 170);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 1080)
			{

			CObjEnemy* obj = new CObjEnemy(799, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}

			else if (m_time == 1200)
			{

			CObjEnemy* obj = new CObjEnemy(-63, 170);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

			}
			else if (m_time == 1260)
			{

			CObjEnemy* obj = new CObjEnemy(-63, 170);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			CObjEnemy2* obj2 = new CObjEnemy2(-63, 350);
			Objs::InsertObj(obj2, OBJ_ENEMY2, 49);

			}
			else if (m_time == 1380)
			{

			CObjEnemy3* obj = new CObjEnemy3(-63, 170);
			Objs::InsertObj(obj, OBJ_ENEMY3, 49);
			

			}
			else if (m_time == 1440)
			{

			CObjEnemy3* obj = new CObjEnemy3(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY3, 49);


			}
			else if (m_time == 1560)
			{

			CObjEnemy* obj = new CObjEnemy(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			obj = new CObjEnemy(-63, 170);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);


			}
			else if (m_time == 1620)
			{

			CObjEnemy* obj = new CObjEnemy(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			obj = new CObjEnemy(-63, 170);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);


			}
			else if (m_time == 1680)
			{

			CObjEnemy* obj = new CObjEnemy(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);
			obj = new CObjEnemy(-63, 170);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);


			}
			else if (m_time == 1780)
			{

				CObjEnemy2* obj = new CObjEnemy2(799, 350);
				Objs::InsertObj(obj, OBJ_ENEMY2, 49);
				obj = new CObjEnemy2(-63, 350);
				Objs::InsertObj(obj, OBJ_ENEMY2, 49);
			}

			else if (m_time == 2000)
			{

			CObjEnemy3* obj = new CObjEnemy3(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY3, 49);
			}
			break;
		}
				case 4:
				{
					if (m_time == 100)
					{

						CObjEnemy* obj = new CObjEnemy(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}
					else if (m_time == 160)
					{

						CObjEnemy* obj = new CObjEnemy(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}
					else if (m_time == 220)
					{

						CObjEnemy* obj = new CObjEnemy(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}
					else if (m_time == 270)
					{

						CObjEnemy2* obj = new CObjEnemy2(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}
					else if (m_time ==370)
					{

						CObjEnemy3* obj = new CObjEnemy3(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY3, 49);

					}
					else if (m_time == 770)
					{

						CObjBoss1* obj = new CObjBoss1(576, 192);
						Objs::InsertObj(obj, OBJ_BOSS1, 49);

					}
					break;
				}

				case 5:
				{
					if (m_time == 100)
					{

						CObjEnemy* obj = new CObjEnemy(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 140)
					{

						CObjEnemy* obj = new CObjEnemy(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 180)
					{

						CObjEnemy* obj = new CObjEnemy(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 300)
					{

						CObjEnemy3* obj = new CObjEnemy3(799, 350);
						Objs::InsertObj(obj, OBJ_ENEMY3, 49);

					}
					else if (m_time == 400)
					{

						CObjEnemy2* obj = new CObjEnemy2(640, -64);
						Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}
					else if (m_time == 460)
					{

						CObjEnemy2* obj = new CObjEnemy2(640, -64);
						Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}
					else if (m_time == 520)
					{

						CObjEnemy2* obj = new CObjEnemy2(-63, 400);
						Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}
					else if (m_time == 620)
					{

						CObjEnemy* obj = new CObjEnemy(-63, 400);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);
						obj = new CObjEnemy(799, 400);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}
					
						
					else if (m_time == 740)
					{

						CObjEnemy3* obj = new CObjEnemy3(640, -64);
						Objs::InsertObj(obj, OBJ_ENEMY3, 49);

					}

					else if (m_time == 780)
					{

						CObjEnemy* obj = new CObjEnemy(799, 400);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 900)
					{

						CObjEnemy* obj = new CObjEnemy(799, 400);
						Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}
					else if (m_time == 1030)
					{

						CObjEnemy2* obj = new CObjEnemy2(799, 400);
						Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}
					else if (m_time == 1130)
					{

						CObjEnemy2* obj = new CObjEnemy2(640, -64);
						Objs::InsertObj(obj, OBJ_ENEMY3, 49);

					}
					else if (m_time == 1250)
					{

						CObjEnemy2* obj = new CObjEnemy2(640, -64);
						Objs::InsertObj(obj, OBJ_ENEMY3, 49);

					}

					else if (m_time == 1350)
					{

					CObjEnemy3* obj = new CObjEnemy3(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY3, 49);

					}

					else if (m_time == 1470)
					{

					CObjEnemy* obj = new CObjEnemy(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}
					else if (m_time == 1560)
					{

					CObjEnemy* obj = new CObjEnemy(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);
					CObjEnemy3* obj3 = new CObjEnemy3(-63, 400);
					Objs::InsertObj(obj3, OBJ_ENEMY3, 49);

					}
					else if (m_time == 1620)
					{

					CObjEnemy2* obj = new CObjEnemy2(640, -64);
					Objs::InsertObj(obj, OBJ_ENEMY2, 49);
				
					}

					else if (m_time == 1680)
					{

					CObjEnemy* obj = new CObjEnemy(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 1800)
					{

					CObjEnemy* obj = new CObjEnemy(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);
					obj = new CObjEnemy(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 1880)
					{

					CObjEnemy* obj = new CObjEnemy(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);
					obj = new CObjEnemy(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 1900)
					{

					CObjEnemy3* obj = new CObjEnemy3(640,-64);
					Objs::InsertObj(obj, OBJ_ENEMY3, 49);

					}

					else if (m_time ==2000)
					{

					CObjEnemy* obj = new CObjEnemy(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);
					obj = new CObjEnemy(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 2080)
					{

					CObjEnemy2* obj = new CObjEnemy2(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY2, 49);
					obj = new CObjEnemy2(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}

					else if (m_time == 2160)
					{

					CObjEnemy* obj = new CObjEnemy(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);
					obj = new CObjEnemy(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY, 49);

					}

					else if (m_time == 2220)
					{

					CObjEnemy2* obj = new CObjEnemy2(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY2, 49);
					obj = new CObjEnemy2(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}

					else if (m_time == 2280)
					{

					CObjEnemy2* obj = new CObjEnemy2(799, 400);
					Objs::InsertObj(obj, OBJ_ENEMY2, 49);
					obj = new CObjEnemy2(-63, 400);
					Objs::InsertObj(obj, OBJ_ENEMY2, 49);

					}



					break;
				}

	case 6:
	{
		if (m_time == 100)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 125)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 200)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 225)
		{	

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 250)
		{

		CObjEnemy* obj = new CObjEnemy(799, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 300)
		{

		CObjEnemy* obj = new CObjEnemy(799, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 350)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 375)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 400)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 450)
		{

			CObjEnemy2* obj_2 = new CObjEnemy2(799, 350);
			Objs::InsertObj(obj_2, OBJ_ENEMY2, 49);

		}
		else if (m_time == 500)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);
		obj_4 = new CObjSmallSlim(0, 300);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 525)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(0, 300);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 550)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 600)
		{

		CObjEnemy* obj = new CObjEnemy(799, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 650)
		{

		CObjEnemy2* obj_2 = new CObjEnemy2(799, 350);
		Objs::InsertObj(obj_2, OBJ_ENEMY2, 49);

		}
		else if (m_time == 700)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 725)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 750)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 775)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 800)
		{

		CObjEnemy* obj = new CObjEnemy(799, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 950)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 975)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1000)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);
		obj_4 = new CObjSmallSlim(0, 300);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1025)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(0, 300);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1050)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);
		obj_4 = new CObjSmallSlim(0, 300);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time ==1100)
		{

		CObjEnemy2* obj_2 = new CObjEnemy2(799, 350);
		Objs::InsertObj(obj_2, OBJ_ENEMY2, 49);

		}
		else if (m_time == 1250)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1275)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1300)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);
		obj_4 = new CObjSmallSlim(0, 300);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1325)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1335)
		{

		CObjEnemy* obj = new CObjEnemy(799, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1350)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1375)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1400)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1425)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1500)
		{

		CObjSmallSlim* obj_4 = new CObjSmallSlim(799, 350);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);
		obj_4 = new CObjSmallSlim(0, 300);
		Objs::InsertObj(obj_4, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1550)
		{

		CObjEnemy* obj = new CObjEnemy(799, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1600)
		{

		CObjEnemy2* obj_2 = new CObjEnemy2(799, 350);
		Objs::InsertObj(obj_2, OBJ_ENEMY2, 49);

		}
		else if (m_time == 1650)
		{

		CObjEnemy* obj = new CObjEnemy(799, 350);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1700)
		{

		CObjEnemy2* obj_2 = new CObjEnemy2(799, 350);
		Objs::InsertObj(obj_2, OBJ_ENEMY2, 49);

		}

		break;
	}

	case 7:
	{
		if (m_time == 100)
		{

			CObjEnemy* obj = new CObjEnemy(799, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 150)
		{

			CObjEnemy* obj = new CObjEnemy(799, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 200)
		{

			CObjEnemy* obj = new CObjEnemy(799, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 250)
		{

			CObjEnemy* obj = new CObjEnemy(799, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if(m_time==350)
		{

			CObjEnemy* obj = new CObjEnemy(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 400)
		{

			CObjEnemy* obj = new CObjEnemy(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 450)
		{

			CObjEnemy* obj = new CObjEnemy(-63, 350);
			Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 550)
		{

			CObjEnemy3* obj = new CObjEnemy3(-63, 300);
			Objs::InsertObj(obj, OBJ_ENEMY3, 49);
			obj = new CObjEnemy3(799, 300);
			Objs::InsertObj(obj, OBJ_ENEMY3, 49);

		}
		else if (m_time == 750)
		{

			CObjEnemy4* obj = new CObjEnemy4(799, 300);
			Objs::InsertObj(obj, OBJ_ENEMY4, 49);
			

		}
		else if (m_time == 950)
		{

			CObjEnemy2* obj = new CObjEnemy2(-63, 300);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);
			obj = new CObjEnemy2(799, 300);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);


		}
		else if (m_time == 1000)
		{

			CObjEnemy2* obj = new CObjEnemy2(-63, 300);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);
			obj = new CObjEnemy2(799, 300);
			Objs::InsertObj(obj, OBJ_ENEMY2, 49);


		}
		else if (m_time == 1100)
		{

			CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
			Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
			

		}
		else if (m_time == 1125)
		{

			CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
			Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);


		}
		else if (m_time == 1150)
		{

		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);


		}
		else if (m_time == 1175)
		{

		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);


		}
		else if (m_time == 1175)
		{

		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);


		}
		else if (m_time == 1200)
		{

		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);


		}
		else if (m_time == 1225)
		{

		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);


		}
		else if (m_time == 1250)
		{

		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		CObjEnemy* obj2 = new CObjEnemy(799, 350);
		Objs::InsertObj(obj2, OBJ_ENEMY, 49);


		}
		else if (m_time == 1350)
		{
		CObjEnemy* obj2 = new CObjEnemy(799, 350);
		Objs::InsertObj(obj2, OBJ_ENEMY, 49);

		}
		else if (m_time == 1390)
		{
		CObjEnemy2* obj2 = new CObjEnemy2(799, 350);
		Objs::InsertObj(obj2, OBJ_ENEMY2, 49);
		obj2 = new CObjEnemy2(-63, 350);
		Objs::InsertObj(obj2, OBJ_ENEMY2, 49);
		}
		else if (m_time == 1490)
		{
		CObjEnemy4* obj = new CObjEnemy4(799, 300);
		Objs::InsertObj(obj, OBJ_ENEMY4, 49);
		
		}
		else if (m_time == 1600)
		{
		CObjEnemy* obj = new CObjEnemy(799, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1700)
		{
		CObjEnemy4* obj = new CObjEnemy4(-63, 300);
		Objs::InsertObj(obj, OBJ_ENEMY4, 49);

		}
		else if (m_time == 1800)
		{
		CObjEnemy* obj = new CObjEnemy(799, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}
		else if (m_time == 1850)
		{
		CObjEnemy* obj = new CObjEnemy(799, 300);
		Objs::InsertObj(obj, OBJ_ENEMY, 49);

		}

		else if (m_time == 1950)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 1975)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 2000)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 2025)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 2075)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		CObjEnemy4* obj2 = new CObjEnemy4(799, 300);
		Objs::InsertObj(obj2, OBJ_ENEMY4, 49);


		}
		else if (m_time == 2100)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 2125)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 2175)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 2200)
		{
		CObjSmallSlim* obj = new CObjSmallSlim(799, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
		obj = new CObjSmallSlim(-63, 300);
		Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);

		}
		else if (m_time == 2300)
		{
		CObjEnemy4* obj = new CObjEnemy4(-63, 300);
		Objs::InsertObj(obj, OBJ_ENEMY4, 49);

		}
		break;
	}
	case 8:
	{
		if (m_time == 100)
		{

			CObjDragon* obj = new CObjDragon(576, 192);
			Objs::InsertObj(obj, OBJ_DRAGON, 49);

		}
		break;
	}
				default:
				{
					
					if (Input::GetVKey('1') == true)
					{
						if (m_key_flag == true)
						{
							CObjEnemy* obj = new CObjEnemy(0, 0);
							Objs::InsertObj(obj, OBJ_ENEMY, 49);
							m_key_flag = false;
						}
					}
					else if (Input::GetVKey('2') == true)
					{
						if (m_key_flag == true)
						{
							CObjEnemy2* obj = new CObjEnemy2(0, 0);
							Objs::InsertObj(obj, OBJ_ENEMY2, 49);
							m_key_flag = false;
						}
					}
					else if (Input::GetVKey('3') == true)
					{
						if (m_key_flag == true)
						{
							CObjEnemy3* obj = new CObjEnemy3(0, 0);
							Objs::InsertObj(obj, OBJ_ENEMY3, 49);
							m_key_flag = false;
						}
					}
					else if (Input::GetVKey('4') == true)
					{
						if (m_key_flag == true)
						{
							CObjEnemy4* obj = new CObjEnemy4(0, 0);
							Objs::InsertObj(obj, OBJ_ENEMY4, 49);
							m_key_flag = false;
						}
					}
					else if (Input::GetVKey('5') == true)
					{
						if (m_key_flag == true)
						{
							CObjSmallSlim* obj = new CObjSmallSlim(0, 0);
							Objs::InsertObj(obj, OBJ_SMALLSLIM, 49);
							m_key_flag = false;
						}
					}
					else
					{
						m_key_flag = true;
					}
					break;
				}
	}
}

//ドロー
void EnemyAppear::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];
	
	swprintf_s(str, L"タイム:%d", m_time);//整数を文字列か

	Font::StrDraw(str, 2, 120, 24, c);
}

//int EnemyAppear::GetNUM()
//{
//	return e_num;
//}