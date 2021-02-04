//�g�p����w�b�_�[�t�@�C��
#include "GameL\DrawTexture.h"
#include "GameL\WinInputs.h"

#include "GameHead.h"
#include "ObjBackGround.h"
#include "GameL\MultiThread.h"

//�g�p����l�[���X�y�[�X
using namespace GameL;

/// <summary>
/// �E�B���h�E�̉����A�c���͂��ꂼ��800x600�B
/// </summary>
/// <param name="id"></param>
CObjBackGround::CObjBackGround(int id)
{
	BackGroundID = id;
}
//�C�j�V�����C�Y
void CObjBackGround::Init()
{
	wchar_t bgid[128];

	swprintf_s(bgid, L"BackGrounds/bg_%02d.png", BackGroundID);

	Draw::LoadImageW(bgid, BackGroundID + 50, TEX_SIZE_512);
}

//�A�N�V����
void CObjBackGround::Action()
{


}

//�h���[
void CObjBackGround::Draw()
{
	//�`��J���[���
	float c[4] = { 1.0f,1.0f,1.0f,1.0f };

	RECT_F src;//�`�挳�؂���ʒu
	RECT_F dst;//�`���\���ʒu


	//�؂���ʒu�̐ݒ�
	src.m_top = 0.0f;
	src.m_left = 0.0f;
	src.m_right = 800.0f;
	src.m_bottom = 600.0f;
	//�\���ʒu�̐ݒ�
	dst.m_top = 0.0f;
	dst.m_left = 0.0f;
	dst.m_right = 800.0f;
	dst.m_bottom = 600.0f;


	//�`��
	Draw::Draw(50 + BackGroundID, &src, &dst, c, 0.0f);
}