#include "WarriorManager.h"

WarriorManager::WarriorManager(WarriorGrids* gridsP, WarriorPlayer* playerP) : Actor(), grids(gridsP), player(playerP)
{
	player->setPosition(grids->GetPlayerStartPos(4));
}

void WarriorManager::updateActor(float dt)
{
	player->TestWallGridCol(grids->GetWallsGridComp());
}