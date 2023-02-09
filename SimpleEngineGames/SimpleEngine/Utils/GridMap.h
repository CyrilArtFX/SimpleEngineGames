#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class GridMap
{
public:
	GridMap(string pathP, vector<int> gridMapP);
	GridMap() = default;
	static GridMap* load(const string& pathP);

	string getPath() const { return path; }
	vector<int> getMap() const { return gridMap; }

private:
	string path{ "" };
	vector<int> gridMap;
};

