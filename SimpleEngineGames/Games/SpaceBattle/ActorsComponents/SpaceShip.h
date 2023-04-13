#pragma once
#include "SpaceActor.h"
#include "SpaceShipMoveComponent.h"

class SpaceShip : public SpaceActor
{
public:
	SpaceShip(Texture& shipTextureP, float ScaleFactorP);
	SpaceShip() = delete;
	SpaceShip(const SpaceShip&) = delete;
	SpaceShip operator=(const SpaceShip&) = delete;

	void Reset();

	Vector2 GetVelocity();
	bool CheckForUFO(CircleCollisionComponent& ufoCollision);

private:
	SpaceShipMoveComponent* moveComp;
};

