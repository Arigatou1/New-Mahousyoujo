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
	HeroDamage = 0;
	ManaDamage = 0;
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
	ManaDamage = ((UserData*)Save::GetData())->ManaHP;
	HeroDamage = ((UserData*)Save::GetData())->HeroHP;

	//�ǋL
	//���܂���������������Ȃ��B

    Score =	(4000-HeroDamage*80) + (6000-ManaDamage*60);










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
	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu

	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 960.0f;
	src.m_bottom = 600.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 500.0f;
	//�`��
	Draw::Draw(0, &src, &dst, c, 0.0f);

	wchar_t str[128];
	
	swprintf_s(str, L"�v���C���[���󂯂��_���[�W:%.2f", HeroDamage);//�����𕶎���
	Font::StrDraw(str, 150, 372, 36, c);

	swprintf_s(str, L"�}�i���󂯂��_���[�W:%.2f", ManaDamage);//�����𕶎���
	Font::StrDraw(str, 150, 420, 36, c);
	
	swprintf_s(str, L"�X�R�A:%.0f", Score);//�����𕶎���
	Font::StrDraw(str, 300, 512, 72, c);

	
	swprintf_s(str, L"10000 - %.2f�~80 - %.2f�~60 =", HeroDamage,ManaDamage);//�����𕶎���
	Font::StrDraw(str, 50, 480, 18, c);
	
	
}