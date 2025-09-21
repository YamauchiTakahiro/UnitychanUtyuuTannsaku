#pragma once
#include"sound/SoundSource.h"

class Player;
class GameCamera;
class BackGround;
class Bullet;
class Enemy;

class Game : public IGameObject
{
public:
	//�����o�֐�
	Game();
	~Game();
	//�X�V����
	void Update();
	//�J�n����
	bool Start();
	//�e��������
	void BulletSpown();

	Player* m_player;//�v���C���[�B
	BackGround* m_backGround;//�w�i
	GameCamera* m_gameCamera;//�J����
	SoundSource* m_gameBGM;//BGM
	Bullet* m_bullet;//�e
	Enemy* m_enemy;//�G�l�~�[
	RenderingEngine m_renderingEngine;//�����_�����O�G���W��
};

