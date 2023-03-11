#pragma once
#include "CollisionComponent.h"
#include <SimpleEngine/Maths/Rectangle.h>
#include <SimpleEngine/Maths/Vector2.h>

//  note : rectangle collision doesn't support actor rotation                                                                                                                                          (aled)

class RectangleCollisionComponent : public CollisionComponent
{
public:
	RectangleCollisionComponent(Actor* ownerP, bool debugEnabledP = true) : CollisionComponent(ownerP, debugEnabledP) {}
	RectangleCollisionComponent() = delete;
	RectangleCollisionComponent(const RectangleCollisionComponent&) = delete;
	RectangleCollisionComponent& operator=(const RectangleCollisionComponent&) = delete;

	
	Rectangle getRectangle() const { return rectangle; }
	Rectangle getTransformedRectangle() const;
	void setRectangle(Rectangle rectangleP);

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
	Rectangle rectangle{ Rectangle::nullRect };
};