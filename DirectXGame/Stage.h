#pragma once
#include "KamataEngine.h"

class Stage 
{
public:
	~Stage();

	void Initialize(uint32_t TtextureHandle);

	void Update();

	void Draw();

	// デスフラグのgetter
	bool IsFinished() const { return finished_; }

private:

	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* sprite2_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;

	// 終了フラグ
	bool finished_ = false;

	int timer = 0;
};
