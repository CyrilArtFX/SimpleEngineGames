#pragma once
#include <SimpleEngine/IScene.h>

class SpaceScene : public IScene
{
public:
	SpaceScene() : IScene() {}
	~SpaceScene() {}
	SpaceScene(const SpaceScene&) = delete;
	SpaceScene& operator=(const SpaceScene&) = delete;

	void load(Game* game) override;
};

