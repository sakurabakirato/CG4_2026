#pragma once
#include "KamataEngine.h"

class TitleScene 
{
public:

	~TitleScene();

	void Initialize();

	void Update();

	void Draw();

	// デスフラグのgetter
	bool IsFinished() const { return finished_; }

private:

	//Model* modelTitle_ = nullptr;

	//Camera camera_;

	// スプライト
	KamataEngine::Sprite* sprite_ = nullptr;
	KamataEngine::Sprite* spriteFont_ = nullptr;
	KamataEngine::Sprite* spriteHit_ = nullptr;

	// テクスチャハンドル
	uint32_t textureHandle_ = 0;
	uint32_t textureHandleFont_ = 0;
	uint32_t textureHandleHit_ = 0;

	//終了フラグ
	bool finished_ = false;

	int timer = 0;

};
