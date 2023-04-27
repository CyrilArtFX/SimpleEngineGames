#include "StoneshardManager.h"

StoneshardManager::StoneshardManager() : Actor()
{
}

void StoneshardManager::updateActor(float dt)
{
}

void StoneshardManager::AddTurnBasedActor(ITurnBasedActor* actor)
{
	turnBasedActors.emplace_back(actor);
}

void StoneshardManager::RemoveTurnBasedActor(ITurnBasedActor* actor)
{
	auto iter = std::find(begin(turnBasedActors), end(turnBasedActors), actor);
	if (iter != end(turnBasedActors))
	{
		std::iter_swap(iter, end(turnBasedActors) - 1);
		turnBasedActors.pop_back();
	}
}
