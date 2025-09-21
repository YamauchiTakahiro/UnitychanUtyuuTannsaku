#pragma once

class Player : public IGameObject
{
public:
	Player();
	~Player();
	//�������烁���o�֐��B
	//�X�V����
	void Update();
	//�`�揈��
	void Render(RenderContext& renderContext);
	//�ړ�����
	void Move();
	//��]����
	void Rotation();
	//��ԊǗ�
	void ManageState();
	//�A�j���[�V�����Đ�
	void PlayAnimation();

	//�������烁���o�ϐ��B
	ModelRender m_modelRender;//���f�������_�[
	Vector3 m_position;//���W
	enum EnAnimationClip {		//�A�j���[�V�����B
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];//�A�j���[�V�����N���b�v
	CharacterController m_characterController;//�L�����N�^�[�R���g���[���[
	Vector3 m_moveSpeed;//�ړ����x
	Quaternion m_rotation;//��]
	int m_playerState = 0;//�v���[���[�̏��
	float m_enemyKillCount = 0;
};



