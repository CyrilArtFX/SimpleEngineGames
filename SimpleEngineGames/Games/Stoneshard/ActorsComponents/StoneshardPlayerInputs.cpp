#include "StoneshardPlayerInputs.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Assets/Assets.h>
#include <Components/GridComponents/GridTileDrawSprite.h>
#include <SimpleEngine/Algorithms/AStar.h>
#include <SimpleEngine/Maths/Vector2Int.h>
#include <vector>

StoneshardPlayerInputs::StoneshardPlayerInputs(StoneshardManager* managerP, StoneshardMap* mapP) : Actor(), manager(managerP), map(mapP)
{
	player = new TurnBasedPlayer(Assets::getTexture("player"));
	player->setPosition(Vector2{ 1232.0f, 720.0f });


	aimDirGrid = new GridComponent(this, 1000);
	aimDirGrid->setTileSize(map->GetGridComp().getTileSize());
	aimDirGrid->setGridSize(map->GetGridComp().getGridSize());
	aimDirGrid->setTileTraduction(1, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("aimDirOk")), false });
	aimDirGrid->setTileTraduction(2, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("aimDirNotOk")), false });
	aimDirGrid->setTileTraduction(3, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("dirPathfinding")), false });

	managerP->AddTurnBasedActor(player);

	managerP->ForceGlobalTurnAction();
}

void StoneshardPlayerInputs::updateActor(float dt)
{
	aimDirGrid->resetToZero();

	Vector2 mouse_pos = getGame().getMousePosition();

	if (player->IsUnderMouse(mouse_pos)) return;

	GridComponent& map_grid = map->GetGridComp();
	int map_mouse_x, map_mouse_y = 0;
	int map_player_x, map_player_y = 0;

	if (map_grid.intersectWithScreenPoint(mouse_pos, &map_mouse_x, &map_mouse_y))
	{
		Vector2Int map_mouse = { map_mouse_x, map_mouse_y };

		if (map_grid.getAstarTraduction(map_mouse_x, map_mouse_y).walkable)
		{
			map_grid.screenPointAsGridCoordinates(player->getPosition(), &map_player_x, &map_player_y);
			Vector2Int map_player = { map_player_x, map_player_y };

			std::vector<Vector2Int> dir_way = AStar::AStarGridComp(map_grid, map_player, map_mouse, true);

			if (dir_way.size() == 1 && dir_way[0] == map_player)
			{
				aimDirGrid->setGridElement(map_mouse_x, map_mouse_y, 2);
			}
			else
			{
				aimDirGrid->setGridElement(map_mouse_x, map_mouse_y, 1);
				dir_way.pop_back();
				while (!dir_way.empty())
				{
					aimDirGrid->setGridElement(*(dir_way.end() - 1), 3);
					dir_way.pop_back();
				}
			}
		}
		else
		{
			aimDirGrid->setGridElement(map_mouse_x, map_mouse_y, 2);
		}
	}
}
