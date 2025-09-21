#pragma once
class BackGround : public IGameObject
{
public:
	//メンバ関数
	BackGround();
	~BackGround();
	//更新処理
	void Update();

	//描画処理。
	void Render(RenderContext& rc);

	//メンバ変数
	ModelRender m_modelRender;//モデルレンダー
	PhysicsStaticObject m_physicsStaticObject;//物理静的オブジェクト
};

