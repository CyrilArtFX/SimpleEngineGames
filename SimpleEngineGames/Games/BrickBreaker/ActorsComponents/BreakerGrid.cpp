#include "BreakerGrid.h"
#include <Components/GridComponents/GridTileDrawRectangle.h>

BreakerGrid::BreakerGrid(int gridSizeX, int gridSizeY, Vector2 tileSize, Color tileColor)
{
	gridComp = new GridComponent(this);
	gridComp->setGridSize(gridSizeX, gridSizeY);
	gridComp->setTileSize(tileSize);
	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle(tileColor, Rectangle{0.0125f, 0.05f, 0.975f, 0.90f}), true });
}

void BreakerGrid::ResetGrid()
{
	int grid_size_x = gridComp->getGridWidth();
	int grid_size_y = gridComp->getGridHeight();

	for (int x = 0; x < grid_size_x; x++)
		for (int y = 0; y < grid_size_y; y++)
			gridComp->setGridElement(x, y, 1);
}
