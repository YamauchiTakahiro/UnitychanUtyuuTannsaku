#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround()
{
	m_modelRender.Init("Assets/modelData/backGround/backGround.tkm");

	//“–‚½‚è”»’è‚ðì¬
	m_physicsStaticObject.CreateFromModel(m_modelRender.GetModel(), m_modelRender.GetModel().GetWorldMatrix());
	//PhysicsWorld::GetInstance()->EnableDrawDebugWireFrame();
}

BackGround::~BackGround()
{

}

void BackGround::Update()
{

}
void BackGround::Render(RenderContext& rc)
{
	m_modelRender.Draw(rc);
}