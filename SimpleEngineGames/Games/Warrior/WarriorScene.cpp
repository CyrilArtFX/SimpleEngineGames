#include "WarriorScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/WarriorManager.h"
#include "ActorsComponents/WarriorPlayer.h"
#include "ActorsComponents/WarriorGrids.h"

void WarriorScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Warrior/Assets/");

	Assets::loadGridMap("WarriorGroundWalls.lua", "grid_walls");
	Assets::loadGridMap("WarriorDoors.lua", "grid_doors");
	Assets::loadGridMap("WarriorKeys.lua", "grid_keys");
	Assets::loadTexture(game->getRenderer(), "warrior.png", "warrior");
	Assets::loadTexture(game->getRenderer(), "trophy.png", "trophy");
	Assets::loadTexture(game->getRenderer(), "tile_ground.png", "tile_ground");
	Assets::loadTexture(game->getRenderer(), "tile_wall.png", "tile_wall");
	Assets::loadTexture(game->getRenderer(), "door.png", "tile_door");
	Assets::loadTexture(game->getRenderer(), "key.png", "tile_key");

	auto grids = new WarriorGrids(Assets::getGridMap("grid_walls"), Assets::getGridMap("grid_doors"), Assets::getGridMap("grid_keys"));

	auto player = new WarriorPlayer(Assets::getTexture("warrior"));

	auto manager = new WarriorManager(grids, player);

	game->getCamera().setCamPos(Vector2::zero);
}