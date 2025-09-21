#include "stdafx.h"
#include "GameOver.h"
#include "Title.h"
#include "Game.h"
#include "SoundManager.h"

GameOver::GameOver()
{
	m_spriteRender.Init("Assets/sprite/gameover.dds", 1920.0f, 1080.0f);
}

GameOver::~GameOver()
{
	DeleteGO(m_gameOverBGM);
}

//bool GameOver::Start()
//{
//
//	//PlayingSound()���g�p���邽�߁ASoundManager�̃C���X�^���X���擾�B
//	SoundManager* sound = FindGO<SoundManager>("soundManager");
//	//BGM�̍Đ��B
//	m_gameOverBGM = sound->PlayingSound(Sound::enSound_GameOverBGM);
//
//	return true;
//}

void GameOver::Update()
{
	//�X�^�[�g�{�^������������^�C�g���ɖ߂�
	if (g_pad[0]->IsTrigger(enButtonStart))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}

	//A�{�^������������Q�[�������g���C����
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void GameOver::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
