#pragma once
#include <SimpleEngine/IScene.h>

class TestScene : public IScene
{
public:
	TestScene() : IScene() {}
	~TestScene() {}
	TestScene(const TestScene&) = delete;
	TestScene& operator=(const TestScene&) = delete;

	void load(Game* game) override;
};

