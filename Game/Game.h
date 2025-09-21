#pragma once
#include"sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Bullet;
class Enemy;

class Game : public IGameObject
{
public:
	//メンバ関数
	Game();
	~Game();
	//更新処理
	void Update();
	//開始処理
	bool Start();
	//弾生成処理
	void BulletSpown();

	Player* m_player;//プレイヤー。
	BackGround* m_backGround;//背景
	GameCamera* m_gameCamera;//カメラ
	SoundSource* m_gameBGM;//BGM
	Bullet* m_bullet;//弾
	Enemy* m_enemy;//エネミー
	RenderingEngine m_renderingEngine;//レンダリングエンジン
};

