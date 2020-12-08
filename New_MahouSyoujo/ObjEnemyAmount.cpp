//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

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
	if (((UserData*)Save::GetData())->enemyRemain==0)
	{
		//HP���[���ɂȂ�����A�ҋ@���Ԃ𑝉�������B
		shootDownTime++;

		if (shootDownTime == 200)
		{
			//EnemyAppear
			Fadeout* obj_Fadeout = new Fadeout();
			Objs::InsertObj(obj_Fadeout, FADEOUT, 151);
		}

		else if (shootDownTime > 300)
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
	//swprintf_s(str, L"������@:�����ړ� Space�W�����v F�U�� H���@�U��");//�����𕶎���
	
	
	//swprintf_s(str, L"�X�R�A:%d", ((UserData*)Save::GetData())->Score);//�����𕶎���
	
	//-1�ȉ��̎��ȊO�\������
	if(((UserData*)Save::GetData())->enemyRemain>=0)
	Font::StrDraw(str, 2, 96, 24, c);

}