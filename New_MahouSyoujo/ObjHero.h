#pragma once
//使用するヘッダー
#include "GameL\SceneObjManager.h"
//使用するネームスペース
using namespace GameL;

//オブジェクト主人公
class CObjHero :public CObj
{
public :
	CObjHero() {};
	~CObjHero() ;
	void Init();
	void Action();
	void Draw();
	float GetX() { return m_px; };
	float GetY() { return m_py; };
	float GetVY() { return m_vy; };
	float GetVX() { return m_vx; };

	float SetX(float x) { return m_px=x; };
	float SetY(float y) { return m_py=y; };
	float SetVY(float vy) { return m_vy = vy; };
	float SetVX(float vx) { return m_vx = vx; };
	int GetHP();
	int GetMAXHP();
	int GetMP();

	void SetUp(bool b) { m_hit_up = b; }
	void SetDown(bool b) { m_hit_down = b; }
	void SetLeft(bool b) { m_hit_left = b; }
	void SetRight(bool b) { m_hit_right = b; }
private:
	float m_px;		//プレイヤーの座標X
	float m_py;		//プレイヤーの座標Y
	float m_vx;		//プレイヤーのベクトルX
	float m_vy;		//プレイヤーのベクトルY
	float m_posture;//向いている方向用

	int m_mp;   //現在のMP
	int m_Skill;//魔法少女のスキル選択


	int m_anime;	//歩くアニメーション
	int m_anitime;	//歩くアニメーションの間隔

	int atk_anime;	//剣を出す
	int atk_anitime;//
	int atk_time;	//攻撃の間隔

	float m_hp;//プレイヤーの体力
	float max_hp;
	int mtk_jkn;//無敵時間用変数
	int mtk_max;//無敵時間用変数
	bool m_mtk;//主人公の無敵判定

	bool h_t;//回復間隔

	bool m_f;		//攻撃の間隔
	bool isJump;//ジャンプできるかできないかを判断する

	//blockとの衝突状態確認用
	bool m_hit_up;
	bool m_hit_down;
	bool m_hit_left;
	bool m_hit_right;

	float h_xsize;
	float h_ysize;

	int Weapon;//主人公の武器
	float damage;//主人公が受けるダメージ
	float AllDamage;//主人公が受けたダメージ
};