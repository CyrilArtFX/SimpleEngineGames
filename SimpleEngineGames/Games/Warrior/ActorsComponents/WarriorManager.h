#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "WarriorPlayer.h"
#include "WarriorGrids.h"

class WarriorManager : public Actor
{
public:
	WarriorManager(WarriorGrids* gridsP, WarriorPlayer* playerP);
	WarriorManager() = delete;
	WarriorManager(const WarriorManager&) = delete;
	WarriorManager operator=(const WarriorManager&) = delete;

	void updateActor(float dt) override;

private:
	WarriorGrids* grids;
	WarriorPlayer* player;
};

