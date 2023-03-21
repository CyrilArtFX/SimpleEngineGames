#pragma once
#include <SimpleEngine/Maths/Vector2.h>
#include <SimpleEngine/Renderer.h>


class ICollision
{
public:
	virtual ~ICollision() {}

	virtual bool intersectWithPoint(const Vector2& point) const = 0;
	virtual bool intersectWithCircleCollision(const class CircleCollisionComponent& collision) const = 0;
	virtual bool intersectWithRectCollision(const class RectangleCollisionComponent& collision) const = 0;

	virtual bool intersectWithY(const float y) const = 0;
	virtual bool intersectWithX(const float x) const = 0;

	virtual float nearestYPosOfY(const float y) const = 0;
	virtual float nearestXPosOfX(const float x) const = 0;

	virtual void drawDebug(Renderer& renderer, Color debugColor) = 0;

protected:
	bool debugEnabled;
};

