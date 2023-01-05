#include "GridComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/Game.h>

GridComponent::GridComponent(Actor* ownerP, int drawOrderP) : DrawComponent(ownerP, drawOrderP)
{
	drawTraduction.push_back(new GridTileDraw());
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

void GridComponent::setDrawTraduction(int traductionIndex, GridTileDraw* traduction)
{
	if (traductionIndex >= 0)
	{
		int drawTraductionSize = drawTraduction.size();
		if (traductionIndex >= drawTraductionSize)
		{
			drawTraduction.resize(traductionIndex + 1);
			for (int i = drawTraductionSize; i <= traductionIndex; i++)
			{
				drawTraduction[i] = new GridTileDraw();
			}
		}

		drawTraduction[traductionIndex] = traduction;
	}
}

GridTileDraw* GridComponent::getDrawTraduction(int traductionIndex) const
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

void GridComponent::setTileSize(Vector2 tileSizeP)
{
	tileSize = tileSizeP;
}

void GridComponent::draw(Renderer& renderer)
{
	if (willDraw)
	{
		if (gridWidth > 0 && gridHeight > 0)
		{
			if (tileSize.x > 0 && tileSize.y > 0)
			{
				for (int i = 0; i < gridWidth; i++)
				{
					for (int j = 0; j < gridHeight; j++)
					{
						Vector2 tilePos = owner.getPosition() - owner.getGame().getCamera().getCamPos();
						Rectangle tile = Rectangle{ tilePos.x + (i * tileSize.x), tilePos.y + (j * tileSize.y), tileSize.x, tileSize.y };
						drawTraduction[grid[i * gridHeight + j]]->draw(renderer, tile, grid[i * gridHeight + j]);
					}
				}
			}
		}
	}
}
