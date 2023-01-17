#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawRectComponent.h>
#include <SimpleEngine/ActorsComponents/Components/RectangleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/MouseMoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

class BreakerPaddle : public Actor
{
public:
	BreakerPaddle();
	BreakerPaddle(const BreakerPaddle&) = delete;
	BreakerPaddle& operator=(const BreakerPaddle&) = delete;

	RectangleCollisionComponent* GetCol() { return rectColComp; }
	void SetDrawValue(bool value);

private:
	DrawRectComponent* drawRectComp;
	RectangleCollisionComponent* rectColComp;
	MouseMoveComponent* mouseMoveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

