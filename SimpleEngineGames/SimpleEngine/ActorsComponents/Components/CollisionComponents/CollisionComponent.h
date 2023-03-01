#pragma once
#include <SimpleEngine/ActorsComponents/Component.h>
#include <SimpleEngine/Maths/Vector2.h>
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

	virtual bool intersectWithY(const float y) const;
	virtual bool intersectWithX(const float x) const;

	virtual float nearestYPosOfY(const float y) const;
	virtual float nearestXPosOfX(const float x) const;

	virtual void drawDebug(Renderer& renderer, Color debugColor);
};

