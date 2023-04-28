#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "TurnBasedPlayer.h"
#include "StoneshardManager.h"
#include "StoneshardMap.h"
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

	
	GridComponent* aimDirGrid;
};

