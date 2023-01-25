#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawCircleComponent.h>
#include <SimpleEngine/ActorsComponents/Components/CircleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/VelocityMoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

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

