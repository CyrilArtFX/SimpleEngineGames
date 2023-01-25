#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/GridComponents/GridComponent.h>

class BreakerGrid : public Actor
{
public:
	BreakerGrid(int gridSizeX, int gridSizeY, Vector2 tileSize, Color tileColor);
	BreakerGrid() = delete;
	BreakerGrid(const BreakerGrid&) = delete;
	BreakerGrid& operator=(const BreakerGrid&) = delete;

	void ResetGrid();

	GridComponent* GetGrid() { return gridComp; }

private:
	GridComponent* gridComp;
};

