#include "GridComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Utils/Maths.h>

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

bool GridComponent::intersectWithScreenPoint(Vector2 point, int* gridPosReturnX, int* gridPosReturnY)
{
	Vector2 grid_origin_screen_pos = owner.getPosition() - owner.getGame().getCamera().getCamPos();

	if (point.x < grid_origin_screen_pos.x || point.y < grid_origin_screen_pos.y)
	{
		return false;
	}
	if (point.x > grid_origin_screen_pos.x + (gridWidth * tileSize.x) || point.y > grid_origin_screen_pos.y + (gridHeight * tileSize.y))
	{
		return false;
	}

	int tile_pos_intersection_x = Maths::floor((point.x - grid_origin_screen_pos.x) / tileSize.x);
	int tile_pos_intersection_y = Maths::floor((point.y - grid_origin_screen_pos.y) / tileSize.y);

	*gridPosReturnX = tile_pos_intersection_x;
	*gridPosReturnY = tile_pos_intersection_y;

	return grid[tile_pos_intersection_x * gridHeight + tile_pos_intersection_y] != 0;
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
						Vector2 grid_origin = owner.getPosition() - owner.getGame().getCamera().getCamPos();
						Rectangle tile = Rectangle{ grid_origin.x + (i * tileSize.x), grid_origin.y + (j * tileSize.y), tileSize.x, tileSize.y };
						drawTraduction[grid[i * gridHeight + j]]->draw(renderer, tile, grid[i * gridHeight + j]);
					}
				}
			}
		}
	}
}

void GridComponent::debug(Renderer& renderer)
{
	//  actually just a test
	int mouse_pos_x, mouse_pos_y;
	SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y);
	Vector2 mouse_pos = Vector2{
		mouse_pos_x * 1.0f,
		mouse_pos_y * 1.0f
	};

	int intersection_x, intersection_y;
	if (intersectWithScreenPoint(mouse_pos, &intersection_x, &intersection_y))
	{
		Vector2 tilePos = owner.getPosition() - owner.getGame().getCamera().getCamPos();
		Rectangle tile = Rectangle{ tilePos.x + (intersection_x * tileSize.x), tilePos.y + (intersection_y * tileSize.y), tileSize.x, tileSize.y };
		renderer.drawDebugTile(tile, Color::white);
	}
}
