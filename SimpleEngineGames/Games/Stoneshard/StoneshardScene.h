#pragma once
#include <SimpleEngine/IScene.h>

class StoneshardScene : public IScene
{
public:
	StoneshardScene() : IScene() {}
	~StoneshardScene() {}
	StoneshardScene(const StoneshardScene&) = delete;
	StoneshardScene& operator=(const StoneshardScene&) = delete;

	void load(Game* game) override;
};

