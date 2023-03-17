#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "RacingTrack.h"
#include "PlayerCar.h"
#include <Components/CollisionComponents/RectangleCollisionComponent.h>
#include <Components/DrawComponents/DrawTextComponent.h>

class RacingManager : public Actor
{
public:
	RacingManager(RacingTrack* trackP, PlayerCar* playerOneCarP, PlayerCar* playerTwoCarP);
	RacingManager() = delete;
	RacingManager(const RacingManager&) = delete;
	RacingManager& operator=(const RacingManager&) = delete;

	void updateActor(float dt) override;

private:
	void PauseGame(bool playerTwoWin);
	void ResumeGame();

	RacingTrack* track;
	PlayerCar* playerOneCar;
	PlayerCar* playerTwoCar;

	RectangleCollisionComponent* finishLineTrigger;
	DrawTextComponent* victoryTextComp;
	DrawTextComponent* resetTextComp;

	bool isPaused{ false };
};

