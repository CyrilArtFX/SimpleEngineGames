#pragma once
#include "../Component.h"
#include <SimpleEngine/Utils/Vector2.h>
#include <SimpleEngine/Renderer.h>


class CollisionComponent : public Component
{
public:
	CollisionComponent(Actor* ownerP) : Component(ownerP) {}
	CollisionComponent() = delete;
	CollisionComponent(const CollisionComponent&) = delete;
	CollisionComponent& operator=(const CollisionComponent&) = delete;

	virtual bool intersectWithPoint(const Vector2& point) const;
	virtual bool intersectWithCircleCollision(const class CircleCollisionComponent& collision) const;
	virtual bool intersectWithRectCollision(const class RectangleCollisionComponent& collision) const;

	virtual bool intersectWithHeight(const float height) const;
	virtual bool intersectWithWidth(const float width) const;

	virtual void drawDebug(Renderer& renderer, Color debugColor);
};

