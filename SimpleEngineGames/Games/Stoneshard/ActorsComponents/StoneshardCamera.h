#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "TurnBasedPlayer.h"
#include <unordered_map>


struct CameraClamp
{
	Vector2 clampMin;
	Vector2 clampMax;
};


class StoneshardCamera : public Actor
{
public:
	StoneshardCamera(TurnBasedPlayer* playerP);
	StoneshardCamera() = delete;
	StoneshardCamera(const StoneshardCamera&) = delete;
	StoneshardCamera& operator=(const StoneshardCamera&) = delete;

	void updateActor(float dt) override;

private:
	TurnBasedPlayer* player;
	Vector2 halfScreenSize;

	CameraClamp currentClamp;
	std::unordered_map <string, CameraClamp> registeredClamps;
};

