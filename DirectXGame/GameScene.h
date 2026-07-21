#pragma once

#include "KamataEngine.h"
#include "Stage.h"
#include "Player.h"
#include "GraphBar.h"

// ゲームシーン
class GameScene 
{
public:
	/// <summary>
	/// デストラクタ
	/// </summary>
	~GameScene();

	/// <summary>
	/// 初期化
	/// </summary>
	void Initialize();

	/// <summary>
	/// 更新
	/// </summary>
	void Update();

	/// <summary>
	/// 描画
	/// </summary>
	void Draw();

	// デスフラグのgetter
	bool IsFinished() const { return finished_; }

private:
	// パーティクル3Dモデルデータ
	KamataEngine::Model* modelPlayer_ = nullptr;

	Stage* stage_ = nullptr;
	Player* player_ = nullptr;
	GraphBar* graphBar_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;


	// テクスチャハンドル
	uint32_t textureHandleStage_ = 0;
	uint32_t textureHandleGraph_ = 0;


	// 終了フラグ
	bool finished_ = false;

	int hp_ = 100;
	int gameScore_ = 1;

};