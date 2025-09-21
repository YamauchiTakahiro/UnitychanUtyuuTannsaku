#pragma once
#include"sound/SoundSource.h"

class Title : public IGameObject
{
public:
	//�����o�֐�
	Title();
	~Title();
	//�J�n����
	bool Start();
	//�`�揈��
	void Render(RenderContext& rc);
	//�X�V����
	void Update();

	SpriteRender m_spriteRender;//�X�v���C�g�����_�[
	SoundSource* m_titleBGM;//BGM
};

