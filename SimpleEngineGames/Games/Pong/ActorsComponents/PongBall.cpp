#include "PongBall.h"
#include <SimpleEngine/Utils/Log.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Components/RectangleCollisionComponent.h>
#include <iostream>

PongBall::PongBall() : Actor()
{
	drawCircleComp = new DrawCircleComponent(this, Vector2{ 0.0f, 0.0f }, 10.0f, Color::white);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(10.0f);

	moveComp = new MoveComponent(this);
	moveComp->setVelocity(Vector2{ 1.0f, -1.0f });

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, circleColComp);
	screenBorderInterComp->SetInteractions(ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Return, ScreenBorderInteractions::Bounce);

	resetPos();
	resumeMovement();
}

void PongBall::updateActor(float dt)
{
	int screenReturn = screenBorderInterComp->CheckBordersInteractions();
	if (screenReturn == 3)
	{
		resetPos();
	}

	if (leftPaddle) 
	{
		if (leftPaddle->GetCol()->intersectWithCircleCollision(*circleColComp))
		{
			moveComp->revertLastMovement(true, false);
			reverseXMovement();
		}
	}

	if (rightPaddle) Log::info("Right Paddle is assigned.");
}

void PongBall::setPaddles(Paddle* leftPaddleP, Paddle* rightPaddleP)
{
	leftPaddle = leftPaddleP;
	rightPaddle = rightPaddleP;
}

void PongBall::resetPos()
{
	setPosition(Vector2{ getGame().getScreenWidth() / 2.0f, getGame().getScreenHeight() / 2.0f });
	reverseXMovement();
}

void PongBall::reverseXMovement()
{
	Vector2 velocity = moveComp->getVelocity();
	moveComp->setVelocity(Vector2{ -velocity.x, velocity.y });
}

void PongBall::pauseMovement()
{
	moveComp->setSpeed(0.0f);
}

void PongBall::resumeMovement()
{
	moveComp->setSpeed(speed);
}

void PongBall::setSpeed(float speedP)
{
	speed = speedP;
}
