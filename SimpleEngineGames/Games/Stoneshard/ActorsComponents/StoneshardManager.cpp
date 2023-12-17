#include "StoneshardManager.h"
#include <algorithm>

StoneshardManager::StoneshardManager() : Actor()
{
}

void StoneshardManager::updateActor(float dt)
{
	if (turnTimeCounter > 0.0f)
	{
		turnTimeCounter -= dt;
	}
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

void StoneshardManager::AddEnemy(TurnBasedEnemy* enemy)
{
	enemiesList.emplace_back(enemy);
}

void StoneshardManager::RemoveEnemy(TurnBasedEnemy* enemy)
{
	auto iter = std::find(begin(enemiesList), end(enemiesList), enemy);
	if (iter != end(enemiesList))
	{
		std::iter_swap(iter, end(enemiesList) - 1);
		enemiesList.pop_back();
	}
}

void StoneshardManager::PlayGlobalTurnAction()
{
	if (turnTimeCounter <= 0.0f)
	{
		ForceGlobalTurnAction();
		turnTimeCounter += turnMinTime;
	}
}

void StoneshardManager::ForceGlobalTurnAction()
{
	for (auto turn_based_actor : turnBasedActors)
	{
		turn_based_actor->TurnAction();
	}
}