#include "GridComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Utils/Maths.h>

GridComponent::GridComponent(Actor* ownerP, int drawOrderP) : DrawComponent(ownerP, drawOrderP)
{
	tileTraduction.push_back(new TileTraduction);
}

GridComponent::~GridComponent()
{
}

void GridComponent::setGridSize(int gridWidthP, int gridHeightP)
{
	if (gridWidthP > 0 && gridHeightP > 0)
	{
		vector<int> new_grid;
		new_grid.resize(gridWidthP * gridHeightP);

		for (int i = 0; i < gridWidthP; i++)
		{
			for (int j = 0; j < gridHeightP; j++)
			{
				if (i < gridWidth && j < gridHeight)
				{
					new_grid[i * gridHeightP + j] = grid[i * gridHeight + j];
				}
				else
				{
					new_grid[i * gridHeightP + j] = 0;
				}
			}
		}

		grid.resize(gridWidthP * gridHeightP);
		grid = new_grid;

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

void GridComponent::setTileTraduction(int traductionIndex, TileTraduction* traduction)
{
	if (traductionIndex >= 0)
	{
		int draw_traduction_size = tileTraduction.size();
		if (traductionIndex >= draw_traduction_size)
		{
			tileTraduction.resize(traductionIndex + 1);
			for (int i = draw_traduction_size; i <= traductionIndex; i++)
			{
				tileTraduction[i] = new TileTraduction;
			}
		}

		tileTraduction[traductionIndex] = traduction;
	}
}

TileTraduction* GridComponent::getTileTraduction(int traductionIndex) const
{
	if (traductionIndex >= 0 && traductionIndex < tileTraduction.size())
	{
		return tileTraduction[traductionIndex];
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

	int tile_pos_intersection_x = 0, tile_pos_intersection_y = 0;

	if (point.x < grid_origin_screen_pos.x || point.x > grid_origin_screen_pos.x + (gridWidth * tileSize.x))
	{
		tile_pos_intersection_x = -1;
	}
	if (point.y < grid_origin_screen_pos.y || point.y > grid_origin_screen_pos.y + (gridHeight * tileSize.y))
	{
		tile_pos_intersection_y = -1;
	}

	if (tile_pos_intersection_x == 0)
	{
		tile_pos_intersection_x = Maths::floor((point.x - grid_origin_screen_pos.x) / tileSize.x);
	}
	if (tile_pos_intersection_y == 0)
	{
		tile_pos_intersection_y = Maths::floor((point.y - grid_origin_screen_pos.y) / tileSize.y);
	}

	if (gridPosReturnX) *gridPosReturnX = tile_pos_intersection_x;
	if (gridPosReturnY) *gridPosReturnY = tile_pos_intersection_y;


	if (tile_pos_intersection_x == -1 || tile_pos_intersection_y == -1 || tile_pos_intersection_x == gridWidth || tile_pos_intersection_y == gridHeight)
	{
		return false;
	}

	return tileTraduction[grid[tile_pos_intersection_x * gridHeight + tile_pos_intersection_y]]->colTraduction;
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
						tileTraduction[grid[i * gridHeight + j]]->drawTraduction->draw(renderer, tile, grid[i * gridHeight + j]);
					}
				}
			}
		}
	}
}

void GridComponent::debug(Renderer& renderer)
{
	Vector2 mouse_pos = owner.getGame().getMousePosition();

	int intersection_x, intersection_y;
	if (intersectWithScreenPoint(mouse_pos, &intersection_x, &intersection_y))
	{
		Vector2 tile_pos = owner.getPosition() - owner.getGame().getCamera().getCamPos();
		Rectangle tile = Rectangle{ tile_pos.x + (intersection_x * tileSize.x), tile_pos.y + (intersection_y * tileSize.y), tileSize.x, tileSize.y };
		renderer.drawDebugTile(tile, Color::white);
	}
}
