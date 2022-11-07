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
	renderer.drawRect(owner, rect, color);
	renderer.drawDebugCircle(owner, Vector2{ rect.x + (rect.width * owner.getScale() / 2.0f), rect.y + (rect.height * owner.getScale() / 2.0f)}, 50, Color::white);
	renderer.drawDebugRect(owner, rect, Color::white);
}