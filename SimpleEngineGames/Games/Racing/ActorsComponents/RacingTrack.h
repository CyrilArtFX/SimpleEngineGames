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

	Vector2 GetPlayerStartPos(int startPosGridIndex);

private:
	GridComponent* gridComp;
};

