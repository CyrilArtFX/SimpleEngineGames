#include "AStar.h"
#include <Components/GridComponents/GridComponent.h>
#include <algorithm>

bool compareTiles(const Tile& a, const Tile& b)
{
	return b.score < a.score;
}

std::vector<Vector2Int> AStar::AStarGridComp(const GridComponent& grid, Vector2Int start, Vector2Int end, std::unordered_map<int, int> astarTraduction)
{
	Vector2Int grid_size = grid.getGridSize();
	std::vector<Vector2Int> way;
	way.push_back(start);

	if (start.x < 0 || start.x >= grid_size.x || start.y < 0 || start.y >= grid_size.y ||
		end.x < 0 || end.x >= grid_size.x || end.y < 0 || end.y >= grid_size.y || start == end)
	{
		return way; //  will return a "no way" if astar can't be compute with those start and end on this grid
	}


	std::unordered_map<Vector2Int, Tile, Vector2IntHash, Vector2IntEqual> checked_tiles;
	std::vector<Tile> registered_tiles;
	std::unordered_map<Vector2Int, Tile, Vector2IntHash, Vector2IntEqual> already_registered_tiles;

	registered_tiles.push_back(Tile{ start, 0, 0, 0, start });
	Tile current_check;

	while (registered_tiles.size() > 0) //  will run while there is accessible nodes to check (will return before if it finds a way)
	{
		std::sort(registered_tiles.begin(), registered_tiles.end(), compareTiles); //  put the lowest score node at the end of the list
		current_check = *(registered_tiles.end() - 1); //  select the lowest score node

		if (current_check.pos == end) //  check if the lowest score node is the end node
		{
			//  TODO : fill way with the way from start (excluded) to end (included)

			return way;
		}

		//  TODO : for loops to check all tiles adjacents to the current checked tile

		checked_tiles[current_check.pos] = current_check; //  add the current checked tile to the list of checked tiles before switching to a new check
	}

	return way; //  will return a "no way" if there is no way possible from start to end on this grid
}
