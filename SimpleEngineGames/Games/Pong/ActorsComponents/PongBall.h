#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawCircleComponent.h>
#include <SimpleEngine/ActorsComponents/Components/CircleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/VelocityMoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

class PongManager;

class PongBall : public Actor
{
public:
	PongBall();
	PongBall(const PongBall&) = delete;
	PongBall& operator=(const PongBall&) = delete;

	void updateActor(float dt) override;
	void TestCollision(class RectangleCollisionComponent* col, bool testAtRight);

	void SetManager(PongManager* gameManagerP);
	void ResetPos();
	void ReverseXMovement();
	void SetRandomYVelocity();
	void SetDirectedYMovement(Rectangle colRect);
	void PauseMovement();
	void ResumeMovement();
	void SetDrawValue(bool value);

	void SetSpeed(float speedP);
	float GetSpeed() const { return speed; }

private:
	PongManager* gameManager{ nullptr };

	DrawCircleComponent* drawCircleComp;
	CircleCollisionComponent* circleColComp;
	VelocityMoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;

	float baseSpeed{ 300.0f };
	float speed{ 0.0f };
	float directMultiplier{ 1.5f };
	float speedBoost{ 15.0f };
};

