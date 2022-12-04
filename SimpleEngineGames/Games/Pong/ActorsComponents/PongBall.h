#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include "Paddle.h"
#include <SimpleEngine/ActorsComponents/Components/DrawCircleComponent.h>
#include <SimpleEngine/ActorsComponents/Components/CircleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/MoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

class PongBall : public Actor
{
public:
	PongBall();
	PongBall(const PongBall&) = delete;
	PongBall& operator=(const PongBall&) = delete;

	void updateActor(float dt) override;

	void setPaddles(Paddle* leftPaddleP, Paddle* rightPaddleP);
	void resetPos();
	void pauseMovement();
	void resumeMovement();

	void setSpeed(float speedP);
	float getSpeed() const { return speed; }

private:
	Paddle* leftPaddle{ nullptr };
	Paddle* rightPaddle{ nullptr };

	DrawCircleComponent* drawCircleComp;
	CircleCollisionComponent* circleColComp;
	MoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;

	float speed{ 300.0f };
};

