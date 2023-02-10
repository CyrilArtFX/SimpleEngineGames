#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/GridComponents/GridComponent.h>

class RacingTrack : public Actor
{
public:
	RacingTrack(GridMap* gridMapP);
	RacingTrack(const RacingTrack&) = delete;
	RacingTrack& operator=(const RacingTrack&) = delete;

private:
	GridComponent* gridComp;
};

