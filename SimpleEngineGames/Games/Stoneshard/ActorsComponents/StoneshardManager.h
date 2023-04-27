#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "ITurnBasedActor.h"
#include <vector>

using std::vector;

class StoneshardManager : public Actor
{
public:
	StoneshardManager();
	StoneshardManager(StoneshardManager&) = delete;
	StoneshardManager& operator=(StoneshardManager&) = delete;

	void updateActor(float dt) override;

	void AddTurnBasedActor(ITurnBasedActor* actor);
	void RemoveTurnBasedActor(ITurnBasedActor* actor);

private:
	vector<ITurnBasedActor*> turnBasedActors;
};

