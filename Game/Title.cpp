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
	//PlayingSound()���g�p���邽�߁ASoundManager�̃C���X�^���X���擾�B
	SoundManager* sound = FindGO<SoundManager>("soundManager");
	//BGM�̍Đ��B
	m_titleBGM = sound->PlayingSound(Sound::enSound_TitleBGM);

	return true;
}

void Title::Update()
{
	//A�{�^�����������Ƃ��ɃQ�[���V�[���ֈڍs����B
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
