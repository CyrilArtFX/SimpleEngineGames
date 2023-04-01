#pragma once
#include <SimpleEngine/IScene.h>

class WarriorScene : public IScene
{
public:
	WarriorScene() : IScene() {}
	~WarriorScene() {}
	WarriorScene(const WarriorScene&) = delete;
	WarriorScene& operator=(const WarriorScene&) = delete;

	void load(Game* game) override;
};

