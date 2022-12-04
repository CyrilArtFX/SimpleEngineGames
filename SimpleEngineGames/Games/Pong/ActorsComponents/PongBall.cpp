#include "PongBall.h"
#include <SimpleEngine/Utils/Log.h>
#include <SimpleEngine/Game.h>

PongBall::PongBall() : Actor()
{
	drawCircleComp = new DrawCircleComponent(this, Vector2{ 0.0f, 0.0f }, 10.0f, Color::white);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(10.0f);

	moveComp = new MoveComponent(this);
	moveComp->setVelocity(Vector2{ 1.0f, -1.0f });

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, circleColComp);
	screenBorderInterComp->SetInteractions(ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce);

	resetPos();
	resumeMovement();
}

void PongBall::updateActor(float dt)
{
	screenBorderInterComp->CheckBordersInteractions();

	if (leftPaddle) Log::info("Left Paddle is assigned.");
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
