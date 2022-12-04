#include "CircleCollisionComponent.h"
#include "../Actor.h"
#include "RectangleCollisionComponent.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Utils/Log.h>

float CircleCollisionComponent::getRadius() const
{
	return owner.getScale() * radius;
}

void CircleCollisionComponent::setRadius(float radiusP)
{
	radius = radiusP;
}

void CircleCollisionComponent::setOffset(Vector2 offsetP)
{
	offset = offsetP;
}

const Vector2 CircleCollisionComponent::getCenter() const
{
	return owner.getPosition() + offset;
}

bool CircleCollisionComponent::intersectWithPoint(const Vector2& point) const
{
	return (getCenter() - point).lengthSq() <= getRadius() * getRadius();
}

bool CircleCollisionComponent::intersectWithCircleCollision(const CircleCollisionComponent& collision) const
{
	return (getCenter() - collision.getCenter()).lengthSq() 
		<= getRadius() * getRadius() + collision.getRadius() * collision.getRadius();
}

bool CircleCollisionComponent::intersectWithRectCollision(const RectangleCollisionComponent& collision) const
{
	return collision.intersectWithCircleCollision(*this);
}

bool CircleCollisionComponent::intersectWithY(const float y) const
{
	float centerY = getCenter().y;
	float circleHeight = getRadius();
	return y >= centerY - circleHeight && y <= centerY + circleHeight;
}

bool CircleCollisionComponent::intersectWithX(const float x) const
{
	float centerX = getCenter().x;
	float circleWidth = getRadius();
	return x >= centerX - circleWidth && x <= centerX + circleWidth;
}

float CircleCollisionComponent::nearestYPosOfY(const float y) const
{
	float yPos = getCenter().y;
	if (yPos > y)
	{
		return y + getRadius();
	}
	else
	{
		return y - getRadius();
	}
}

float CircleCollisionComponent::nearestXPosOfX(const float x) const
{
	float xPos = getCenter().x;
	if (xPos > x)
	{
		return x + getRadius();
	}
	else
	{
		return x - getRadius();
	}
}

void CircleCollisionComponent::debug(Renderer& renderer)
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

void CircleCollisionComponent::drawDebug(Renderer& renderer, Color debugColor)
{
	renderer.drawDebugCircle(owner, offset, radius, debugColor);
}