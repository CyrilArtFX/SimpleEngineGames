#include "GridComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Maths/Maths.h>
#include <Components/CollisionComponents/CircleCollisionComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>

GridComponent::GridComponent(Actor* ownerP, int drawOrderP) : DrawComponent(ownerP, drawOrderP)
{
	tileTraduction.push_back(new TileTraduction);
	gridRectCol = new RectangleCollisionComponent(ownerP, false);
}

GridComponent::GridComponent(Actor* ownerP, GridMap* gridMap, int drawOrderP) : DrawComponent(ownerP, drawOrderP)
{
	tileTraduction.push_back(new TileTraduction);
	gridRectCol = new RectangleCollisionComponent(ownerP, false);

	resetToGridMap(gridMap);
}

GridComponent::~GridComponent()
{
}

void GridComponent::resetToGridMap(GridMap* gridMap)
{
	setGridSize(gridMap->getWidth(), gridMap->getHeight());
	vector<int> map_datas = gridMap->getMap();
	for (int i = 0; i < map_datas.size(); i++)
	{
		setGridElement(i % gridWidth, Maths::floor(i / gridWidth), map_datas[i]);
	}
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

		resetGridRectCol();
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

	resetGridRectCol();
}

bool GridComponent::intersectWithScreenPoint(Vector2 point, int* gridPosReturnX, int* gridPosReturnY)
{
	Vector2 grid_origin_screen_pos = owner.getPosition() - owner.getGame().getCamera().getCamPos();

	int tile_pos_intersection_x = Maths::floor((point.x - grid_origin_screen_pos.x) / tileSize.x);
	int tile_pos_intersection_y = Maths::floor((point.y - grid_origin_screen_pos.y) / tileSize.y);

	if (tile_pos_intersection_x < 0 || tile_pos_intersection_y < 0 || tile_pos_intersection_x >= gridWidth || tile_pos_intersection_y >= gridHeight)
	{
		return false;
	}

	if (gridPosReturnX) *gridPosReturnX = tile_pos_intersection_x;
	if (gridPosReturnY) *gridPosReturnY = tile_pos_intersection_y;

	int index = grid[tile_pos_intersection_x * gridHeight + tile_pos_intersection_y];
	if (index >= 0 && index < tileTraduction.size())
	{
		return tileTraduction[index]->colTraduction;
	}
	return false;
}

bool GridComponent::intersectWithCircleCol(const CircleCollisionComponent& circle, int* gridPosReturnX, int* gridPosReturnY)
{
	if (!gridRectCol->intersectWithCircleCollision(circle)) return false;

	Vector2 grid_origin_screen_pos = owner.getPosition() - owner.getGame().getCamera().getCamPos();
	Vector2 circle_center = circle.getCenter();
	float circle_radius = circle.getRadius();
	Vector2 up_left_corner = Vector2{ circle_center.x - circle_radius, circle_center.y - circle_radius };
	Vector2 down_right_corner = Vector2{ circle_center.x + circle_radius, circle_center.y + circle_radius };

	int tile_pos_up_left_x = Maths::floor((up_left_corner.x - grid_origin_screen_pos.x) / tileSize.x);
	int tile_pos_up_left_y = Maths::floor((up_left_corner.y - grid_origin_screen_pos.y) / tileSize.y);
	int tile_pos_down_right_x = Maths::floor((down_right_corner.x - grid_origin_screen_pos.x) / tileSize.x);
	int tile_pos_down_right_y = Maths::floor((down_right_corner.y - grid_origin_screen_pos.y) / tileSize.y);

	tile_pos_up_left_x = Maths::max(tile_pos_up_left_x, 0);
	tile_pos_up_left_y = Maths::max(tile_pos_up_left_y, 0);
	tile_pos_down_right_x = Maths::min(tile_pos_down_right_x, gridWidth - 1);
	tile_pos_down_right_y = Maths::min(tile_pos_down_right_y, gridHeight - 1);

	bool true_col_found = false;
	bool need_grid_pos_return = gridPosReturnX || gridPosReturnY;
	int nearest_true_col_sqlength = INT_MAX;

	for (int x = tile_pos_up_left_x; x <= tile_pos_down_right_x; x++)
	{
		for (int y = tile_pos_up_left_y; y <= tile_pos_down_right_y; y++)
		{
			int index = grid[x * gridHeight + y];
			if (index >= 0 && index < tileTraduction.size())
			{
				if (tileTraduction[index]->colTraduction)
				{
					float xf = static_cast<float>(x) * tileSize.x;
					float yf = static_cast<float>(y) * tileSize.y;
					gridRectCol->setRectangle(Rectangle{ grid_origin_screen_pos.x + xf, grid_origin_screen_pos.y + yf, xf + tileSize.x, yf + tileSize.y });
					if (!gridRectCol->intersectWithCircleCollision(circle)) continue;

					true_col_found = true;
					if (need_grid_pos_return)
					{
						Vector2 center_to_tile = Vector2{ grid_origin_screen_pos.x + (x * tileSize.x), grid_origin_screen_pos.y + (y * tileSize.y) } - circle_center;
						float sqlength = center_to_tile.lengthSq();
						if (sqlength < nearest_true_col_sqlength)
						{
							if (gridPosReturnX) *gridPosReturnX = x;
							if (gridPosReturnY) *gridPosReturnY = y;
							nearest_true_col_sqlength = sqlength;
						}
					}
					else
					{
						resetGridRectCol();
						return true;
					}
				}
			}
		}
	}

	resetGridRectCol();
	return true_col_found;
}

