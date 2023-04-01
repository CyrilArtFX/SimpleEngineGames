#pragma once
#include <SimpleEngine/IScene.h>

class PongScene : public IScene
{
public:
	PongScene() : IScene() {}
	~PongScene() {}
	PongScene(const PongScene&) = delete;
	PongScene& operator=(const PongScene&) = delete;

	void load(Game* game) override;
};

