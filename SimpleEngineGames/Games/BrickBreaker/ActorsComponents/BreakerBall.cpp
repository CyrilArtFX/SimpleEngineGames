#include "BreakerBall.h"
#include <Components/CollisionComponents/RectangleCollisionComponent.h>

BreakerBall::BreakerBall() : Actor()
{
	drawCircleComp = new DrawCircleComponent(this, Vector2{ 0.0f, 0.0f }, 10.0f, Color::white);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(10.0f);

	moveComp = new VelocityMoveComponent(this);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, circleColComp);
	screenBorderInterComp->setInteractions(ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Return, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce);

	ResetPos();
}

bool BreakerBall::UpdateBall()
{
	previousPos = moveComp->getBeforeLastMovementPosition();

	int screen_return = screenBorderInterComp->checkBordersInteractions();
	return screen_return == 2;
}

bool BreakerBall::TestPaddleCollision(RectangleCollisionComponent* col)
{
	bool intersect_with_paddle = col->intersectWithCircleCollision(*circleColComp) && moveComp->getVelocity().y > 0.0f;
	if (intersect_with_paddle)
	{
		moveComp->revertLastMovement(false, true);
		ReverseYMovement();
		SetDirectedXMovement(col->getTransformedRectangle());
	}
	return intersect_with_paddle;
}

void BreakerBall::SetManager(BreakerManager* gameManagerP)
{
	gameManager = gameManagerP;
}

void BreakerBall::ResetPos()
{
	moveComp->setSpeed(speed);
	setPosition(Vector2{ 400.0f, 480.0f });
	moveComp->setVelocity(Vector2{ 0.0f, -1.0f });
}

void BreakerBall::ReverseXMovement()
{
	moveComp->reverseXMovement();
}

void BreakerBall::ReverseYMovement()
{
	moveComp->reverseYMovement();
}

void BreakerBall::SetDirectedXMovement(Rectangle colRect)
{
	float new_velocity_x = (getPosition().x - colRect.x - (colRect.width / 2)) / colRect.width * directMultiplier;
	Vector2 velocity = moveComp->getVelocity();
	moveComp->setVelocity(Vector2{ new_velocity_x, velocity.y });
}

void BreakerBall::PauseMovement()
{
	moveComp->setSpeed(0.0f);
}

void BreakerBall::ResumeMovement()
{
	moveComp->setSpeed(speed);
}

void BreakerBall::SetDrawValue(bool value)
{
	drawCircleComp->setWillDraw(value);
}

void BreakerBall::SetSpeed(float speedP)
{
	speed = speedP;
}
