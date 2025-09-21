#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "BackGround.h"
#include "GameCamera.h"
#include "Bullet.h"
#include "Enemy.h"
#include "SoundManager.h"
#include "GameClear.h"
#include "GameOver.h"
#include "sound/SoundEngine.h"
#include "sound/SoundSource.h"


Game::Game()
{
	//プレイヤーを生成する。
	m_player = NewGO<Player>(0, "battleCharacter");
	//背景を生成する。
	m_backGround = NewGO<BackGround>(0, "backGround");
	//カメラを生成する。
	m_gameCamera = NewGO<GameCamera>(0, "gameCamera");
	//ランダムな場所に敵を10体生成する。
	for (int enemy = 0; enemy < 10; enemy++)
	{
		m_enemy = NewGO<Enemy>(1, "enemy");
		m_enemy->m_position = { rand() % 461 + 140.0f ,rand() % -470 - 250.0f, 0.0f };
	}

	g_renderingEngine->DisableTonemap();
}

Game::~Game()
{
	//プレイヤーを削除する
	DeleteGO(m_player);
	//背景を削除する
	DeleteGO(m_backGround);
	//カメラを削除する
	DeleteGO(m_gameCamera);
	//BGMを削除する
	DeleteGO(m_gameBGM);
	//敵を削除する
	DeleteGO(m_enemy);
	//弾を削除する
	DeleteGO(m_bullet);
}

bool Game::Start()
{
	//PlayingSound()を使用するため、SoundManagerのインスタンスを取得。
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	//BGMの再生。
	m_gameBGM = sound->PlayingSound(Sound::enSound_InGameBGM);

	return true;
}

void Game::Update()
{
	//Xボタンを押したときに弾を発射する。
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		BulletSpown();
	}

	//敵を10体倒したらゲームクリアに移行する
	if (m_player->m_enemyKillCount >= 10.0)
	{
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
	}

	g_renderingEngine->DisableRaytracing();
}

void Game::BulletSpown()
{
	//プレイヤーの前方に弾を生成する。
	m_bullet = NewGO<Bullet>(0, "bullet");
	m_bullet->m_position = { m_player->m_position.x + 40.0f, m_player->m_position.y + 50.0f, 0.0f };
	
	//弾の発射音を鳴らす。
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/soundEffects/laser.wav");
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(2);
	se->Play(false);
	se->SetVolume(1.0f);
}