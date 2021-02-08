//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"
#include "GameL/Audio.h"

#include "GameHead.h"
#include "ObjEnemyAmount.h"
#include "GameL\UserData.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEnemyAmount::Init()
{
	EnemyAmount = 0;
	shootDownTime = 0;
}

//�A�N�V����
void CObjEnemyAmount::Action()
{
	if (((UserData*)Save::GetData())->enemyRemain==0 && ((UserData*)Save::GetData())->HPZeroCheck==false)
	{
		//HP���[���ɂȂ�����A�ҋ@���Ԃ𑝉�������B
		shootDownTime++;
	
		if (shootDownTime == 1)
		{
			/// <summary>
			///		�V�[�����C���̃��[�h�𑁂��I��点�邽�߂ɕς��������B
			/// �������邵���Ȃ�������__________
			/// </summary>
			switch (((UserData*)Save::GetData())->Stage + 1)
			{
			case 1:
				Audio::Stop(14);
				break;
			case 2:
			case 3:
			case 4:
				Audio::Stop(15);
				break;
			case 5:
			case 6:
				Audio::Stop(17);
				break;
			case 7:
				Audio::Stop(18);
				break;
			case 8:
				Audio::Stop(19);
				break;
			default:
				break;
			}
			Audio::Stop(16);
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
			Scene::SetScene(new CSceneGameClear());
		}
	}
}



//�h���[
void CObjEnemyAmount::Draw()
{
	float c[4] = { 0.0f,0.0f,0.0f,1.0f };
	wchar_t str[128];




	swprintf_s(str, L"�c��G�̐�:%d", ((UserData*)Save::GetData())->enemyRemain);//�����𕶎���
	
	//swprintf_s(str, L"�X�R�A:%d", ((UserData*)Save::GetData())->Score);//�����𕶎���
	
	//-1�ȉ��̎��ȊO�\������
	if(((UserData*)Save::GetData())->enemyRemain>=0)
	Font::StrDraw(str, 2, 96, 24, c);


	RECT_F src;
	RECT_F dst;
	src.m_top = 0;
	src.m_left = 192;
	src.m_right =256;
	src.m_bottom =64;

	dst.m_top = 560;
	dst.m_left = 0;
	dst.m_right = 800;
	dst.m_bottom = 600;

	Draw::Draw(0, &src, &dst, c, 0.0f);

	for (int i = 0; i < 3; i++)
	{
		c[i] = 1.0f;
	}

	swprintf_s(str, L"������@:�����ړ��@�������@�؂�ւ� �@Space:�W�����v  F�U��  D���@");//�����𕶎���
	Font::StrDraw(str, 2, 566, 24, c);

}