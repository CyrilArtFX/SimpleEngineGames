#pragma once
#include <SimpleEngine/IScene.h>

class RacingScene : public IScene
{
public:
	RacingScene() : IScene() {}
	~RacingScene() {}
	RacingScene(const RacingScene&) = delete;
	RacingScene& operator=(const RacingScene&) = delete;

	void load(Game* game) override;
};

