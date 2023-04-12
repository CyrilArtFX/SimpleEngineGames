#include "SpaceManager.h"
#include <SimpleEngine/Game.h>

SpaceManager::SpaceManager(SpaceShip* shipP, SpaceShot* shotP) : Actor(), ship(shipP), shot(shotP)
{
}

void SpaceManager::updateActor(float dt)
{
	ship->EdgeWrap();
	shot->EdgeWrap();

	if (getGame().isKeyPressed(SDL_MOUSE_LEFT))
	{
		shot->Fire(ship->getPosition(), ship->get2DRotation(), ship->GetVelocity(), dt);
	}

	//shot->CheckForUFO();
	shot->RunTimer(dt);
}