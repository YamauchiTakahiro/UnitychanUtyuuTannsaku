#pragma once
#include"sound/SoundSource.h"

class GameOver : public IGameObject
{
public:
	//�����o�֐�
	GameOver();
	~GameOver();
	//�J�n����
	//bool Start();
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& rc);

	//�����o�ϐ�
	SpriteRender m_spriteRender;//�X�v���C�g�����_�[
	SoundSource* m_gameOverBGM;//BGM
};