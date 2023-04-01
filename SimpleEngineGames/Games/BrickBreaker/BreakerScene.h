#pragma once
#include <SimpleEngine/IScene.h>

class BreakerScene : public IScene
{
public:
	BreakerScene() : IScene() {}
	~BreakerScene() {}
	BreakerScene(const BreakerScene&) = delete;
	BreakerScene& operator=(const BreakerScene&) = delete;

	void load(Game* game) override;
};

