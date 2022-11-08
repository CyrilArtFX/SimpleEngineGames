#include "CollisionComponent.h"
#include "../../Game.h"

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

void CollisionComponent::drawDebug(Renderer& renderer, Color debugColor)
{
}
