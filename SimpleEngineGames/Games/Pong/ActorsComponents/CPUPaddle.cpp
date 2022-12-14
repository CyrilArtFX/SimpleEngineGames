#include "CPUPaddle.h"

CPUPaddle::CPUPaddle(Vector2 startPosP) : Paddle(), startPos(startPosP)
{
	moveComp = new MoveComponent(this);
	moveComp->setSpeed(150.0f);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, rectColComp);
	screenBorderInterComp->SetInteractions(ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock);
	screenBorderInterComp->autoUpdate = true;

	setPosition(startPosP);
}

void CPUPaddle::updateVelocity(float ballPosY)
{
	Rectangle scaledRect = rectColComp->getTransformedRectangle();
	float centerY = scaledRect.y + (scaledRect.height / 2.0f);

	moveComp->setVelocity(Vector2::zero);

	if (centerY > ballPosY)
	{
		if (centerY - ballPosY > 35.0f)
		{
			moveComp->setVelocity(Vector2{ 0.0f, -1.0f });
		}
	}
	else if (centerY < ballPosY)
	{
		if (ballPosY - centerY > 35.0f)
		{
			moveComp->setVelocity(Vector2{ 0.0f, 1.0f });
		}
	}
}

void CPUPaddle::resetPos()
{
	setPosition(startPos);
}
