#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "TurnBasedPlayer.h"
#include "StoneshardManager.h"
#include "StoneshardMap.h"
#include "StoneshardCamera.h"
#include <Components/GridComponents/GridComponent.h>

class StoneshardPlayerInputs : public Actor
{
public:
	StoneshardPlayerInputs(StoneshardManager* managerP, StoneshardMap* mapP);
	StoneshardPlayerInputs(const StoneshardPlayerInputs&) = delete;
	StoneshardPlayerInputs& operator=(const StoneshardPlayerInputs&) = delete;

	void updateActor(float dt) override;

private:
	StoneshardManager* manager;
	StoneshardMap* map;

	TurnBasedPlayer* player;
	StoneshardCamera* camera;

	GridComponent* aimDirGrid;

	Vector2Int lastDestinationRegistered{ Vector2Int::zero };
};

