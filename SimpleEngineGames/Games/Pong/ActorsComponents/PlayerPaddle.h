#pragma once
#include "Paddle.h"
#include <SimpleEngine/ActorsComponents/Components/MouseMovComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

class PlayerPaddle : public Paddle
{
public:
	PlayerPaddle();
	PlayerPaddle(const PlayerPaddle&) = delete;
	PlayerPaddle& operator=(const PlayerPaddle&) = delete;

private:
	MouseMovComponent* mouseMoveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

