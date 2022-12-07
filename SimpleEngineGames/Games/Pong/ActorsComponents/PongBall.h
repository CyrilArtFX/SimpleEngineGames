#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "Paddle.h"
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

	void setPaddles(Paddle* leftPaddleP, Paddle* rightPaddleP);
	void setManager(PongManager* gameManagerP);
	void resetPos();
	void reverseXMovement();
	void setDirectedYMovement(Rectangle colRect);
	void pauseMovement();
	void resumeMovement();

	void setSpeed(float speedP);
	float getSpeed() const { return speed; }

private:
	Paddle* leftPaddle{ nullptr };
	Paddle* rightPaddle{ nullptr };

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

