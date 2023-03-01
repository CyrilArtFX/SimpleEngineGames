#include "DrawCircleComponent.h"

DrawCircleComponent::DrawCircleComponent(Actor* ownerP, Vector2 offsetP, float radiusP, Color colorP, int drawOrderP) :
	DrawComponent(ownerP, drawOrderP), offset(offsetP), radius(radiusP), color(colorP)
{
}

DrawCircleComponent::~DrawCircleComponent()
{
}

void DrawCircleComponent::setOffset(const Vector2 offsetP)
{
	offset = offsetP;
}

void DrawCircleComponent::setRadius(const float radiusP)
{
	radius = radiusP;
}

void DrawCircleComponent::setColor(const Color colorP)
{
	color = colorP;
}

void DrawCircleComponent::draw(Renderer& renderer)
{
	if (willDraw)
	{
		renderer.drawCircle(owner, offset, radius, color);
	}
}
