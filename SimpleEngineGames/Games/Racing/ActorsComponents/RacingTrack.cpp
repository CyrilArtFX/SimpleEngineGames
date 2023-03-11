#include "RacingTrack.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Components/GridComponents/GridTileDrawRectangle.h>

RacingTrack::RacingTrack(GridMap* gridMapP)
{
	gridComp = new GridComponent(this, gridMapP);
	int screen_width = getGame().getScreenWidth();
	int screen_height = getGame().getScreenHeight();
	gridComp->setTileSize(Vector2{ static_cast<float>(screen_width) / gridMapP->getWidth(), static_cast<float>(screen_height) / gridMapP->getHeight() });
	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle(Color::blue, Rectangle{0.025f, 0.025f, 0.95f, 0.95f}), true });
}

Vector2 RacingTrack::GetPlayerStartPos(int startPosGridIndex)
{
	for (int x = 0; x < gridComp->getGridWidth(); x++)
	{
		for (int y = 0; y < gridComp->getGridHeight(); y++)
		{
			if (gridComp->getGridElement(x, y) == startPosGridIndex)
			{
				Vector2 tile_size = gridComp->getTileSize();
				return Vector2{ (x + 0.5f) * tile_size.x, (y + 0.5f) * tile_size.y };
			}
		}
	}

	return Vector2::zero;
}
