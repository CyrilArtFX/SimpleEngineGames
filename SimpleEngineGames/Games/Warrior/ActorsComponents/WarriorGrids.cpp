#include "WarriorGrids.h"
#include <SimpleEngine/Game.h>
#include <Components/GridComponents/GridTileDrawSprite.h>

WarriorGrids::WarriorGrids(GridMap* wallsGridMapP, GridMap* doorsGridMapP, GridMap* keysGridMapP) : Actor(), wallsGridMap(wallsGridMapP), doorsGridMap(doorsGridMapP), keysGridMap(keysGridMapP)
{
	int screen_width = getGame().getScreenWidth();
	int screen_height = getGame().getScreenHeight();

	wallsGridComp = new GridComponent(this, wallsGridMapP);
	wallsGridComp->setTileSize(Vector2{ static_cast<float>(screen_width) / wallsGridMapP->getWidth(), static_cast<float>(screen_height) / wallsGridMapP->getHeight() });
	SetDoorsAsWalls();

	wallsGridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_ground")), false });
	wallsGridComp->setTileTraduction(2, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_wall")), true });
	wallsGridComp->setTileTraduction(3, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("tile_wall")), true });
}

void WarriorGrids::ResetGrids()
{
	wallsGridComp->resetToGridMap(wallsGridMap);
	//doorsGridComp->resetToGridMap(doorsGridMap);
	//keysGridComp->resetToGridMap(keysGridMap);
	SetDoorsAsWalls();
}

Vector2 WarriorGrids::GetPlayerStartPos(int startPosGridIndex)
{
	for (int x = 0; x < wallsGridComp->getGridWidth(); x++)
	{
		for (int y = 0; y < wallsGridComp->getGridHeight(); y++)
		{
			if (wallsGridComp->getGridElement(x, y) == startPosGridIndex)
			{
				wallsGridComp->setGridElement(x, y, 1);
				Vector2 tile_size = wallsGridComp->getTileSize();
				return Vector2{ (x + 0.5f) * tile_size.x, (y + 0.5f) * tile_size.y };
			}
		}
	}

	return Vector2::zero;
}

void WarriorGrids::RemoveDoor(int doorGridPosX, int doorGridPosY)
{
	//doorsGridComp->setGridElement(doorGridPosX, doorGridPosY, 0);
	//wallsGridComp->setGridElement(doorGridPosX, doorGridPosY, 1);
}

void WarriorGrids::RemoveKey(int keyGridPosX, int keyGridPosY)
{
	//keysGridComp->setGridElement(keyGridPosX, keyGridPosY, 0);
}

void WarriorGrids::SetDoorsAsWalls()
{
	//  prendre chaque élément 1 de la grille des portes et mettre 3 aux mêmes coordinées sur la grille des murs
}