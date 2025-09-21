#include "stdafx.h"
#include "Title.h"
#include "Game.h"
#include "SoundManager.h"

Title::Title()
{
	m_spriteRender.Init("Assets/sprite/title.dds", 1920.f, 1080.0f);
}

Title::~Title()
{
	DeleteGO(m_titleBGM);
}

bool Title::Start()
{
	//PlayingSound()を使用するため、SoundManagerのインスタンスを取得。
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	//BGMの再生。
	m_titleBGM = sound->PlayingSound(Sound::enSound_TitleBGM);

	return true;
}

void Title::Update()
{
	//Aボタンを押したときにゲームシーンへ移行する。
	if (g_pad[0]->IsTrigger(enButtonA))
	{
		NewGO<Game>(0, "game");
		DeleteGO(this);
	}
}

void Title::Render(RenderContext& rc)
{
	m_spriteRender.Draw(rc);
}
