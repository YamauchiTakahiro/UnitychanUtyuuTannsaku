#pragma once

class Player;

class GameCamera : public IGameObject
{
public:
	//�����o�֐�
	GameCamera();
	~GameCamera();
	//�J�n����
	bool Start();
	//�X�V����
	void Update();

	//�����o�ϐ�
	Player* m_player;//�v���C���[
	Vector3 m_toCameraPos;//�J�����܂ł̋���
};

