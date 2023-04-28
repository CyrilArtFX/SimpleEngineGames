#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "ITurnBasedActor.h"
#include <vector>

using std::vector;

class StoneshardManager : public Actor
{
public:
	StoneshardManager();
	StoneshardManager(const StoneshardManager&) = delete;
	StoneshardManager& operator=(const StoneshardManager&) = delete;

	void updateActor(float dt) override;

	void AddTurnBasedActor(ITurnBasedActor* actor);
	void RemoveTurnBasedActor(ITurnBasedActor* actor);

	void ForceGlobalTurnAction();

private:
	vector<ITurnBasedActor*> turnBasedActors;
};

