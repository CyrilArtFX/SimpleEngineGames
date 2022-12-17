#include "CPUPaddle.h"

CPUPaddle::CPUPaddle(Vector2 startPosP) : Paddle(), startPos(startPosP)
{
	moveComp = new VelocityMoveComponent(this);
	moveComp->setSpeed(150.0f);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, rectColComp);
	screenBorderInterComp->setInteractions(ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock);
	screenBorderInterComp->autoUpdate = true;

	setPosition(startPosP);
}

void CPUPaddle::UpdateVelocity(float ballPosY)
{
	Rectangle scaled_rect = rectColComp->getTransformedRectangle();
	float center_y = scaled_rect.y + (scaled_rect.height / 2.0f);

	moveComp->setVelocity(Vector2::zero);

	if (center_y > ballPosY)
	{
		if (center_y - ballPosY > 35.0f)
		{
			moveComp->setVelocity(Vector2{ 0.0f, -1.0f });
		}
	}
	else if (center_y < ballPosY)
	{
		if (ballPosY - center_y > 35.0f)
		{
			moveComp->setVelocity(Vector2{ 0.0f, 1.0f });
		}
	}
}

void CPUPaddle::ResetPos()
{
	setPosition(startPos);
}
