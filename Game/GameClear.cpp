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
//	//PlayingSound()を使用するため、SoundManagerのインスタンスを取得。
//	SoundManager* sound = FindGO<SoundManager>("soundManager");
//	//BGMの再生。
//	m_gameClearBGM = sound->PlayingSound(Sound::enSound_GameClearBGM);
//
//	return true;
//}

void GameClear::Update()
{
	//スタートボタンを押したらタイトルに戻る
	if (g_pad[0]->IsTrigger(enButtonStart))
	{
		NewGO<Title>(0, "title");
		DeleteGO(this);
	}

	//Aボタンを押したらゲームをリトライする
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