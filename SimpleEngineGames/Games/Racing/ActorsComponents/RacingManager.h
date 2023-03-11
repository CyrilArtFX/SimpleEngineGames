#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "RacingTrack.h"
#include "PlayerCar.h"

class RacingManager : public Actor
{
public:
	RacingManager(RacingTrack* trackP, PlayerCar* playerOneCarP);
	RacingManager() = delete;
	RacingManager(const RacingManager&) = delete;
	RacingManager& operator=(const RacingManager&) = delete;

	void updateActor(float dt) override;

private:
	RacingTrack* track;
	PlayerCar* playerOneCar;
};

