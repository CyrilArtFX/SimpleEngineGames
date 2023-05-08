#include "StoneshardCamera.h"
#include <SimpleEngine/Game.h>

StoneshardCamera::StoneshardCamera(TurnBasedPlayer* playerP) : Actor(), player(playerP)
{
	registeredClamps["BaseMap"] = CameraClamp{ Vector2{-32.0f, -32.0f}, Vector2{672.0f, 392.0f} };

	currentClamp = registeredClamps["BaseMap"];

	halfScreenSize = Vector2{ static_cast<float>(getGame().getScreenWidth() / 2), static_cast<float>(getGame().getScreenHeight() / 2) };
}

void StoneshardCamera::updateActor(float dt)
{
	Vector2 cam_pos = player->getPosition() - halfScreenSize;
	cam_pos.clamp(currentClamp.clampMin, currentClamp.clampMax);
	getGame().getCamera().setCamPos(cam_pos);
}
