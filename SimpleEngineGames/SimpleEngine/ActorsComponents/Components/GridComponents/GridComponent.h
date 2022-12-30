#pragma once
#include <SimpleEngine/ActorsComponents/Components/DrawComponent.h>
#include "GridTileDrawComponent.h"
#include <vector>
using std::vector;

class GridComponent : public DrawComponent
{
public:
	GridComponent(Actor* ownerP, int drawOrderP = 500);
	virtual ~GridComponent();
	GridComponent() = delete;
	GridComponent(const GridComponent&) = delete;
	GridComponent& operator=(const GridComponent&) = delete;

	void setGridSize(int gridWidthP, int gridHeightP);
	int getGridWidth() const { return gridWidth; }
	int getGridHeight() const { return gridHeight; }

	bool setGridElement(int indexX, int indexY, int element);
	int getGridElement(int indexX, int indexY) const;

	void setDrawTraduction(int traductionIndex, GridTileDrawComponent* traduction);
	GridTileDrawComponent* getDrawTraduction(int traductionIndex) const;

	void draw(Renderer& renderer) override;

private:
	int gridWidth{ 0 };
	int gridHeight{ 0 };

	vector<int> grid;
	vector<GridTileDrawComponent*> drawTraduction;
};

