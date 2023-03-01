#include "Paddle.h"
#include <SimpleEngine/Maths/Rectangle.h>

Paddle::Paddle() : Actor()
{
	Rectangle rect = Rectangle{ 0.0f, -50.0f, 10.0f, 100.0f };

	drawRectComp = new DrawRectComponent(this, rect, Color::white);

	rectColComp = new RectangleCollisionComponent(this);
	rectColComp->setRectangle(rect);
}

void Paddle::SetDrawValue(bool value)
{
	drawRectComp->setWillDraw(value);
}
