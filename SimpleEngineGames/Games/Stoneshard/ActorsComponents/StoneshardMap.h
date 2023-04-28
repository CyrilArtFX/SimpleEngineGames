#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/GridComponents/GridComponent.h>

class StoneshardMap : public Actor
{
public:
	StoneshardMap(GridMap* gridMapP);
	StoneshardMap() = delete;
	StoneshardMap(const StoneshardMap&) = delete;
	StoneshardMap& operator=(const StoneshardMap&) = delete;

	GridComponent& GetGridComp() { return *gridComp; }

private:
	GridComponent* gridComp;
};

