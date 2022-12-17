#pragma once
#include "Paddle.h"
#include <SimpleEngine/ActorsComponents/Components/VelocityMoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

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

