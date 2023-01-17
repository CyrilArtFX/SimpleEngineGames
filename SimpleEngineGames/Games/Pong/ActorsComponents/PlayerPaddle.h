#pragma once
#include "Paddle.h"
#include <SimpleEngine/ActorsComponents/Components/MouseMoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

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

