#include "StoneshardPlayerInputs.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Assets/Assets.h>
#include <Components/GridComponents/GridTileDrawSprite.h>
#include <SimpleEngine/Algorithms/AStar.h>
#include <SimpleEngine/Maths/Vector2Int.h>
#include "TurnBasedEnemy.h"
#include <vector>

StoneshardPlayerInputs::StoneshardPlayerInputs(StoneshardManager* managerP, StoneshardMap* mapP) : Actor(), manager(managerP), map(mapP)
{
	player = new TurnBasedPlayer(Assets::getTexture("player"));
	player->setPosition(Vector2{ 1232.0f, 720.0f });

	camera = new StoneshardCamera(player);

	GridComponent& map_grid = map->GetGridComp();

	aimDirGrid = new GridComponent(this, 1000);
	aimDirGrid->setTileSize(map_grid.getTileSize());
	aimDirGrid->setGridSize(map_grid.getGridSize());
	aimDirGrid->setTileTraduction(1, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("aimDirOk")), false });
	aimDirGrid->setTileTraduction(2, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("aimDirNotOk")), false });
	aimDirGrid->setTileTraduction(3, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("dirPathfinding")), false });

	manager->AddTurnBasedActor(player);

	auto enemy_1 = new TurnBasedEnemy(*player, map_grid, Vector2{ 336.0f, 720.0f }, 50176.0f);
	manager->AddTurnBasedActor(enemy_1);
	manager->AddEnemy(enemy_1);

	manager->ForceGlobalTurnAction();
}

void StoneshardPlayerInputs::updateActor(float dt)
{
	aimDirGrid->resetToZero();

	GridComponent& map_grid = map->GetGridComp();
	Vector2 mouse_pos = getGame().getMousePosition();

	bool aiming_enemy = false;
	vector<TurnBasedEnemy*> enemies = manager->GetEnemiesList();
	for (auto enemy : enemies)
	{
		if (!enemy->GetIsVisible()) continue;
		if (enemy->GetPlayerDetected()) player->ForceClearMovement();
		if (enemy->IsUnderMouse(mouse_pos)) aiming_enemy = true;
	}


	if (player->HasMovementWaiting())
	{
		if (getGame().isKeyPressed(SDL_MOUSE_LEFT))
		{
			player->ForceClearMovement();
		}

		if (!player->MovingBetweenTiles())
		{
			manager->PlayGlobalTurnAction();
		}



		int map_player_x, map_player_y = 0;
		map_grid.screenPointAsGridCoordinates(player->getPosition(), &map_player_x, &map_player_y);
		Vector2Int map_player = { map_player_x, map_player_y };
		if (map_player != lastDestinationRegistered)
		{
			std::vector<Vector2Int> dir_way = AStar::AStarGridComp(map_grid, map_player, lastDestinationRegistered, true);

			while (!dir_way.empty())
			{
				aimDirGrid->setGridElement(*(dir_way.end() - 1), 3);
				dir_way.pop_back();
			}
		}
	}
	else
	{
		if (player->IsUnderMouse(mouse_pos)) return;
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
					if (getGame().isKeyPressed(SDL_MOUSE_LEFT))
					{
						std::vector<Vector2> move_list;
						Vector2 grid_tile_size = map_grid.getTileSize();
						for (auto iter : dir_way)
						{
							move_list.push_back(Vector2{ iter.x * grid_tile_size.x + grid_tile_size.x / 2.0f , iter.y * grid_tile_size.y + grid_tile_size.y / 2.0f });
						}
						std::reverse(move_list.begin(), move_list.end());

						player->SetMovementList(move_list);
						lastDestinationRegistered = map_mouse;
						manager->PlayGlobalTurnAction();
					}

					if (!aiming_enemy)
					{
						aimDirGrid->setGridElement(map_mouse_x, map_mouse_y, 1);
					}
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
}
