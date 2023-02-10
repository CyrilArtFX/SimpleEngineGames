#pragma once
#include <SimpleEngine/Scene.h>

class RacingScene : public Scene
{
public:
	RacingScene() : Scene() {}
	~RacingScene() {}
	RacingScene(const RacingScene&) = delete;
	RacingScene& operator=(const RacingScene&) = delete;

	void load(Game* game) override;
};

