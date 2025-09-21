#include "stdafx.h"
#include "Bullet.h"
#include "Enemy.h"
#include "collision/CollisionObject.h"

Bullet::Bullet()
{
	m_modelRender.Init("Assets/modelData/bullet/bullet.tkm");
}

Bullet::~Bullet()
{

}

void Bullet::Update()
{
	Move();

	OnCollision();

	//Hit();

	//‰æ–ÊŠO‚Éo‚½‚çÁ‚¦‚é
	if (m_position.x >= 640.0f)
	{
		DeleteGO(this);
	}

	m_modelRender.Update();
}

void Bullet::Move()
{
	//ˆÚ“®‘¬“x‚ğİ’è
	m_position.x += 10.0f;

	m_modelRender.SetPosition(m_position);
}

void Bullet::Render(RenderContext& renderConetxt)
{
	m_modelRender.Draw(renderConetxt);
}

void Bullet::OnCollision()
{
    nsK2Engine::CollisionObject* collisionObject = NewGO<nsK2Engine::CollisionObject>(0);
	Vector3 collisionPosition = m_position;

	collisionObject->CreateSphere(collisionPosition, Quaternion::Identity, 10.0f);
	collisionObject->SetName("bullet");
}

void Bullet::Hit()
{
	const auto& collisions = g_collisionObjectManager->FindCollisionObjects("enemy");

	for (auto collision : collisions)
	{
		if (collision->IsHit(m_collisionObject) == true)
		{
			DeleteGO(this);
			break;
		}
	}
}