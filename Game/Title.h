#pragma once
#include"sound/SoundSource.h"

class Title : public IGameObject
{
public:
	//メンバ関数
	Title();
	~Title();
	//開始処理
	bool Start();
	//描画処理
	void Render(RenderContext& rc);
	//更新処理
	void Update();

	SpriteRender m_spriteRender;//スプライトレンダー
	SoundSource* m_titleBGM;//BGM
};

