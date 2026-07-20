#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::mt19937 randomEngine(seedGenerator());
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

// デストラクタ
GameScene::~GameScene() 
{
	// 3Dモデルデータの解放
	delete modelParticle_;
	delete stage_;

	// パーティクルの解放
	for (Particle* particle : particles_) 
	{
		delete particle;
	}
	particles_.clear();
}

// 初期化
void GameScene::Initialize() 
{
	// 乱数の初期化
	srand((unsigned)time(NULL));

	// 3Dモデルデータの生成
	modelParticle_ = Model::CreateSphere(4, 4);
	textureHandleStage_ = TextureManager::Load("stage.png");

	// カメラの初期化
	camera_.Initialize();
	// 追加
	camera_.translation_ = {0.0f, 0.0f, -50.0f};
	camera_.rotation_ = {0.0f, 0.0f, 0.0f};
	camera_.UpdateMatrix();

	stage_ = new Stage();
	stage_->Initialize(textureHandleStage_);


}

// 更新
void GameScene::Update() 
{
	stage_->Update();

	// 確率で発生
	if (rand() % 3 == 0) 
	{
		// 発生位置は乱数
		Vector3 position = {distribution(randomEngine) * 30.0f, distribution(randomEngine) * 20.0f, 0};
		// パーティクルの生成
		ParticleBorn(position);
	}
	// パーティクルの更新
	for (Particle* particle : particles_) 
	{
		particle->Update();
	}

	// 終了フラグの立ったパーティクルを削除
	particles_.remove_if([](Particle* particle) 
		{
		if (particle->IsFinished() == true) 
		{
			delete particle;
			return true;
		}
		return false;
	});
}

// 描画
void GameScene::Draw() 
{
	// DirectXCommonインスタンスの取得
	DirectXCommon* dxCommon = DirectXCommon::GetInstance();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());

	stage_->Draw();

	// スプライト描画後処理
	Sprite::PostDraw();

	// 3Dモデル描画前処理
	Model::PreDraw();

	// パーティクル描画
	for (Particle* particle : particles_) 
	{
		particle->Draw(camera_);
	}
	// 3Dモデル描画後処理
	Model::PostDraw();
}

// パーティクルの発生
void GameScene::ParticleBorn(Vector3 position) 
{
	// パーティクルの生成
	for (int i = 0; i < 150; i++) 
	{
		// 生成
		Particle* particle = new Particle();
		// 移動量
		Vector3 velocity = {distribution(randomEngine), distribution(randomEngine), 0};
		Normalize(velocity);
		velocity *= distribution(randomEngine);
		velocity *= 0.1f;
		// 初期化
		particle->Initialize(modelParticle_, position, velocity);
		// リストに追加
		particles_.push_back(particle);
	}
}
