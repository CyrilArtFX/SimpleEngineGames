#include "AStarDemo.h"
#include <SimpleEngine/Algorithms/AStar.h>
#include <Components/GridComponents/GridTileDrawRectangle.h>
#include <SimpleEngine/Game.h>
#include <vector>

AStarDemo::AStarDemo(GridMap* gridMapP, Vector2 tileSizeP) : gridMap(gridMapP)
{
	gridComp = new GridComponent(this, gridMapP, 500);

	gridComp->setTileSize(tileSizeP);

	gridComp->setTileTraduction(0, new TileTraduction{ new GridTileDrawRectangle(Color::transparency, Rectangle::unitRect), true });
	gridComp->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle(Color::white, Rectangle::unitRect), false });
	gridComp->setTileTraduction(2, new TileTraduction{ new GridTileDrawRectangle(Color::green, Rectangle::unitRect), true });
	gridComp->setTileTraduction(3, new TileTraduction{ new GridTileDrawRectangle(Color::blue, Rectangle::unitRect), true });
	gridComp->setTileTraduction(4, new TileTraduction{ new GridTileDrawRectangle(Color::cyan, Rectangle::unitRect), true });

	gridComp->setAstarTraduction(3, AstarTraduction{ true, 10, 14 });
}

void AStarDemo::updateActor(float dt)
{
	Vector2Int grid_mouse;

	if (getGame().isKeyPressed(SDL_MOUSE_LEFT))
	{
		if (gridComp->intersectWithScreenPoint(getGame().getMousePosition(), &grid_mouse.x, &grid_mouse.y))
		{
			if (startPos == grid_mouse)
			{
				startPos = Vector2Int{ -1, -1 };
				ResetGrid();
			}
			else
			{
				startPos = grid_mouse;
				ResetGrid();
				
				AStar();
			}
		}
	}

	if (getGame().isKeyPressed(SDL_MOUSE_RIGHT))
	{
		if (gridComp->intersectWithScreenPoint(getGame().getMousePosition(), &grid_mouse.x, &grid_mouse.y))
		{
			if (endPos == grid_mouse)
			{
				endPos = Vector2Int{ -1, -1 };
				ResetGrid();
			}
			else
			{
				endPos = grid_mouse;
				ResetGrid();

				AStar();
			}
		}
	}
}

void AStarDemo::ResetGrid()
{
	gridComp->resetToGridMap(gridMap);

	if (startPos.x >= 0 && startPos.x < gridComp->getGridWidth() && startPos.y >= 0 && startPos.y < gridComp->getGridHeight())
	{
		gridComp->setGridElement(startPos, 2);
	}

	if (endPos.x >= 0 && endPos.x < gridComp->getGridWidth() && endPos.y >= 0 && endPos.y < gridComp->getGridHeight())
	{
		gridComp->setGridElement(endPos, 3);
	}
}

void AStarDemo::AStar()
{
	if (startPos.x < 0 || startPos.x >= gridComp->getGridWidth() || startPos.y < 0 || startPos.y >= gridComp->getGridHeight() ||
		endPos.x < 0 || endPos.x >= gridComp->getGridWidth() || endPos.y < 0 || endPos.y >= gridComp->getGridHeight()) return;
		
	std::vector<Vector2Int> way = AStar::AStarGridComp(*gridComp, startPos, endPos, true);

	way.pop_back();

	while (!way.empty())
	{
		gridComp->setGridElement(*(way.end() - 1), 4);
		way.pop_back();
	}
}
