#include "StoneshardMap.h"
#include <Components/GridComponents/GridTileDrawRectangle.h>

StoneshardMap::StoneshardMap(GridMap* gridMapP)
{
	gridComp = new GridComponent(this, gridMapP);
	gridComp->setTileSize(Vector2{ 32.0f, 32.0f });

	gridComp->setTileTraduction(0, new TileTraduction{ new GridTileDrawRectangle(Color(154, 205, 50, 255), Rectangle::unitRect), true });
	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle(Color(34, 139, 34, 255), Rectangle::unitRect), true });
}