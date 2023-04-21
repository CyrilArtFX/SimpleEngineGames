#pragma once
#include <SimpleEngine/ActorsComponents/Components/DrawComponents/DrawComponent.h>
#include "GridTileDraw.h"
#include <SimpleEngine/Assets/GridMap.h>
#include <vector>
#include <unordered_map>
#include <SimpleEngine/Maths/Vector2Int.h>
using std::vector;
using std::unordered_map;


struct TileTraduction
{
	GridTileDraw* drawTraduction{ new GridTileDraw() };
	bool colTraduction{ false };
};



//  grid does not support scale currently

class GridComponent : public DrawComponent
{
public:
	GridComponent(Actor* ownerP, int drawOrderP = 10);
	GridComponent(Actor* ownerP, GridMap* gridMap, int drawOrderP = 10);
	virtual ~GridComponent();
	GridComponent() = delete;
	GridComponent(const GridComponent&) = delete;
	GridComponent& operator=(const GridComponent&) = delete;

	void resetToGridMap(GridMap* gridMap);
	void setGridSize(int gridWidthP, int gridHeightP);
	void setGridSize(Vector2Int gridSizeP);
	int getGridWidth() const { return gridWidth; }
	int getGridHeight() const { return gridHeight; }
	Vector2Int getGridSize() const { return Vector2Int{ gridWidth, gridHeight }; }

	bool setGridElement(int indexX, int indexY, int element);
	int getGridElement(int indexX, int indexY) const;
	bool setGridElement(Vector2Int index, int element);
	int getGridElement(Vector2Int index) const;

	void setTileTraduction(int traductionIndex, TileTraduction* traduction);
	TileTraduction* getTileTraduction(int traductionIndex) const;

	void setTileSize(Vector2 tileSizeP);
	Vector2 getTileSize() const { return tileSize; }

	/* Will return true depending of the tile traduction of the intersected tile */
	bool intersectWithScreenPoint(Vector2 point, int* gridPosReturnX = NULL, int* gridPosReturnY = NULL);

	/* Will return true if at least one of the intersected tiles has a true collision traduction
	   GridPosReturn will be set as the nearest true collision tile of the center of circle */
	bool intersectWithCircleCol(const class CircleCollisionComponent& circle, int* gridPosReturnX = NULL, int* gridPosReturnY = NULL);

	/* Will return true if at least one of the intersected tiles has a true collision traduction
	   GridPosReturn will be set as the nearest true collision tile of the center of rectangle */
	bool intersectWithRectangleCol(const class RectangleCollisionComponent& rectangle, int* gridPosReturnX = NULL, int* gridPosReturnY = NULL);

	/* Will set the gridPosReturns as the grid pos of the point
	   Will return true if those grid pos are out of the grid */
	bool screenPointAsGridCoordinates(Vector2 point, int* gridPosReturnX, int* gridPosReturnY);

	void draw(Renderer& renderer) override;
	void debug(Renderer& renderer) override;

private:
	int gridWidth{ 0 };
	int gridHeight{ 0 };

	Vector2 tileSize{ Vector2::zero };

	vector<int> grid;
	vector<TileTraduction*> tileTraduction;
	unordered_map<int, int> astarTraduction;

	class RectangleCollisionComponent* gridRectCol;

	Vector2 screenSize;


	void resetGridRectCol();
};

