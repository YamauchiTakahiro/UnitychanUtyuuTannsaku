#pragma once

class Player : public IGameObject
{
public:
	Player();
	~Player();
	//ここからメンバ関数。
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& renderContext);
	//移動処理
	void Move();
	//回転処理
	void Rotation();
	//状態管理
	void ManageState();
	//アニメーション再生
	void PlayAnimation();

	//ここからメンバ変数。
	ModelRender m_modelRender;//モデルレンダー
	Vector3 m_position;//座標
	enum EnAnimationClip {		//アニメーション。
		enAnimationClip_Idle,
		enAnimationClip_Walk,
		enAnimationClip_Jump,
		enAnimationClip_Run,
		enAnimationClip_Num,
	};
	AnimationClip m_animationClips[enAnimationClip_Num];//アニメーションクリップ
	CharacterController m_characterController;//キャラクターコントローラー
	Vector3 m_moveSpeed;//移動速度
	Quaternion m_rotation;//回転
	int m_playerState = 0;//プレーヤーの状態
	float m_enemyKillCount = 0;
};



