#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/GridComponents/GridComponent.h>
#include <SimpleEngine/Maths/Vector2.h>
#include <SimpleEngine/Maths/Vector2Int.h>

class AStarDemo : public Actor
{
public:
	AStarDemo(GridMap* gridMapP, Vector2 tileSizeP);
	AStarDemo() = delete;
	AStarDemo(AStarDemo&) = delete;
	AStarDemo& operator=(AStarDemo&) = delete;

	void updateActor(float dt) override;

private:
	void ResetGrid();
	void AStar();

	GridComponent* gridComp;
	GridMap* gridMap;

	Vector2Int startPos{ -1, -1 };
	Vector2Int endPos{ -1,-1 };
};

