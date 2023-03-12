#include "RacingManager.h"
#include <iostream>

RacingManager::RacingManager(RacingTrack* trackP, PlayerCar* playerOneCarP) : Actor(), track(trackP), playerOneCar(playerOneCarP)
{
	playerOneCar->setPosition(track->GetPlayerStartPos(6));
}

void RacingManager::updateActor(float dt)
{
	playerOneCar->TestGridCol(track->GetGridComp());
}
