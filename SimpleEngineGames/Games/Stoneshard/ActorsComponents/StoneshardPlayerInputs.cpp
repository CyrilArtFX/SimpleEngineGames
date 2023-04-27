#include "StoneshardPlayerInputs.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Assets/Assets.h>

StoneshardPlayerInputs::StoneshardPlayerInputs(StoneshardManager* managerP) : Actor(), manager(managerP)
{
	player = new TurnBasedPlayer(Assets::getTexture("player"));

	managerP->AddTurnBasedActor(player);
}

void StoneshardPlayerInputs::updateActor(float dt)
{
}
