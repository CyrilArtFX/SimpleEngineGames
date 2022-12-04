#include "RectangleCollisionComponent.h"
#include "../Actor.h"
#include "CircleCollisionComponent.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Utils/Log.h>
#include <SimpleEngine/Utils/Maths.h>

Rectangle RectangleCollisionComponent::getTransformedRectangle() const
{
	return Rectangle{
		owner.getPosition().x + rectangle.x,
		owner.getPosition().y + rectangle.y,
		owner.getScale() * rectangle.width,
		owner.getScale() * rectangle.height
	};
}

void RectangleCollisionComponent::setRectangle(Rectangle rectangleP)
{
	rectangle = rectangleP;
}

bool RectangleCollisionComponent::intersectWithPoint(const Vector2& point) const
{
	Rectangle scaledRect = getTransformedRectangle();
	return point.x >= scaledRect.x && point.x <= scaledRect.x + scaledRect.width
		&& point.y >= scaledRect.y && point.y <= scaledRect.y + scaledRect.height;
}

bool RectangleCollisionComponent::intersectWithCircleCollision(const CircleCollisionComponent& collision) const
{
	Rectangle scaledRect = getTransformedRectangle();
	float halfWidth = scaledRect.width / 2;
	float halfHeight = scaledRect.height / 2;
	float circleRadius = collision.getRadius();
	Vector2 circleCenter = collision.getCenter();

	Vector2 rectCenter = Vector2{ scaledRect.x + halfWidth, scaledRect.y + halfHeight };
	Vector2 circleDistance = Vector2{ fabs(circleCenter.x - rectCenter.x), fabs(circleCenter.y - rectCenter.y) };

	if (circleDistance.x > (halfWidth + circleRadius)) return false;
	if (circleDistance.y > (halfHeight + circleRadius)) return false;

	if (circleDistance.x <= (halfWidth)) return true;
	if (circleDistance.y <= (halfHeight)) return true;

	float cornerDistanceSq = (circleDistance.x - halfWidth) * (circleDistance.x - halfWidth) 
		+ (circleDistance.y - halfHeight) * (circleDistance.y - halfHeight);
	return (cornerDistanceSq <= (circleRadius * circleRadius));
}

bool RectangleCollisionComponent::intersectWithRectCollision(const RectangleCollisionComponent& collision) const
{
	Rectangle scaledRect1 = getTransformedRectangle();
	Rectangle scaledRect2 = collision.getTransformedRectangle();

	return intersectWithPoint(Vector2{ scaledRect2.x, scaledRect2.y })
		|| intersectWithPoint(Vector2{ scaledRect2.x + scaledRect2.width, scaledRect2.y })
		|| intersectWithPoint(Vector2{ scaledRect2.x, scaledRect2.y + scaledRect2.height })
		|| intersectWithPoint(Vector2{ scaledRect2.x + scaledRect2.width, scaledRect2.y + scaledRect2.height })
		|| collision.intersectWithPoint(Vector2{ scaledRect1.x, scaledRect1.y });
}

bool RectangleCollisionComponent::intersectWithY(const float y) const
{
	Rectangle scaledRect = getTransformedRectangle();
	return y >= scaledRect.y && y <= scaledRect.y + scaledRect.height;
}

bool RectangleCollisionComponent::intersectWithX(const float x) const
{
	Rectangle scaledRect = getTransformedRectangle();
	return x >= scaledRect.x && x <= scaledRect.x + scaledRect.width;
}

float RectangleCollisionComponent::nearestYPosOfY(const float y) const
{
	Rectangle scaledRect = getTransformedRectangle();
	float yCenter = scaledRect.y + scaledRect.height / 2.0f;
	if (yCenter > y)
	{
		return y - rectangle.y;
	}
	else
	{
		return y - rectangle.y - scaledRect.height;
	}
}

float RectangleCollisionComponent::nearestXPosOfX(const float x) const
{
	Rectangle scaledRect = getTransformedRectangle();
	float xCenter = scaledRect.x + scaledRect.width / 2.0f;
	if (xCenter > x)
	{
		return x - rectangle.x;
	}
	else
	{
		return x - rectangle.x - scaledRect.width;
	}
}

void RectangleCollisionComponent::debug(Renderer& renderer)
{
	int mousePosX, mousePosY;
	SDL_GetMouseState(&mousePosX, &mousePosY);
	Vector2 mousePos = Vector2{
		mousePosX + owner.getGame().getCamera().getCamPos().x,
		mousePosY + owner.getGame().getCamera().getCamPos().y
	};

	if (intersectWithPoint(mousePos))
	{
		drawDebug(renderer, Color::white);
	}
	else
	{
		drawDebug(renderer, Color::grey);
	}
}

void RectangleCollisionComponent::drawDebug(Renderer& renderer, Color debugColor)
{
	renderer.drawDebugRect(owner, rectangle, debugColor);
}
