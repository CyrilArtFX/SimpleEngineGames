#pragma once
#include "Paddle.h"
#include <SimpleEngine/ActorsComponents/Components/MoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

class CPUPaddle : public Paddle
{
public:
	CPUPaddle();
	CPUPaddle(const CPUPaddle&) = delete;
	CPUPaddle& operator=(const CPUPaddle&) = delete;

	void updateVelocity(float ballPosY);

private:
	MoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

