#pragma once

class Player;
class Bullet;
class CollisionObject;

class Enemy: public IGameObject
{
public:
	//メンバ関数
	Enemy();
	~Enemy();
	//更新処理
	void Update();
	//移動状態の管理
	void MoveStatus();
	//移動処理
	void Move();
	//回転処理
	void Rotation();
	//コリジョン生成処理
	void OnCollision();
	//当たり判定処理
	void Hit();
	//描画処理
	void Render(RenderContext& renderContext);

	//メンバ変数
	ModelRender m_modelRender;//モデルレンダー
	Vector3 m_position;//座標
	Quaternion m_rotation;//回転
	Player* m_player;//プレイヤー
	Bullet* m_bullet;//弾
	int m_moveState = 0;//移動状態
	nsK2Engine::CollisionObject* m_collisionObject; //コリジョンオブジェクト
};
