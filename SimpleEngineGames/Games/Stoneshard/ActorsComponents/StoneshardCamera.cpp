#include "StoneshardCamera.h"
#include <SimpleEngine/Game.h>

StoneshardCamera::StoneshardCamera(TurnBasedPlayer* playerP) : Actor(), player(playerP)
{
	registeredClamps["BaseMap"] = CameraClamp{ Vector2{0.0f, 0.0f}, Vector2{640.0f, 360.0f} };

	currentClamp = registeredClamps["BaseMap"];

	halfScreenSize = Vector2{ static_cast<float>(getGame().getScreenWidth() / 2), static_cast<float>(getGame().getScreenHeight() / 2) };
}

void StoneshardCamera::updateActor(float dt)
{
	Vector2 cam_pos = player->getPosition() - halfScreenSize;
	cam_pos.clamp(currentClamp.clampMin, currentClamp.clampMax);
	getGame().getCamera().setCamPos(cam_pos);
}
