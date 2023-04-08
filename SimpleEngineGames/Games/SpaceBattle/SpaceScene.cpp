#include "SpaceScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>

void SpaceScene::load(Game* game)
{
	Assets::setAssetsPath("Games/SpaceBattle/Assets/");

	Assets::loadTexture(game->getRenderer(), "ship.png", "ship");
	Assets::loadTexture(game->getRenderer(), "ufo.png", "ufo");
	Assets::loadTexture(game->getRenderer(), "shot.png", "shot");


	game->getCamera().setCamPos(Vector2::zero);
}
