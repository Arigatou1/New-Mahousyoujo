#pragma once
//�g�p����w�b�_�[
#include "GameL\SceneObjManager.h"
//�g�p����l�[���X�y�[�X
using namespace GameL;

//�I�u�W�F�N�g�F��l��
class CObjMagicalGirl : public CObj
{
	public:
		CObjMagicalGirl() {};
		~CObjMagicalGirl() {};
		void Init();   //�C�j�V�����C�Y
		void Action(); //�A�N�V����
		void Draw();   //�h���[
		int GetMP();
		int GetMaxMP();
		int GetHP();
		int GetSkill();
	private:
		float m_gx;//�ʒu
		float m_gy;
		float z_x;//all�e�̈ʒux
		float z_y;//all�e�̈ʒuy
		float m_postrue;//�p��

		int m_mp;//MP
		int m_maxmp;//MAXMP
		int m_atk_animation;//�U���̃��[�V����

		int m_skill;//�X�L���I��
		
		int m_mtime;//MP�񕜗p����
		int m_btime;//�z�[�~���O�e�p����
		bool s_t;//�X�L���I���Ԋu
		bool m_t;//�U���Ԋu
		bool h_t;//�񕜊Ԋu
		bool b_t;//�o���A�Ԋu
		bool z_t;//�S�̍U���Ԋu
};