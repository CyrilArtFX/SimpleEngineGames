#include "CollisionComponent.h"
#include <SimpleEngine/Game.h>

bool CollisionComponent::intersectWithPoint(const Vector2& point) const
{
	return false;
}

bool CollisionComponent::intersectWithCircleCollision(const CircleCollisionComponent& collision) const
{
	return false;
}

bool CollisionComponent::intersectWithRectCollision(const RectangleCollisionComponent& collision) const
{
	return false;
}

bool CollisionComponent::intersectWithY(const float y) const
{
	return false;
}

bool CollisionComponent::intersectWithX(const float x) const
{
	return false;
}

float CollisionComponent::nearestYPosOfY(const float y) const
{
	return y;
}

float CollisionComponent::nearestXPosOfX(const float x) const
{
	return x;
}

void CollisionComponent::drawDebug(Renderer& renderer, Color debugColor)
{
}
