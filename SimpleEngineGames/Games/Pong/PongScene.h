#pragma once
#include <SimpleEngine/Scene.h>

class PongScene : public Scene
{
public:
	PongScene() : Scene() {}
	~PongScene() {}
	PongScene(const PongScene&) = delete;
	PongScene& operator=(const PongScene&) = delete;

	void load(Game* game) override;
};

