#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "BreakerBall.h"
#include "BreakerPaddle.h"
#include "BreakerGrid.h"

class BreakerManager : public Actor
{
public:
	BreakerManager(BreakerBall* ballP, BreakerPaddle* paddleP, BreakerGrid* gridP);
	BreakerManager() = delete;
	BreakerManager(const BreakerManager&) = delete;
	BreakerManager& operator=(const BreakerManager&) = delete;

	void updateActor(float dt) override;

private:
	BreakerBall* ball;
	BreakerPaddle* paddle;
	BreakerGrid* grid;

	int numberOfBricks;

	void ResetGrid();
};

