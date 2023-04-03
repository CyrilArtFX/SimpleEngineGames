#include "SpaceScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>

void SpaceScene::load(Game* game)
{
	Assets::setAssetsPath("Games/SpaceBattle/Assets/");



	game->getCamera().setCamPos(Vector2::zero);
}
