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
		int GetHP();
		int GetSkill();
	private:
		float m_gx;//位置
		float m_gy;
		float z_x;//all弾の位置x
		float z_y;//all弾の位置y
		float m_postrue;//姿勢

		int m_mp;//MP
		int m_maxmp;//MAXMP
		int m_atk_animation;//攻撃のモーション
		//int h_maxhp;//主人公の最大HP
		//int h_hp;//主人公の現HP

		int m_skill;//スキル選択
		
		int m_mtime;//MP回復用時間
		int m_btime;//ホーミング弾用時間
		bool s_t;//スキル選択間隔
		bool m_t;//攻撃間隔
		bool h_t;//回復間隔
		bool b_t;//バリア間隔
		bool z_t;//全体攻撃間隔
};