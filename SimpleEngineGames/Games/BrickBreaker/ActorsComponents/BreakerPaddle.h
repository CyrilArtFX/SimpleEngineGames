#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawRectComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>
#include <Components/MoveComponents/MouseMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>

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

