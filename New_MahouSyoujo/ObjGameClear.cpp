//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "GameL\UserData.h"
#include "ObjGameClear.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjGameClear::Init()
{
	StageID = ((UserData*)Save::GetData())->Stage;
	((UserData*)Save::GetData())->Clear_Flag[StageID+1] = true;

	Score = 0;
}

//�A�N�V����
void CObjGameClear::Action()
{

	//�X�R�A���v�Z
	///�����炭�A�����̏����Ńo�O���������Ă��邱�Ƃ�����������ŁA
	/// ���������Ă������Ƃɂ���B
	/// �������A�X�R�A�̏�񂾂��łȂ��A�N���A�t���O�̏��܂ł���������ŏ����Ă��܂��̂�
	/// �Ȃ����낤���H
	//((UserData*)Save::GetData())->Score =
	//	(((UserData*)Save::GetData())->HeroHP * 40 + ((UserData*)Save::GetData())->ManaHP * 60);


	//�ǋL
	//���܂���������������Ȃ��B

    Score =	(30-((UserData*)Save::GetData())->HeroHP)*40 + ((UserData*)Save::GetData())->ManaHP*60;



	//��������ۑ�
	//�����͖��Ȃ������B
	if(((UserData*)Save::GetData())->ScoreData[StageID]<Score)
	{
		((UserData*)Save::GetData())->ScoreData[StageID] = Score;
	}

	
					

	//�G���^�[�L�[�������ăV�[��:�Q�[��Menu�Ɉڍs����
		if (Input::GetVKey(VK_RETURN) == true)
		{
			if (m_key_flag == true)
			{
				Scene::SetScene(new CSceneMenu());
				m_key_flag = false;
			}
		}

		else
		{
			m_key_flag = true;
		}
}

//�h���[
void CObjGameClear::Draw()
{
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	Font::StrDraw(L"GAME CLEAR!", 200, 200, 96, c);


	

	wchar_t str[128];
	swprintf_s(str, L"�X�R�A:%.0f", Score);//�����𕶎���
	Font::StrDraw(str, 300, 2, 24, c);

}