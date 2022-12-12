#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawCircleComponent.h>
#include <SimpleEngine/ActorsComponents/Components/CircleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/MoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

class PongManager;

class PongBall : public Actor
{
public:
	PongBall();
	PongBall(const PongBall&) = delete;
	PongBall& operator=(const PongBall&) = delete;

	void updateActor(float dt) override;
	void testCollision(class RectangleCollisionComponent* col, bool testAtRight);

	void setManager(PongManager* gameManagerP);
	void resetPos();
	void reverseXMovement();
	void setDirectedYMovement(Rectangle colRect);
	void pauseMovement();
	void resumeMovement();
	void SetDrawValue(bool value);

	void setSpeed(float speedP);
	float getSpeed() const { return speed; }

private:
	PongManager* gameManager{ nullptr };

	DrawCircleComponent* drawCircleComp;
	CircleCollisionComponent* circleColComp;
	MoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;

	float baseSpeed{ 300.0f };
	float speed{ 0.0f };
	float directMultiplier{ 1.5f };
	float speedBoost{ 15.0f };
};

