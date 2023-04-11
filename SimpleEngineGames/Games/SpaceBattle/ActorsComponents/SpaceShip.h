#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/CircleCollisionComponent.h>
#include "SpaceShipMoveComponent.h"

class SpaceShip : public Actor
{
public:
	SpaceShip(Texture& shipTextureP);
	SpaceShip() = delete;
	SpaceShip(const SpaceShip&) = delete;
	SpaceShip operator=(const SpaceShip&) = delete;

	void updateActor(float dt) override;


private:
	DrawSpriteComponent* drawSpriteComp;
	CircleCollisionComponent* circleColComp;
	SpaceShipMoveComponent* moveComp;
};

