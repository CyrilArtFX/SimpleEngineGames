#include "StoneshardScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/StoneshardManager.h"
#include "ActorsComponents/StoneshardPlayerInputs.h"
#include "ActorsComponents/StoneshardMap.h"
#include "ActorsComponents/StoneshardCamera.h"

void StoneshardScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Stoneshard/Assets/");

	Assets::loadTexture(game->getRenderer(), "AimDirOk.png", "aimDirOk");
	Assets::loadTexture(game->getRenderer(), "AimDirNotOk.png", "aimDirNotOk");
	Assets::loadTexture(game->getRenderer(), "DirPathfinding.png", "dirPathfinding");
	Assets::loadTexture(game->getRenderer(), "Player.png", "player");
	Assets::loadGridMap("StoneshardMapV1.lua", "mapV1");

	auto manager = new StoneshardManager();
	auto map = new StoneshardMap(Assets::getGridMap("mapV1"));

	auto player_inputs = new StoneshardPlayerInputs(manager, map);
}
