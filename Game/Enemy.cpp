#include "stdafx.h"
#include "Enemy.h"
#include "Player.h"
#include "Bullet.h"
#include "collision/CollisionObject.h"

Enemy::Enemy()
{
	m_modelRender.Init("Assets/modelData/enemy/enemy.tkm");

    m_player = FindGO<Player>("battleCharacter");

	m_bullet = FindGO<Bullet>("bullet");
}

Enemy::~Enemy()
{

}

void Enemy::Update()
{
	MoveStatus();

	Move();

	//Rotation();

	OnCollision();

	Hit();

	m_modelRender.Update();
}

void Enemy::MoveStatus()
{
	//y���W��280�ȏ�ɂȂ�����
	if (m_position.y >= 280.0f)
	{
		//moveState��1�ɂ���
		m_moveState = 1;
	}
	//y���W��-280�ȉ��ɂȂ�����
	else if (m_position.y <= -280.0f)
	{
		//moveState��0�ɂ���
		m_moveState = 0;
	}
}

void Enemy::Move() 
{

	switch (m_moveState)
	{
		//moveState��0�̎�
	case 0:
		//��Ɉړ�����
			m_position.y += 2.0f;
		break;
		//moveState��1�̎�
	case 1:
		//���Ɉړ�����
			m_position.y -= 2.0f;
		break;
	default:
		break;
	}

	m_modelRender.SetPosition(m_position);
}

void Enemy::Rotation()
{
	//�����_���Ȓl�ŉ�]������
	m_rotation.AddRotationDegY(rand() % 9 + 2.0f);
	m_modelRender.SetRotation(m_rotation);
}

void Enemy::OnCollision()
{
	//�R���W�����I�u�W�F�N�g�𐶐�
	m_collisionObject = NewGO<nsK2Engine::CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//�{�b�N�X��̃R���W�����𐶐�
	m_collisionObject->CreateBox(collisionPosition, Quaternion::Identity, Vector3(50.0f, 50.0f, 50.0f));
	//���O�𐶐�����
	m_collisionObject->SetName("enemy");
}

void Enemy::Hit()
{
	const auto& collisions = g_collisionObjectManager->FindCollisionObjects("bullet");

	for (auto collision : collisions)
	{
		if (collision->IsHit(m_collisionObject) == true)
		{
			g_soundEngine->ResistWaveFileBank(2, "Assets/sound/soundEffects/beingHit.wav");
			SoundSource* se = NewGO<SoundSource>(0);
			se->Init(2);
			se->Play(false);
			se->SetVolume(3.5f);

			m_player->m_enemyKillCount += 1.0;

			DeleteGO(m_bullet);

			DeleteGO(this);
			break;
		}
	}
}

void Enemy::Render(RenderContext& renderContext)
{
	m_modelRender.Draw(renderContext);
}