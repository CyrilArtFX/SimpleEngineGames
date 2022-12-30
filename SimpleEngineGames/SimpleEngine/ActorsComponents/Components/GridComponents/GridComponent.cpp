#include "GridComponent.h"

GridComponent::GridComponent(Actor* ownerP, int drawOrderP) : DrawComponent(ownerP, drawOrderP)
{
	drawTraduction[0] = new GridTileDrawComponent();
}

GridComponent::~GridComponent()
{
}

void GridComponent::setGridSize(int gridWidthP, int gridHeightP)
{
	if (gridWidthP > 0 && gridHeightP > 0)
	{
		vector<int> newGrid;
		newGrid.resize(gridWidthP * gridHeightP);

		for (int i = 0; i < gridWidthP; i++)
		{
			for (int j = 0; j < gridHeightP; j++)
			{
				if (i < gridWidth && j < gridHeight)
				{
					newGrid[i * gridHeightP + j] = grid[i * gridHeight + j];
				}
				else
				{
					newGrid[i * gridHeightP + j] = 0;
				}
			}
		}

		grid.resize(gridWidthP * gridHeightP);
		grid = newGrid;

		gridWidth = gridWidthP;
		gridHeight = gridHeightP;
	}
}

bool GridComponent::setGridElement(int indexX, int indexY, int element)
{
	if (gridWidth > 0 && gridHeight > 0)
	{
		if (indexX >= 0 && indexX < gridWidth && indexY >= 0 && indexY < gridHeight)
		{
			grid[indexX * gridHeight + indexY] = element;
			return true;
		}
	}
	return false;
}

int GridComponent::getGridElement(int indexX, int indexY) const
{
	if (gridWidth > 0 && gridHeight > 0)
	{
		if (indexX >= 0 && indexX < gridWidth && indexY >= 0 && indexY < gridHeight)
		{
			return grid[indexX * gridHeight + indexY];
		}
	}
	return -1;
}

void GridComponent::setDrawTraduction(int traductionIndex, GridTileDrawComponent* traduction)
{
	if (traductionIndex >= 0)
	{
		int drawTraductionSize = drawTraduction.size();
		if (traductionIndex >= drawTraductionSize)
		{
			drawTraduction.resize(traductionIndex + 1);
			for (int i = drawTraductionSize; i <= traductionIndex; i++)
			{
				drawTraduction[traductionIndex] = new GridTileDrawComponent();
			}
		}

		drawTraduction[traductionIndex] = traduction;
	}
}

GridTileDrawComponent* GridComponent::getDrawTraduction(int traductionIndex) const
{
	if (traductionIndex >= 0 && traductionIndex < drawTraduction.size())
	{
		return drawTraduction[traductionIndex];
	}
	else
	{
		return nullptr;
	}
}

void GridComponent::draw(Renderer& renderer)
{
	if (gridWidth > 0 && gridHeight > 0)
	{
		for (int i = 0; i < gridWidth; i++)
		{
			for (int j = 0; j < gridHeight; j++)
			{
				//  get element 'i * gridHeight + j' of the grid
				//  and draw it's traduction
			}
		}
	}
}
