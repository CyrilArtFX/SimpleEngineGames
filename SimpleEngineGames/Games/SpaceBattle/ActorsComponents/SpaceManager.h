#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "SpaceShip.h"
#include "SpaceShot.h"

class SpaceManager : public Actor
{
public:
	SpaceManager(SpaceShip* shipP, SpaceShot* shotP);
	SpaceManager() = delete;
	SpaceManager(SpaceManager&) = delete;
	SpaceManager& operator=(SpaceManager&) = delete;

	void updateActor(float dt) override;

private:
	SpaceShip* ship;
	SpaceShot* shot;
};

