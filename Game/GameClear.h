#pragma once
#include"sound/SoundSource.h"

class GameClear : public IGameObject
{
public:
	//メンバ関数
	GameClear();
	~GameClear();
	//開始処理
	//bool Start();
	//更新処理
	void Update();
	//描画処理
	void Render(RenderContext& rc);

	//メンバ変数
	SpriteRender m_spriteRender;//スプライトレンダー
	SoundSource* m_gameClearBGM;//BGM
};

