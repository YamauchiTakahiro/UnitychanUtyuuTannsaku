#pragma once
#include"sound/SoundSource.h"

class GameClear : public IGameObject
{
public:
	//�����o�֐�
	GameClear();
	~GameClear();
	//�J�n����
	//bool Start();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SpriteRender m_spriteRender;//�X�v���C�g�����_�[
	SoundSource* m_gameClearBGM;//BGM
};

