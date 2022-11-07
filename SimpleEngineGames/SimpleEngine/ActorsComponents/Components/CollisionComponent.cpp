#include "CollisionComponent.h"

CollisionComponent::CollisionComponent(Actor* owner) : Component(owner)
{
}

bool intersectWithPoint(const Vector2& point)
{
	return false;
}

bool intersectWithCollison(const CollisionComponent& collision)
{
	return false;
}
