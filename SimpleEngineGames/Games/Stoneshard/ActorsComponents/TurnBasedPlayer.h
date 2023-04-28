#pragma once
#include "ITurnBasedActor.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>

class TurnBasedPlayer : public ITurnBasedActor, public Actor
{
public:
	TurnBasedPlayer(Texture& playerTextureP);
	TurnBasedPlayer() = delete;
	TurnBasedPlayer(const TurnBasedPlayer&) = delete;
	TurnBasedPlayer& operator=(const TurnBasedPlayer&) = delete;

	void TurnAction() override;
	bool IsUnderMouse(Vector2 mousePos) const;

private:
	DrawSpriteComponent* drawSpriteComp;
	RectangleCollisionComponent* rectColComp;
	Vector2 halfTexSize;
};

