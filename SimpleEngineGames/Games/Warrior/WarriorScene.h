#pragma once
#include <SimpleEngine/Scene.h>

class WarriorScene : public Scene
{
public:
	WarriorScene() : Scene() {}
	~WarriorScene() {}
	WarriorScene(const WarriorScene&) = delete;
	WarriorScene& operator=(const WarriorScene&) = delete;

	void load(Game* game) override;
};

