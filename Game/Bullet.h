#pragma once

class Bullet : public IGameObject
{
public:
	//�����o�֐�
	Bullet();
	~Bullet();
	//�X�V����
	void Update();
	//�ړ�����
	void Move();
	//�R���W������������
	void OnCollision();
	//�����蔻�菈��
	void Hit();
	//�`�揈��
	void Render(RenderContext& renderContext);

	//�����o�ϐ�
	ModelRender m_modelRender;//���f�������_�[
	Vector3 m_position;//���W
	Vector3 m_moveSpeed;//�ړ����x
	nsK2Engine::CollisionObject* m_collisionObject; //�R���W�����I�u�W�F�N�g
};

