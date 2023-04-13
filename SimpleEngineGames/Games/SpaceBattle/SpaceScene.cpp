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
	Assets::loadFont("pixeled.ttf", "pixeled15", 15);

	float scale_factor = 2.0f;

	auto player = new SpaceShip(Assets::getTexture("ship"), scale_factor);

	auto shot = new SpaceShot(Assets::getTexture("shot"), 400.0f, 1.0f, scale_factor);

	auto ufo = new SpaceUFO(Assets::getTexture("ufo"), 150.0f, 2.3f, scale_factor);

	auto manager = new SpaceManager(player, shot, ufo);

	game->getCamera().setCamPos(Vector2::zero);
}
