#pragma once

#include "KamataEngine.h"
#include "Particle.h"
#include "Stage.h"

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
	KamataEngine::Model* modelParticle_ = nullptr;

	Stage* stage_ = nullptr;

	// カメラ
	KamataEngine::Camera camera_;
	// パーティクル
	Particle* particle_ = nullptr;
	std::list<Particle*> particles_;

	/// <summary>
	/// パーティクル発生
	/// </summary>
	/// <param name="position">位置</param>
	void ParticleBorn(Vector3 position);

	// テクスチャハンドル
	uint32_t textureHandleStage_ = 0;


	// 終了フラグ
	bool finished_ = false;

};