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
	//y座標が280以上になったら
	if (m_position.y >= 280.0f)
	{
		//moveStateを1にする
		m_moveState = 1;
	}
	//y座標が-280以下になったら
	else if (m_position.y <= -280.0f)
	{
		//moveStateを0にする
		m_moveState = 0;
	}
}

void Enemy::Move() 
{

	switch (m_moveState)
	{
		//moveStateが0の時
	case 0:
		//上に移動する
			m_position.y += 2.0f;
		break;
		//moveStateが1の時
	case 1:
		//下に移動する
			m_position.y -= 2.0f;
		break;
	default:
		break;
	}

	m_modelRender.SetPosition(m_position);
}

void Enemy::Rotation()
{
	//ランダムな値で回転させる
	m_rotation.AddRotationDegY(rand() % 9 + 2.0f);
	m_modelRender.SetRotation(m_rotation);
}

void Enemy::OnCollision()
{
	//コリジョンオブジェクトを生成
	m_collisionObject = NewGO<nsK2Engine::CollisionObject>(0);
	Vector3 collisionPosition = m_position;
	//ボックス状のコリジョンを生成
	m_collisionObject->CreateBox(collisionPosition, Quaternion::Identity, Vector3(50.0f, 50.0f, 50.0f));
	//名前を生成する
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