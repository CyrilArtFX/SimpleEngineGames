#pragma once
#include <SimpleEngine/Scene.h>

class BreakerScene : public Scene
{
public:
	BreakerScene() : Scene() {}
	~BreakerScene() {}
	BreakerScene(const BreakerScene&) = delete;
	BreakerScene& operator=(const BreakerScene&) = delete;

	void load(Game* game) override;
};

