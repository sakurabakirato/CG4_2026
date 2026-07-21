#include "GameScene.h"
#include <random>

using namespace KamataEngine;
using namespace MathUtility;

std::random_device seedGenerator;
std::uniform_real_distribution<float> distribution(-1.0f, 1.0f);

// デストラクタ
GameScene::~GameScene() 
{
	// 3Dモデルデータの解放
	delete stage_;
	delete player_;

	delete modelPlayer_;
}

// 初期化
void GameScene::Initialize() 
{
	// 乱数の初期化
	srand((unsigned)time(NULL));

	// 3Dモデルデータの生成
	textureHandleStage_ = TextureManager::Load("stage.png");
	modelPlayer_ = Model::CreateFromOBJ("player");

	// カメラの初期化
	camera_.Initialize();
	// 追加
	camera_.translation_ = {0.0f, 0.0f, -50.0f};
	camera_.rotation_ = {0.0f, 0.0f, 0.0f};
	camera_.UpdateMatrix();

	stage_ = new Stage();
	stage_->Initialize(textureHandleStage_);

	player_ = new Player();
	player_->Initialize(modelPlayer_);


}

// 更新
void GameScene::Update() 
{ 
	stage_->Update(); 
	player_->Update();
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


	//深度バッファクリア
	dxCommon->ClearDepthBuffer();


	// 3Dモデル描画前処理
	Model::PreDraw();

	player_->Draw(camera_);

	// 3Dモデル描画後処理
	Model::PostDraw();

	// スプライト描画前処理
	Sprite::PreDraw(dxCommon->GetCommandList());



	// スプライト描画後処理
	Sprite::PostDraw();
}

