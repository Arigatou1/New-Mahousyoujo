//�g�p����w�b�_�[�t�@�C��
#include "GameL\WinInputs.h"
#include "GameL\DrawFont.h"
#include "GameL\SceneManager.h"

#include "GameHead.h"
#include "GameL\UserData.h"
#include "ObjEndlessResult.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

//�C�j�V�����C�Y
void CObjEndlessResult::Init()
{
	
	Score = 0;
	m_key_flag = false;
}

//�A�N�V����
void CObjEndlessResult::Action()
{

	//�X�R�A���v�Z
	
	Score = ((UserData*)Save::GetData())->HeroHP;


	//��������ۑ�
	//�����͖��Ȃ������B
	if (((UserData*)Save::GetData())->ScoreData[16] < Score)
	{
		((UserData*)Save::GetData())->ScoreData[16] = Score;
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
void CObjEndlessResult::Draw()
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

	swprintf_s(str, L"�X�R�A:%.0f", Score);//�����𕶎���
	Font::StrDraw(str, 240, 412, 72, c);


}