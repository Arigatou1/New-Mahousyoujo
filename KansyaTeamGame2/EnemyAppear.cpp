//使用するヘッダーファイル
#include "GameL/DrawTexture.h"
#include "GameHead.h"
#include "GameL\HitBoxManager.h"
#include "GameL/SceneObjManager.h"
#include "EnemyAppear.h"
#include "GameL\UserData.h"
#include "GameL\DrawFont.h"


//使用するネームベース
using namespace GameL;


//イニシャライズ
void EnemyAppear::Init()
{
	m_time = 0;
	//e_num = 0;
	int StageID = ((UserData*)Save::GetData())->Stage + 1;

	switch (StageID)
	{
	case 1:
		((UserData*)Save::GetData())->enemyRemain = 21;
	case 2:
		((UserData*)Save::GetData())->enemyRemain = 39;
	default:
		((UserData*)Save::GetData())->enemyRemain = 999;
	}
}

//アクション
void EnemyAppear::Action()
{
	//時間経過
	//代入し続ける?させない方法はある？
	int StageID = ((UserData*)Save::GetData())->Stage + 1;


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

				
				default:
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