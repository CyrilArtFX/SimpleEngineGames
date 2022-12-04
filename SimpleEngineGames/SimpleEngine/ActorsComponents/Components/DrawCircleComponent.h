#pragma once
#include "DrawComponent.h"
#include <SimpleEngine/Utils/Vector2.h>
#include <SimpleEngine/Utils/Color.h>

class DrawCircleComponent : public DrawComponent
{
public:
	DrawCircleComponent(Actor* ownerP, Vector2 offsetP, float radiusP, Color colorP, int drawOrderP = 100);
	virtual ~DrawCircleComponent();
	DrawCircleComponent() = delete;
	DrawCircleComponent(const DrawCircleComponent&) = delete;
	DrawCircleComponent& operator=(const DrawCircleComponent&) = delete;

	virtual void setOffset(const Vector2 offsetP);
	virtual void setRadius(const float radiusP);
	virtual void setColor(const Color colorP);
	virtual void draw(Renderer& renderer) override;

	Vector2 getOffset() const { return offset; }
	float getRadius() const { return radius; }
	Color getColor() const { return color; }

protected:
	Vector2 offset;
	float radius;
	Color color;
};

