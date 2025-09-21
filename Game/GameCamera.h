#pragma once

class Player;

class GameCamera : public IGameObject
{
public:
	//メンバ関数
	GameCamera();
	~GameCamera();
	//開始処理
	bool Start();
	//更新処理
	void Update();

	//メンバ変数
	Player* m_player;//プレイヤー
	Vector3 m_toCameraPos;//カメラまでの距離
};

