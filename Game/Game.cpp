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
	//�v���C���[�𐶐�����B
	m_player = NewGO<Player>(0, "battleCharacter");
	//�w�i�𐶐�����B
	m_backGround = NewGO<BackGround>(0, "backGround");
	//�J�����𐶐�����B
	m_gameCamera = NewGO<GameCamera>(0, "gameCamera");
	//�����_���ȏꏊ�ɓG��10�̐�������B
	for (int enemy = 0; enemy < 10; enemy++)
	{
		m_enemy = NewGO<Enemy>(1, "enemy");
		m_enemy->m_position = { rand() % 461 + 140.0f ,rand() % -470 - 250.0f, 0.0f };
	}

	g_renderingEngine->DisableTonemap();
}

Game::~Game()
{
	//�v���C���[���폜����
	DeleteGO(m_player);
	//�w�i���폜����
	DeleteGO(m_backGround);
	//�J�������폜����
	DeleteGO(m_gameCamera);
	//BGM���폜����
	DeleteGO(m_gameBGM);
	//�G���폜����
	DeleteGO(m_enemy);
	//�e���폜����
	DeleteGO(m_bullet);
}

bool Game::Start()
{
	//PlayingSound()���g�p���邽�߁ASoundManager�̃C���X�^���X���擾�B
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	//BGM�̍Đ��B
	m_gameBGM = sound->PlayingSound(Sound::enSound_InGameBGM);

	return true;
}

void Game::Update()
{
	//X�{�^�����������Ƃ��ɒe�𔭎˂���B
	if (g_pad[0]->IsTrigger(enButtonX))
	{
		BulletSpown();
	}

	//�G��10�̓|������Q�[���N���A�Ɉڍs����
	if (m_player->m_enemyKillCount >= 10.0)
	{
		NewGO<GameClear>(0, "gameClear");
		DeleteGO(this);
	}

	g_renderingEngine->DisableRaytracing();
}

void Game::BulletSpown()
{
	//�v���C���[�̑O���ɒe�𐶐�����B
	m_bullet = NewGO<Bullet>(0, "bullet");
	m_bullet->m_position = { m_player->m_position.x + 40.0f, m_player->m_position.y + 50.0f, 0.0f };
	
	//�e�̔��ˉ���炷�B
	g_soundEngine->ResistWaveFileBank(2, "Assets/sound/soundEffects/laser.wav");
	SoundSource* se = NewGO<SoundSource>(0);
	se->Init(2);
	se->Play(false);
	se->SetVolume(1.0f);
}