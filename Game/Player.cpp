#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	m_animationClips[enAnimationClip_Idle].Load("Assets/animData/idle.tka");
	m_animationClips[enAnimationClip_Idle].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Walk].Load("Assets/animData/walk.tka");
	m_animationClips[enAnimationClip_Walk].SetLoopFlag(true);
	m_animationClips[enAnimationClip_Jump].Load("Assets/animData/jump.tka");
	m_animationClips[enAnimationClip_Jump].SetLoopFlag(false);
	m_animationClips[enAnimationClip_Run].Load("Assets/animData/run.tka");
	m_animationClips[enAnimationClip_Run].SetLoopFlag(true);
	//モデルを初期化する。
	m_modelRender.Init("Assets/modelData/unityChan.tkm", m_animationClips, enAnimationClip_Num, enModelUpAxisY);
	m_characterController.Init(25.0f, 75.0f, m_position);
}

Player::~Player()
{

}

void Player::Update()
{
	Move();

	Rotation();

	ManageState();

	PlayAnimation();

	//モデルを更新する。
	m_modelRender.Update();
}

void Player::Move()
{
	//移動速度を初期化する
	m_moveSpeed.x = 0.0f;
	m_moveSpeed.y = 0.0f;
	m_moveSpeed.z = 0.0f;

	//左スティックの入力量を取得する
	Vector3 stickL;
	stickL.x = g_pad[0]->GetLStickXF();
	stickL.y = g_pad[0]->GetLStickYF();

	//カメラの右方向ベクトルを取得する
	Vector3 right = g_camera3D->GetRight();

	right.y = 0.0f;

	//Bボタンを押しているとき移動速度を半分にする
	if (g_pad[0]->IsTrigger(enButtonB))
	{
		//x軸の移動
		if (m_position.x >= -470.0f && m_position.x <= 60.0f)
		{
			right *= stickL.x * 60.0f;
		}
		else
		{
			right *= stickL.x * -60.0f;
		}

		//y軸の移動
		if (m_position.y <= 250.0f && m_position.y >= -280.0f)
		{
			m_moveSpeed.y += stickL.y * 60.0f;
		}
		else
		{
			m_moveSpeed.y += stickL.y * -60.0f;
		}
	}
	else
	{
		//x軸の移動
		if (m_position.x >= -470.0f && m_position.x <= 60.0f)
		{
			right *= stickL.x * 120.0f;
		}
		else
		{
			right *= stickL.x * -120.0f;
		}

		//y軸の移動
		if (m_position.y <= 250.0f && m_position.y >= -280.0f)
		{
			m_moveSpeed.y += stickL.y * 120.0f;
		}
		else
		{
			m_moveSpeed.y += stickL.y * -120.0f;
		}
	}

	//移動方向に右方向ベクトルを加算する
	m_moveSpeed += right;

	//キャラクターコントローラーで移動する
	m_position = m_characterController.Execute(m_moveSpeed, 2.0f / 60.0f);

	m_modelRender.SetPosition(m_position);
}

void Player::Rotation()
{
	//プレイヤーを左に向ける
	m_rotation.SetRotationDegY(90.0f);

	m_modelRender.SetRotation(m_rotation);
}

void Player::ManageState()
{

}

void Player::PlayAnimation()
{
	m_modelRender.PlayAnimation(enAnimationClip_Jump);
}

void Player::Render(RenderContext& renderContext)
{
	//モデルを表示する。
	m_modelRender.Draw(renderContext);
}