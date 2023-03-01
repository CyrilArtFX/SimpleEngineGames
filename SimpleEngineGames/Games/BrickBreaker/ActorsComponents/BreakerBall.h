#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawCircleComponent.h>
#include <Components/CollisionComponents/CircleCollisionComponent.h>
#include <Components/MoveComponents/VelocityMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>

class BreakerManager;

class BreakerBall : public Actor
{
public:
	BreakerBall();
	BreakerBall(const BreakerBall&) = delete;
	BreakerBall& operator=(const BreakerBall&) = delete;

	bool TestPaddleCollision(class RectangleCollisionComponent* col);
	bool UpdateBall();

	void SetManager(BreakerManager* gameManagerP);
	void ResetPos();
	void ReverseXMovement();
	void ReverseYMovement();
	void SetDirectedXMovement(Rectangle colRect);
	void PauseMovement();
	void ResumeMovement();
	void SetDrawValue(bool value);

	void SetSpeed(float speedP);
	float GetSpeed() const { return speed; }
	Vector2 GetPreviousPos() const{ return previousPos; }

private:
	BreakerManager* gameManager{ nullptr };

	DrawCircleComponent* drawCircleComp;
	CircleCollisionComponent* circleColComp;
	VelocityMoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;

	float speed{ 300.0f };
	float directMultiplier{ 1.5f };
	Vector2 previousPos{ Vector2::zero };
};

