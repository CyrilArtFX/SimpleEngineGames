#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle() : Paddle()
{
	mouseMoveComp = new MouseMovComponent(this);
	mouseMoveComp->setEnableXMovement(false);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, mouseMoveComp, rectColComp);
	screenBorderInterComp->SetInteractions(ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock);
	screenBorderInterComp->autoUpdate = true;
}
