#pragma once
class BackGround : public IGameObject
{
public:
	//�����o�֐�
	BackGround();
	~BackGround();
	//�X�V����
	void Update();

	//�`�揈���B
	void Render(RenderContext& rc);

	//�����o�ϐ�
	ModelRender m_modelRender;//���f�������_�[
	PhysicsStaticObject m_physicsStaticObject;//�����ÓI�I�u�W�F�N�g
};

