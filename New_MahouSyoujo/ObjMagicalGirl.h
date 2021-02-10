#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト：主人公
class CObjMagicalGirl : public CObj
{
	public:
		CObjMagicalGirl() {};
		~CObjMagicalGirl() {};
		void Init();   //イニシャライズ
		void Action(); //アクション
		void Draw();   //ドロー
		int GetMP();
		int GetMaxMP();
		int GetSkill();
		int GetHP();
	private:
		float m_gx;//x軸の位置
		float m_gy;//y軸の位置
		
		float m_postrue;//姿勢

		float h_hp;//主人公HP

		int m_mp;//MP
		int m_maxmp;//MAXMP
		int m_atk_animation;//攻撃のモーション

		int m_skill;//スキル選択
		
		int m_mtime;//MP回復用時間
		
		bool s_t;//スキル選択間隔
		int iconAnime[2];//アイコン上に表示させるやつ。
		bool m_key_flag;
};