#include "BreakerManager.h"

BreakerManager::BreakerManager(BreakerBall* ballP, BreakerPaddle* paddleP) : Actor(), ball(ballP), paddle(paddleP)
{
}

void BreakerManager::updateActor(float dt)
{
	ball->TestPaddleCollision(paddle->GetCol());
}