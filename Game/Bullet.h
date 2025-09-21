#pragma once

class Bullet : public IGameObject
{
public:
	//メンバ関数
	Bullet();
	~Bullet();
	//更新処理
	void Update();
	//移動処理
	void Move();
	//コリジョン生成処理
	void OnCollision();
	//当たり判定処理
	void Hit();
	//描画処理
	void Render(RenderContext& renderContext);

	//メンバ変数
	ModelRender m_modelRender;//モデルレンダー
	Vector3 m_position;//座標
	Vector3 m_moveSpeed;//移動速度
	nsK2Engine::CollisionObject* m_collisionObject; //コリジョンオブジェクト
};

