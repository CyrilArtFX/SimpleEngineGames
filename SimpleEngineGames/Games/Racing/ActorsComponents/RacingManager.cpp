#include "RacingManager.h"
#include <iostream>

RacingManager::RacingManager(RacingTrack* trackP, PlayerCar* playerOneCarP, PlayerCar* playerTwoCarP) : Actor(), track(trackP), playerOneCar(playerOneCarP), playerTwoCar(playerTwoCarP)
{
	playerOneCar->setPosition(track->GetPlayerStartPos(6));
	playerTwoCar->setPosition(track->GetPlayerStartPos(6));
}

void RacingManager::updateActor(float dt)
{
	playerOneCar->TestGridCol(track->GetGridComp());
	playerTwoCar->TestGridCol(track->GetGridComp());
}
