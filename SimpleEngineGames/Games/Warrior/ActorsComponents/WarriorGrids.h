#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/GridComponents/GridComponent.h>

class WarriorGrids: public Actor
{
public:
	WarriorGrids(GridMap* wallsGridMapP, GridMap* doorsGridMapP, GridMap* keysGridMapP);
	WarriorGrids() = delete;
	WarriorGrids(const WarriorGrids&) = delete;
	WarriorGrids operator=(const WarriorGrids&) = delete;

	void ResetGrids();
	Vector2 GetPlayerStartPos(int startPosGridIndex);

	GridComponent& GetWallsGridComp() { return *wallsGridComp; }
	//GridComponent& GetDoorsGridComp() { return *doorsGridComp; }
	//GridComponent& GetKeysGridComp() { return *keysGridComp; }

	void RemoveDoor(int doorGridPosX, int doorGridPosY);
	void RemoveKey(int keyGridPosX, int keyGridPosY);

private:
	void SetDoorsAsWalls();

	GridComponent* wallsGridComp;
	//GridComponent* doorsGridComp;
	//GridComponent* keysGridComp;

	GridMap* wallsGridMap;
	GridMap* doorsGridMap;
	GridMap* keysGridMap;
};

