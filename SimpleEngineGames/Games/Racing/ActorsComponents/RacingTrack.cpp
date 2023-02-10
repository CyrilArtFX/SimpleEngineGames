#include "RacingTrack.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Components/GridComponents/GridTileDrawRectangle.h>

RacingTrack::RacingTrack(GridMap* gridMapP)
{
	gridComp = new GridComponent(this, gridMapP);
	int screen_width = getGame().getScreenWidth();
	int screen_height = getGame().getScreenHeight();
	gridComp->setTileSize(Vector2{ static_cast<float>(screen_width) / gridMapP->getWidth(),
		static_cast<float>(screen_height) / gridMapP->getHeight() });
	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle
		(Color::blue, Rectangle{0.025f, 0.025f, 0.95f, 0.95f}), true });
}
