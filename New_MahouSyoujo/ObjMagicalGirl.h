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
		int GetSkill();
		int GetHP();
	private:
		float m_gx;//x���̈ʒu
		float m_gy;//y���̈ʒu
		
		float m_postrue;//�p��

		float h_hp;//��l��HP

		int m_mp;//MP
		int m_maxmp;//MAXMP
		int m_atk_animation;//�U���̃��[�V����

		int m_skill;//�X�L���I��
		
		int m_mtime;//MP�񕜗p����
		
		bool s_t;//�X�L���I���Ԋu
		int iconAnime[2];//�A�C�R����ɕ\���������B
		bool m_key_flag;
};