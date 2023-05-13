#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "ITurnBasedActor.h"
#include "TurnBasedEnemy.h"
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

	void AddEnemy(TurnBasedEnemy* enemy);
	void RemoveEnemy(TurnBasedEnemy* enemy);
	vector<TurnBasedEnemy*> GetEnemiesList() { return enemiesList; }

	void PlayGlobalTurnAction();
	void ForceGlobalTurnAction();

private:
	vector<ITurnBasedActor*> turnBasedActors;
	vector<TurnBasedEnemy*> enemiesList;

	float turnMinTime{ 0.05f };
	float turnTimeCounter{ 0.0f };
};

