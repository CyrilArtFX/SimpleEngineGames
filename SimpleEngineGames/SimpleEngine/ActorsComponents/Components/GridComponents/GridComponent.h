#pragma once
#include <SimpleEngine/ActorsComponents/Components/DrawComponent.h>
#include "GridTileDraw.h"
#include <vector>
using std::vector;


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
	virtual ~GridComponent();
	GridComponent() = delete;
	GridComponent(const GridComponent&) = delete;
	GridComponent& operator=(const GridComponent&) = delete;

	void setGridSize(int gridWidthP, int gridHeightP);
	int getGridWidth() const { return gridWidth; }
	int getGridHeight() const { return gridHeight; }

	bool setGridElement(int indexX, int indexY, int element);
	int getGridElement(int indexX, int indexY) const;

	void setTileTraduction(int traductionIndex, TileTraduction* traduction);
	TileTraduction* getTileTraduction(int traductionIndex) const;

	void setTileSize(Vector2 tileSizeP);
	Vector2 getTileSize() const { return tileSize; }

	//  will return true depending of the tile traduction of the intersected tile
	bool intersectWithScreenPoint(Vector2 point, int* gridPosReturnX = NULL, int* gridPosReturnY = NULL);

	void draw(Renderer& renderer) override;
	void debug(Renderer& renderer) override;

private:
	int gridWidth{ 0 };
	int gridHeight{ 0 };

	Vector2 tileSize{ Vector2::zero };

	vector<int> grid;
	vector<TileTraduction*> tileTraduction;
};

