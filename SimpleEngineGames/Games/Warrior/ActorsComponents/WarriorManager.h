#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "WarriorPlayer.h"
#include "WarriorGrids.h"
#include <Components/DrawComponents/DrawTextComponent.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>

class WarriorManager : public Actor
{
public:
	WarriorManager(WarriorGrids* gridsP, WarriorPlayer* playerP);
	WarriorManager() = delete;
	WarriorManager(const WarriorManager&) = delete;
	WarriorManager operator=(const WarriorManager&) = delete;

	void updateActor(float dt) override;

private:
	void ResetGame();
	void SetKeyCountText();

	WarriorGrids* grids;
	WarriorPlayer* player;

	DrawTextComponent* keyCountTextComp;
	DrawTextComponent* resetTextComp;

	DrawSpriteComponent* trophyDrawComp;
	RectangleCollisionComponent* trophyColComp;

	int keysInHand{ 0 };
};

