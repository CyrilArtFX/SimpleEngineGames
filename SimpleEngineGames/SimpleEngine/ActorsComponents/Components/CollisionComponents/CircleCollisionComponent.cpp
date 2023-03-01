#include "CircleCollisionComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
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
	float center_y = getCenter().y;
	float circle_radius = getRadius();
	return y >= center_y - circle_radius && y <= center_y + circle_radius;
}

bool CircleCollisionComponent::intersectWithX(const float x) const
{
	float center_x = getCenter().x;
	float circle_radius = getRadius();
	return x >= center_x - circle_radius && x <= center_x + circle_radius;
}

float CircleCollisionComponent::nearestYPosOfY(const float y) const
{
	float y_pos = getCenter().y;
	if (y_pos > y)
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
	float x_pos = getCenter().x;
	if (x_pos > x)
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
	Vector2 screen_mouse_pos = owner.getGame().getMousePosition();

	Vector2 mouse_pos = Vector2{
		screen_mouse_pos.x + owner.getGame().getCamera().getCamPos().x,
		screen_mouse_pos.y + owner.getGame().getCamera().getCamPos().y
	};

	if (intersectWithPoint(mouse_pos))
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