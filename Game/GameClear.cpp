#include "stdafx.h"
#include "GameClear.h"
#include "Title.h"
#include "Game.h"
#include "SoundManager.h"

GameClear::GameClear()
{
	m_spriteRender.Init("Assets/sprite/gameclear.dds", 1920.0f, 1080.0f);
}

GameClear::~GameClear()
{
	DeleteGO(m_gameClearBGM);
}

//bool GameClear::Start()
//{
//	//PlayingSound()���g�p���邽�߁ASoundManager�̃C���X�^���X���擾�B
//	SoundManager* sound = FindGO<SoundManager>("soundManager");
//	//BGM�̍Đ��B
//	m_gameClearBGM = sound->PlayingSound(Sound::enSound_GameClearBGM);
//
//	return true;
//}

void GameClear::Update()
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

void GameClear::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}