bool GridComponent::intersectWithRectangleCol(const RectangleCollisionComponent& rectangle, int* gridPosReturnX, int* gridPosReturnY)
{
	if (!gridRectCol->intersectWithRectCollision(rectangle)) return false;

	Vector2 grid_origin_screen_pos = owner.getPosition() - owner.getGame().getCamera().getCamPos();
	Rectangle scaled_rect = rectangle.getTransformedRectangle();
	Vector2 rect_center = Vector2{ scaled_rect.x + (scaled_rect.width / 2.0f), scaled_rect.y + (scaled_rect.height / 2.0f) };
	Vector2 up_left_corner = Vector2{ scaled_rect.x, scaled_rect.y };
	Vector2 down_right_corner = Vector2{ scaled_rect.x + scaled_rect.width, scaled_rect.y + scaled_rect.height };

	int tile_pos_up_left_x = Maths::floor((up_left_corner.x - grid_origin_screen_pos.x) / tileSize.x);
	int tile_pos_up_left_y = Maths::floor((up_left_corner.y - grid_origin_screen_pos.y) / tileSize.y);
	int tile_pos_down_right_x = Maths::floor((down_right_corner.x - grid_origin_screen_pos.x) / tileSize.x);
	int tile_pos_down_right_y = Maths::floor((down_right_corner.y - grid_origin_screen_pos.y) / tileSize.y);

	tile_pos_up_left_x = Maths::max(tile_pos_up_left_x, 0);
	tile_pos_up_left_y = Maths::max(tile_pos_up_left_y, 0);
	tile_pos_down_right_x = Maths::min(tile_pos_down_right_x, gridWidth - 1);
	tile_pos_down_right_y = Maths::min(tile_pos_down_right_y, gridHeight - 1);

	bool true_col_found = false;
	bool need_grid_pos_return = gridPosReturnX || gridPosReturnY;
	int nearest_true_col_sqlength = INT_MAX;

	for (int x = tile_pos_up_left_x; x <= tile_pos_down_right_x; x++)
	{
		for (int y = tile_pos_up_left_y; y <= tile_pos_down_right_y; y++)
		{
			int index = grid[x * gridHeight + y];
			if (index >= 0 && index < tileTraduction.size())
			{
				if (tileTraduction[index]->colTraduction)
				{
					true_col_found = true;
					if (need_grid_pos_return)
					{
						Vector2 center_to_tile = Vector2{ grid_origin_screen_pos.x + (x * tileSize.x), grid_origin_screen_pos.y + (y * tileSize.y) } - rect_center;
						float sqlength = center_to_tile.lengthSq();
						if (sqlength < nearest_true_col_sqlength)
						{
							if (gridPosReturnX) *gridPosReturnX = x;
							if (gridPosReturnY) *gridPosReturnY = y;
							nearest_true_col_sqlength = sqlength;
						}
					}
					else
					{
						return true;
					}
				}
			}
		}
	}

	return true_col_found;
}

void GridComponent::draw(Renderer& renderer)
{
	if (!willDraw) return;
	if (gridWidth <= 0 || gridHeight <= 0) return;
	if (tileSize.x <= 0 || tileSize.y <= 0) return;

	Vector2 grid_origin = owner.getPosition() - owner.getGame().getCamera().getCamPos();

	float tile_rect_orig_y = grid_origin.y;
	for (int y = 0; y < gridHeight; y++)
	{
		float tile_rect_orig_x = grid_origin.x;
		for (int x = 0; x < gridWidth; x++)
		{
			Rectangle tile = Rectangle{ tile_rect_orig_x, tile_rect_orig_y, tileSize.x, tileSize.y };
			int index = grid[x * gridHeight + y];
			if (index >= 0 && index < tileTraduction.size())
			{
				tileTraduction[index]->drawTraduction->draw(renderer, tile, index);
			}

			tile_rect_orig_x += tileSize.x;
		}

		tile_rect_orig_y += tileSize.y;
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

void GridComponent::resetGridRectCol()
{
	gridRectCol->setRectangle(Rectangle{ 0.0f, 0.0f, gridWidth * tileSize.x, gridHeight * tileSize.y });
}
