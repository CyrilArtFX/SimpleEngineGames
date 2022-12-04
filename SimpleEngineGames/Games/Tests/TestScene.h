#pragma once
#include <SimpleEngine/Scene.h>

class TestScene : public Scene
{
public:
	TestScene() : Scene() {}
	~TestScene() {}
	TestScene(const TestScene&) = delete;
	TestScene& operator=(const TestScene&) = delete;

	void load(Game* game) override;
};

