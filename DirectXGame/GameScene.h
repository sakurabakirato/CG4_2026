#pragma once
#include "KamataEngine.h"
#include "Effect.h"

//ゲームシーン
class GameScene 
{
public:
	//デストラクタ
	/*GameScene();*/
	~GameScene();

	//初期化
	void Initialize();

	//更新
	void Update();

	//描画
	void Draw();

private:
	KamataEngine::Effect* effect_ = nullptr;
	KamataEngine::WorldTransform worldTransform_;
	KamataEngine::Camera camera_;

	uint32_t textureHandle_ = 0;
};
