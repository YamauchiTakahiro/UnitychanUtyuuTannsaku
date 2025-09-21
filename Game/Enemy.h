#pragma once

class Player;
class Bullet;
class CollisionObject;

class Enemy: public IGameObject
{
public:
	//�����o�֐�
	Enemy();
	~Enemy();
	//�X�V����
	void Update();
	//�ړ���Ԃ̊Ǘ�
	void MoveStatus();
	//�ړ�����
	void Move();
	//��]����
	void Rotation();
	//�R���W������������
	void OnCollision();
	//�����蔻�菈��
	void Hit();
	//�`�揈��
	void Render(RenderContext& renderContext);

	//�����o�ϐ�
	ModelRender m_modelRender;//���f�������_�[
	Vector3 m_position;//���W
	Quaternion m_rotation;//��]
	Player* m_player;//�v���C���[
	Bullet* m_bullet;//�e
	int m_moveState = 0;//�ړ����
	nsK2Engine::CollisionObject* m_collisionObject; //�R���W�����I�u�W�F�N�g
};
