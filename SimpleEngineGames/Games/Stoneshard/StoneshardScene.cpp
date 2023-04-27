#include "StoneshardScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/StoneshardManager.h"
#include "ActorsComponents/StoneshardPlayerInputs.h"

void StoneshardScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Stoneshard/Assets/");

	Assets::loadTexture(game->getRenderer(), "AimDirOk.png", "aimDirOk");
	Assets::loadTexture(game->getRenderer(), "AimDirNotOk.png", "aimDirNotOk");
	Assets::loadTexture(game->getRenderer(), "DirPathfinding.png", "dirPathfinding");
	Assets::loadTexture(game->getRenderer(), "Player.png", "player");

	auto manager = new StoneshardManager();

	auto player_inputs = new StoneshardPlayerInputs(manager);
}
