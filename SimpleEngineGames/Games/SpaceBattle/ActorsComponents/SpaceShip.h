#pragma once
#include "SpaceActor.h"
#include "SpaceShipMoveComponent.h"

class SpaceShip : public SpaceActor
{
public:
	SpaceShip(Texture& shipTextureP);
	SpaceShip() = delete;
	SpaceShip(const SpaceShip&) = delete;
	SpaceShip operator=(const SpaceShip&) = delete;

	Vector2 GetVelocity();

private:
	SpaceShipMoveComponent* moveComp;
};

