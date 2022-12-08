#include "CPUPaddle.h"

CPUPaddle::CPUPaddle() : Paddle()
{
	moveComp = new MoveComponent(this);
	moveComp->setSpeed(50.0f);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, rectColComp);
	screenBorderInterComp->SetInteractions(ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock);
	screenBorderInterComp->autoUpdate = true;
}

void CPUPaddle::updateVelocity(float ballPosY)
{
	Rectangle scaledRect = rectColComp->getTransformedRectangle();
	float centerY = scaledRect.y + (scaledRect.height / 2.0f);

	if (centerY > ballPosY)
	{

	}
	else if (centerY < ballPosY)
	{

	}
}
