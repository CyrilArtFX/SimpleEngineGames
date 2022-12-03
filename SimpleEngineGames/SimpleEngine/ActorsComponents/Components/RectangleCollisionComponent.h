#pragma once
#include "CollisionComponent.h"
#include <SimpleEngine/Utils/Rectangle.h>
#include <SimpleEngine/Utils/Vector2.h>

//  note : rectangle collision doesn't support actor rotation                                                                                                                                          (aled)

class RectangleCollisionComponent : public CollisionComponent
{
public:
	RectangleCollisionComponent(Actor* ownerP) : CollisionComponent(ownerP) {}
	RectangleCollisionComponent() = delete;
	RectangleCollisionComponent(const RectangleCollisionComponent&) = delete;
	RectangleCollisionComponent& operator=(const RectangleCollisionComponent&) = delete;

	
	Rectangle getRectangle() const { return rectangle; }
	Rectangle getTransformedRectangle() const;
	void setRectangle(Rectangle rectangleP);

	bool intersectWithPoint(const Vector2& point) const override;
	bool intersectWithCircleCollision(const class CircleCollisionComponent& collision) const override;
	bool intersectWithRectCollision(const class RectangleCollisionComponent& collision) const override;

	void debug(Renderer& renderer) override;
	void drawDebug(Renderer& renderer, Color debugColor) override;

private:
	Rectangle rectangle{ Rectangle::nullRect };
};