#pragma once
#include "ITurnBasedActor.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>
#include <Components/MoveComponents/AToBMoveComponent.h>
#include <vector>

class TurnBasedPlayer : public ITurnBasedActor, public Actor
{
public:
	TurnBasedPlayer(Texture& playerTextureP);
	TurnBasedPlayer() = delete;
	TurnBasedPlayer(const TurnBasedPlayer&) = delete;
	TurnBasedPlayer& operator=(const TurnBasedPlayer&) = delete;

	void TurnAction() override;
	bool IsUnderMouse(Vector2 mousePos) const;
	bool MovingBetweenTiles() const;

	void SetMovementList(std::vector<Vector2> movementListP);
	void ForceClearMovement();
	bool HasMovementWaiting() const;

private:
	DrawSpriteComponent* drawSpriteComp;
	RectangleCollisionComponent* rectColComp;
	AToBMoveComponent* moveComp;
	Vector2 halfTexSize;
	std::vector<Vector2> movementList;
};

