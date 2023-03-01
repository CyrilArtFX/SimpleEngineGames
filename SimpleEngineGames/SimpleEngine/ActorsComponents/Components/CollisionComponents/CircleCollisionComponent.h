#pragma once
#include "CollisionComponent.h"
#include <SimpleEngine/Maths/Vector2.h>

class CircleCollisionComponent : public CollisionComponent
{
public:
	CircleCollisionComponent(Actor* ownerP) : CollisionComponent(ownerP) {}
	CircleCollisionComponent() = delete;
	CircleCollisionComponent(const CircleCollisionComponent&) = delete;
	CircleCollisionComponent& operator=(const CircleCollisionComponent&) = delete;

	float getRadius() const;
	void setRadius(float radiusP);
	Vector2 getOffset() const { return offset; }
	void setOffset(Vector2 offsetP);
	const Vector2 getCenter() const;

	bool intersectWithPoint(const Vector2& point) const override;
	bool intersectWithCircleCollision(const class CircleCollisionComponent& collision) const override;
	bool intersectWithRectCollision(const class RectangleCollisionComponent& collision) const override;

	bool intersectWithY(const float y) const override;
	bool intersectWithX(const float x) const override;

	float nearestYPosOfY(const float y) const override;
	float nearestXPosOfX(const float x) const override;

	void debug(Renderer& renderer) override;
	void drawDebug(Renderer& renderer, Color debugColor) override;


private:
	float radius{ 1.0f };
	Vector2 offset{ Vector2::zero };
};