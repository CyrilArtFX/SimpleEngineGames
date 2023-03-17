#include "RacingTrack.h"
#include <SimpleEngine/Game.h>
#include <Components/GridComponents/GridTileDrawSprite.h>

RacingTrack::RacingTrack(GridMap* gridMapP) : gridMap(gridMapP)
{
	gridComp = new GridComponent(this, gridMapP);
	int screen_width = getGame().getScreenWidth();
	int screen_height = getGame().getScreenHeight();
	gridComp->setTileSize(Vector2{ static_cast<float>(screen_width) / gridMapP->getWidth(), static_cast<float>(screen_height) / gridMapP->getHeight() });

	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("track_road")), false });
	gridComp->setTileTraduction(2, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("track_wall")), true });
	gridComp->setTileTraduction(3, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("track_goal")), false });
	gridComp->setTileTraduction(4, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("track_grass")), true });
	gridComp->setTileTraduction(5, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("track_flag")), true });
}

void RacingTrack::ResetTrack()
{
	gridComp->resetToGridMap(gridMap);
}

Vector2 RacingTrack::GetPlayerStartPos(int startPosGridIndex)
{
	for (int x = 0; x < gridComp->getGridWidth(); x++)
	{
		for (int y = 0; y < gridComp->getGridHeight(); y++)
		{
			if (gridComp->getGridElement(x, y) == startPosGridIndex)
			{
				gridComp->setGridElement(x, y, 1);
				Vector2 tile_size = gridComp->getTileSize();
				return Vector2{ (x + 0.5f) * tile_size.x, (y + 0.5f) * tile_size.y };
			}
		}
	}

	return Vector2::zero;
}
