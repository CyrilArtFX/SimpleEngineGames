#pragma once
#include "Paddle.h"
#include <Components/MoveComponents/VelocityMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>

class CPUPaddle : public Paddle
{
public:
	CPUPaddle(Vector2 startPosP);
	CPUPaddle(const CPUPaddle&) = delete;
	CPUPaddle& operator=(const CPUPaddle&) = delete;

	void UpdateVelocity(float ballPosY);
	void ResetPos();

private:
	VelocityMoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
	Vector2 startPos;
};

