#pragma once
#include "ITurnBasedActor.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>

class TurnBasedPlayer : public ITurnBasedActor, public Actor
{
public:
	TurnBasedPlayer(Texture& playerTextureP);
	TurnBasedPlayer() = delete;
	TurnBasedPlayer(const TurnBasedPlayer&) = delete;
	TurnBasedPlayer& operator=(const TurnBasedPlayer&) = delete;

	void TurnAction() override;

private:
	DrawSpriteComponent* drawSpriteComp;
};

