#pragma once
#include "ITurnBasedActor.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>
#include <Components/MoveComponents/AToBMoveComponent.h>

class TurnBasedEnemy : public ITurnBasedActor, public Actor
{
public:
	TurnBasedEnemy(const Actor& playerP, const class GridComponent& mapGridP, Vector2 spawnPositionP, float sqPlayerDetectionDistP = 50176.0f);
	TurnBasedEnemy() = delete;
	TurnBasedEnemy(const TurnBasedEnemy&) = delete;
	TurnBasedEnemy& operator=(const TurnBasedEnemy&) = delete;
	~TurnBasedEnemy();

	void TurnAction() override;
	bool IsUnderMouse(Vector2 mousePos);
	bool GetIsVisible() const { return isVisible; }
	bool GetPlayerDetected() const { return playerDetected; }

	void Kill(class StoneshardManager& manager);

private:
	bool CheckVisibility();

	DrawSpriteComponent* drawSpriteComp;
	DrawSpriteComponent* warningSpriteComp;
	RectangleCollisionComponent* rectColComp;
	AToBMoveComponent* moveComp;

	const Actor& player;
	const class GridComponent& mapGrid;
	bool playerDetected{ false };
	float sqPlayerDetectionDist;

	bool wasHighlightedLastFrame{ false };
	bool isVisible;
	bool warningActivated{ false };
};

