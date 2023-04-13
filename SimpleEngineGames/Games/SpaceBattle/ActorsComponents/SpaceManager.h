#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "SpaceShip.h"
#include "SpaceShot.h"
#include "SpaceUFO.h"
#include <Components/DrawComponents/DrawTextComponent.h>

class SpaceManager : public Actor
{
public:
	SpaceManager(SpaceShip* shipP, SpaceShot* shotP, SpaceUFO* ufoP);
	SpaceManager() = delete;
	SpaceManager(SpaceManager&) = delete;
	SpaceManager& operator=(SpaceManager&) = delete;

	void updateActor(float dt) override;

private:
	SpaceShip* ship;
	SpaceShot* shot;
	SpaceUFO* ufo;

	DrawTextComponent* textComp;
};

