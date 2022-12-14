#include "PongBall.h"
#include <SimpleEngine/Utils/Log.h>
#include <SimpleEngine/Utils/Random.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Components/RectangleCollisionComponent.h>
#include "PongManager.h"
#include <iostream>

PongBall::PongBall() : Actor()
{
	drawCircleComp = new DrawCircleComponent(this, Vector2{ 0.0f, 0.0f }, 10.0f, Color::white);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(10.0f);

	moveComp = new MoveComponent(this);
	moveComp->setVelocity(Vector2{ 1.0f, 0.0f });
	setRandomYVelocity();

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
}

void PongBall::testCollision(RectangleCollisionComponent* col, bool testAtRight)
{
	if (col->intersectWithCircleCollision(*circleColComp) && (testAtRight ? moveComp->getVelocity().x > 0.0f : moveComp->getVelocity().x < 0.0f))
	{
		moveComp->revertLastMovement(true, false);
		reverseXMovement();
		setDirectedYMovement(col->getTransformedRectangle());
		speed += speedBoost;
		moveComp->setSpeed(speed);
	}
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
	setRandomYVelocity();
}

void PongBall::reverseXMovement()
{
	Vector2 velocity = moveComp->getVelocity();
	moveComp->setVelocity(Vector2{ -velocity.x, velocity.y });
}

void PongBall::setRandomYVelocity()
{
	Vector2 velocity = moveComp->getVelocity();
	float random = Random::getFloatRange(-1.0f, 1.0f);
	moveComp->setVelocity(Vector2{ velocity.x, random});
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

void PongBall::SetDrawValue(bool value)
{
	drawCircleComp->setWillDraw(value);
}

void PongBall::setSpeed(float speedP)
{
	speed = speedP;
}
