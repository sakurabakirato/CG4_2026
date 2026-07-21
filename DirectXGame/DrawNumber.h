#pragma once
#include "KamataEngine.h"

class DrawNumber 
{
public:

	~DrawNumber();

	void Initialize(uint32_t textureHandle);

	void Update(uint32_t number);

	void Draw(); 

private:

	KamataEngine::Sprite* sprite_[5] = {};

	KamataEngine::Vector2 size = {32.0f, 64.0f};


	uint32_t textureHandle_ = 0;



};
