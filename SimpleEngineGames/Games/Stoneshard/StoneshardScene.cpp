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
	Assets::loadTexture(game->getRenderer(), "Enemy.png", "enemy");
	Assets::loadGridMap("StoneshardMapV1.lua", "mapV1");
	Assets::loadGridMap("StoneshardMapV2.lua", "mapV2");
	Assets::loadTexture(game->getRenderer(), "Tiles/grass.png", "tile_grass");
	Assets::loadTexture(game->getRenderer(), "Tiles/bush.png", "tile_bush");
	Assets::loadTexture(game->getRenderer(), "Tiles/small_tree.png", "tile_small_tree");
	Assets::loadTexture(game->getRenderer(), "Tiles/tree_bottom.png", "tile_tree_bottom");
	Assets::loadTexture(game->getRenderer(), "Tiles/tree_middle.png", "tile_tree_middle");
	Assets::loadTexture(game->getRenderer(), "Tiles/tree_top.png", "tile_tree_top");
	Assets::loadTexture(game->getRenderer(), "Tiles/big_tree_bottom_left.png", "tile_big_tree_bottom_left");
	Assets::loadTexture(game->getRenderer(), "Tiles/big_tree_bottom_right.png", "tile_big_tree_bottom_right");
	Assets::loadTexture(game->getRenderer(), "Tiles/big_tree_middle_left.png", "tile_big_tree_middle_left");
	Assets::loadTexture(game->getRenderer(), "Tiles/big_tree_middle_right.png", "tile_big_tree_middle_right");
	Assets::loadTexture(game->getRenderer(), "Tiles/big_tree_top_left.png", "tile_big_tree_top_left");
	Assets::loadTexture(game->getRenderer(), "Tiles/big_tree_top_right.png", "tile_big_tree_top_right");

	auto manager = new StoneshardManager();
	auto map = new StoneshardMap(Assets::getGridMap("mapV2"));

	auto player_inputs = new StoneshardPlayerInputs(manager, map);
}
