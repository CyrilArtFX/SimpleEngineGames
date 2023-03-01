#pragma once
#include "Paddle.h"
#include <Components/MoveComponents/MouseMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>

class PlayerPaddle : public Paddle
{
public:
	PlayerPaddle();
	PlayerPaddle(const PlayerPaddle&) = delete;
	PlayerPaddle& operator=(const PlayerPaddle&) = delete;

private:
	MouseMoveComponent* mouseMoveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

