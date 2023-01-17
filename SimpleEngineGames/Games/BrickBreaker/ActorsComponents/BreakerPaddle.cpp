#include "BreakerPaddle.h"
#include <SimpleEngine/Utils/Rectangle.h>

BreakerPaddle::BreakerPaddle() : Actor()
{
	Rectangle rect = Rectangle{ -50.0f, 0.0f, 100.0f, 10.0f };

	drawRectComp = new DrawRectComponent(this, rect, Color::white);

	rectColComp = new RectangleCollisionComponent(this);
	rectColComp->setRectangle(rect);

	mouseMoveComp = new MouseMoveComponent(this);
	mouseMoveComp->setEnableYMovement(false);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, mouseMoveComp, rectColComp);
	screenBorderInterComp->setInteractions(ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock, ScreenBorderInteractions::SmoothBlock);
	screenBorderInterComp->autoUpdate = true;
}

void BreakerPaddle::SetDrawValue(bool value)
{
	drawRectComp->setWillDraw(value);
}
