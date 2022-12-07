#include "PongBall.h"
#include <SimpleEngine/Utils/Log.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Components/RectangleCollisionComponent.h>
#include "PongManager.h"

PongBall::PongBall() : Actor()
{
	drawCircleComp = new DrawCircleComponent(this, Vector2{ 0.0f, 0.0f }, 10.0f, Color::white);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(10.0f);

	moveComp = new MoveComponent(this);
	moveComp->setVelocity(Vector2{ 1.0f, -1.0f });

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, circleColComp);
	screenBorderInterComp->SetInteractions(ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Return, ScreenBorderInteractions::Return);

	resetPos();
	resumeMovement();
}

void PongBall::updateActor(float dt)
{
	int screenReturn = screenBorderInterComp->CheckBordersInteractions();
	if (screenReturn == 3)
	{
		gameManager->ScoreAtLeft();
	}
	else if (screenReturn == 4)
	{
		gameManager->ScoreAtRight();
	}

	if (leftPaddle) 
	{
		if (leftPaddle->GetCol()->intersectWithCircleCollision(*circleColComp) && moveComp->getVelocity().x < 0.0f)
		{
			moveComp->revertLastMovement(true, false);
			reverseXMovement();
			setDirectedYMovement(leftPaddle->GetCol()->getTransformedRectangle());
			speed += speedBoost;
			moveComp->setSpeed(speed);
		}
	}

	if (rightPaddle)
	{
		if (rightPaddle->GetCol()->intersectWithCircleCollision(*circleColComp) && moveComp->getVelocity().x > 0.0f)
		{
			moveComp->revertLastMovement(true, false);
			reverseXMovement();
			setDirectedYMovement(rightPaddle->GetCol()->getTransformedRectangle());
			speed += speedBoost;
			moveComp->setSpeed(speed);
		}
	}
}

void PongBall::setPaddles(Paddle* leftPaddleP, Paddle* rightPaddleP)
{
	leftPaddle = leftPaddleP;
	rightPaddle = rightPaddleP;
}

void PongBall::setManager(PongManager* gameManagerP)
{
	gameManager = gameManagerP;
}

void PongBall::resetPos()
{
	speed = baseSpeed;
	moveComp->setSpeed(speed);
	setPosition(Vector2{ getGame().getScreenWidth() / 2.0f, getGame().getScreenHeight() / 2.0f });
	reverseXMovement();
}

void PongBall::reverseXMovement()
{
	Vector2 velocity = moveComp->getVelocity();
	moveComp->setVelocity(Vector2{ -velocity.x, velocity.y });
}

void PongBall::setDirectedYMovement(Rectangle colRect)
{
	float newVelocityY = (getPosition().y - colRect.y - (colRect.height / 2)) / colRect.height * directMultiplier;
	Vector2 velocity = moveComp->getVelocity();
	moveComp->setVelocity(Vector2{ velocity.x, newVelocityY });
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
