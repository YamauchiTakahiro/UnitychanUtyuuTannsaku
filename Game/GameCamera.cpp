#include "stdafx.h"
#include "GameCamera.h"

GameCamera::GameCamera()
{

}

GameCamera::~GameCamera()
{

}
bool GameCamera::Start()
{
	m_toCameraPos.Set(0.0f, 0.0f, -550.0f);

	return true;
}

void GameCamera::Update()
{
	Vector3 target;

	target.x = 85.0f;
	target.y = 0.0f;
	target.z = 0.0f;

	Vector3 pos = target + m_toCameraPos;

	g_camera3D->SetTarget(target);
	g_camera3D->SetPosition(pos);

	g_camera3D->Update();
}