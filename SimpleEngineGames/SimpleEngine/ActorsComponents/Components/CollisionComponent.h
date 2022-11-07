#pragma once
#include "../Component.h"
#include "../../Utils/Vector2.h"

enum CollisionType
{
	Circle,
	Rectangle,
	Null
};

class CollisionComponent : public Component
{
public:
	CollisionComponent(Actor* owner);
	CollisionComponent() = delete;
	CollisionComponent(const CollisionComponent&) = delete;
	CollisionComponent& operator=(const CollisionComponent&) = delete;

	virtual bool intersectWithPoint(const Vector2& point);
	virtual bool intersectWithCollision(const CollisionComponent& collision);

private:
	CollisionType collisionType{ CollisionType::Null };
};

