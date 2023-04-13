#pragma once
#include "SpaceActor.h"
#include <Components/MoveComponents/VelocityMoveComponent.h>

class SpaceUFO : public SpaceActor
{
public:
	SpaceUFO(Texture& ufoTextureP, float speedP, float timePerDirectionP, float ScaleFactorP);
	SpaceUFO() = delete;
	SpaceUFO(const SpaceUFO&) = delete;
	SpaceUFO& operator=(const SpaceUFO&) = delete;

	void Reset();

	void RunTimer(float deltaTime);
	CircleCollisionComponent& GetCol() { return *circleColComp; }

private:
	void ChangeDirection();

	VelocityMoveComponent* moveComp;

	float timePerDirection;
	float cooldown{ 0.0f };
};

