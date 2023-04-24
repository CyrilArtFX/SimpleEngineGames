#pragma once
#include <vector>
#include <unordered_map>
#include <SimpleEngine/Maths/Vector2Int.h>

struct Tile
{
	Vector2Int pos;
	int cost;
	int heuristic;
	int score;
	Vector2Int previousTilePos;
};

static class AStar
{
public:
	static std::vector<Vector2Int> AStarGridComp(const class GridComponent& grid, Vector2Int start, Vector2Int end, std::unordered_map<int, int> astarTraduction, bool reverseReturn, int heuristicValue = 10);
};

