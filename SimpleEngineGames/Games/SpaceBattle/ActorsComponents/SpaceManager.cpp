#include "SpaceManager.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Assets/Assets.h>

SpaceManager::SpaceManager(SpaceShip* shipP, SpaceShot* shotP, SpaceUFO* ufoP) : Actor(), ship(shipP), shot(shotP), ufo(ufoP)
{
	textComp = new DrawTextComponent(this, Assets::getFont("pixeled15"), "Space Battle", Color::white, Vector2{ getGame().getScreenWidth() / 2.0f, getGame().getScreenHeight() - 50.0f }, true);
}

void SpaceManager::updateActor(float dt)
{
	ship->EdgeWrap();
	shot->EdgeWrap();
	ufo->EdgeWrap();

	if (getGame().isKeyPressed(SDL_MOUSE_LEFT))
	{
		shot->Fire(ship->getPosition(), ship->get2DRotation(), ship->GetVelocity(), dt);
	}

	if (shot->CheckForUFO(ufo->GetCol()))
	{
		ufo->Reset();
		textComp->setText("Enemy Blasted!");
	}
	else if (ship->CheckForUFO(ufo->GetCol()))
	{
		ship->Reset();
		textComp->setText("Player Crashed!");
	}

	shot->RunTimer(dt);
	ufo->RunTimer(dt);
}