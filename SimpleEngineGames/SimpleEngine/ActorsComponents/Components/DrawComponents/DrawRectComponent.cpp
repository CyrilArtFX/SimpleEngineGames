#include "DrawRectComponent.h"

DrawRectComponent::DrawRectComponent(Actor* ownerP, Rectangle rectP, Color colorP, int drawOrderP) :
	DrawComponent(ownerP, drawOrderP), rect(rectP), color(colorP)
{
}

DrawRectComponent::~DrawRectComponent()
{
}

void DrawRectComponent::setRect(const Rectangle rectP)
{
	rect = rectP;
}

void DrawRectComponent::setColor(const Color colorP)
{
	color = colorP;
}

void DrawRectComponent::draw(Renderer& renderer) 
{
	if (willDraw)
	{
		renderer.drawRect(owner, rect, color);
	}
}