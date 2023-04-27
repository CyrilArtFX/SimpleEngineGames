#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "TurnBasedPlayer.h"
#include "StoneshardManager.h"

class StoneshardPlayerInputs : public Actor
{
public:
	StoneshardPlayerInputs(StoneshardManager* managerP);
	StoneshardPlayerInputs(StoneshardPlayerInputs&) = delete;
	StoneshardPlayerInputs& operator=(StoneshardPlayerInputs&) = delete;

	void updateActor(float dt) override;

private:
	StoneshardManager* manager;
	TurnBasedPlayer* player;
};

