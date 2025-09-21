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
//	//PlayingSound()を使用するため、SoundManagerのインスタンスを取得。
//	SoundManager* sound = FindGO<SoundManager>("soundManager");
//	//BGMの再生。
//	m_gameOverBGM = sound->PlayingSound(Sound::enSound_GameOverBGM);
//
//	return true;
//}

void GameOver::Update()
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

void GameOver::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
