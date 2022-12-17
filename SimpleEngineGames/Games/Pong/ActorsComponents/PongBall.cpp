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

	moveComp = new VelocityMoveComponent(this);
	moveComp->setVelocity(Vector2{ 1.0f, 0.0f });
	SetRandomYVelocity();

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, circleColComp);
	screenBorderInterComp->setInteractions(ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Return, ScreenBorderInteractions::Return);

	ResetPos();
	ResumeMovement();
}

void PongBall::updateActor(float dt)
{
	int screen_return = screenBorderInterComp->checkBordersInteractions();
	if (screen_return == 3)
	{
		gameManager->ScoreAtLeft();
	}
	else if (screen_return == 4)
	{
		gameManager->ScoreAtRight();
	}
}

void PongBall::TestCollision(RectangleCollisionComponent* col, bool testAtRight)
{
	if (col->intersectWithCircleCollision(*circleColComp) && (testAtRight ? moveComp->getVelocity().x > 0.0f : moveComp->getVelocity().x < 0.0f))
	{
		moveComp->revertLastMovement(true, false);
		ReverseXMovement();
		SetDirectedYMovement(col->getTransformedRectangle());
		speed += speedBoost;
		moveComp->setSpeed(speed);
	}
}

void PongBall::SetManager(PongManager* gameManagerP)
{
	gameManager = gameManagerP;
}

void PongBall::ResetPos()
{
	speed = baseSpeed;
	moveComp->setSpeed(speed);
	setPosition(Vector2{ getGame().getScreenWidth() / 2.0f, getGame().getScreenHeight() / 2.0f });
	ReverseXMovement();
	SetRandomYVelocity();
}

void PongBall::ReverseXMovement()
{
	moveComp->reverseXMovement();
}

void PongBall::SetRandomYVelocity()
{
	Vector2 velocity = moveComp->getVelocity();
	float random = Random::getFloatRange(-1.0f, 1.0f);
	moveComp->setVelocity(Vector2{ velocity.x, random});
}

void PongBall::SetDirectedYMovement(Rectangle colRect)
{
	float new_velocity_y = (getPosition().y - colRect.y - (colRect.height / 2)) / colRect.height * directMultiplier;
	Vector2 velocity = moveComp->getVelocity();
	moveComp->setVelocity(Vector2{ velocity.x, new_velocity_y });
}

void PongBall::PauseMovement()
{
	moveComp->setSpeed(0.0f);
}

void PongBall::ResumeMovement()
{
	moveComp->setSpeed(speed);
}

void PongBall::SetDrawValue(bool value)
{
	drawCircleComp->setWillDraw(value);
}

void PongBall::SetSpeed(float speedP)
{
	speed = speedP;
}
