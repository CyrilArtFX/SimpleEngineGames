#include "PlayerPaddle.h"

PlayerPaddle::PlayerPaddle() : Paddle()
{
	mouseMoveComp = new MouseMovComponent(this);
	mouseMoveComp->setEnableXMovement(false);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, mouseMoveComp, rectColComp);
	screenBorderInterComp->SetInteractions(ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block);
	screenBorderInterComp->autoUpdate = true;
}
