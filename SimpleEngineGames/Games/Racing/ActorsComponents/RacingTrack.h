#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/GridComponents/GridComponent.h>

class RacingTrack : public Actor
{
public:
	RacingTrack(GridMap* gridMapP);
	RacingTrack() = delete;
	RacingTrack(const RacingTrack&) = delete;
	RacingTrack& operator=(const RacingTrack&) = delete;

	void ResetTrack();
	Vector2 GetPlayerStartPos(int startPosGridIndex);
	GridComponent& GetGridComp() { return *gridComp; }

private:
	GridComponent* gridComp;
	GridMap* gridMap;
};

