#include "SpaceScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/SpaceShip.h"
#include "ActorsComponents/SpaceShot.h"
#include "ActorsComponents/SpaceManager.h"

void SpaceScene::load(Game* game)
{
	Assets::setAssetsPath("Games/SpaceBattle/Assets/");

	Assets::loadTexture(game->getRenderer(), "ship.png", "ship");
	Assets::loadTexture(game->getRenderer(), "ufo.png", "ufo");
	Assets::loadTexture(game->getRenderer(), "shot.png", "shot");

	auto player = new SpaceShip(Assets::getTexture("ship"));

	auto shot = new SpaceShot(Assets::getTexture("shot"), 400.0f, 1.0f);

	auto manager = new SpaceManager(player, shot);

	game->getCamera().setCamPos(Vector2::zero);
}
