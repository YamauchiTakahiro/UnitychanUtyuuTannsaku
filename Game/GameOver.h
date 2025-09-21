#pragma once
#include"sound/SoundSource.h"

class GameOver : public IGameObject
{
public:
	//メンバ関数
	GameOver();
	~GameOver();
	//開始処理
	//bool Start();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	//メンバ変数
	SpriteRender m_spriteRender;//スプライトレンダー
	SoundSource* m_gameOverBGM;//BGM
};