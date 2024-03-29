#pragma once
#include "DrawComponent.h"
#include <SimpleEngine/Maths/Rectangle.h>
#include <SimpleEngine/Utils/Color.h>

//  note : rectangle drawing doesn't support actor rotation

class DrawRectComponent : public DrawComponent
{
public:
	DrawRectComponent(Actor* ownerP, Rectangle rectP, Color colorP, int drawOrderP = 100);
	virtual ~DrawRectComponent();
	DrawRectComponent() = delete;
	DrawRectComponent(const DrawRectComponent&) = delete;
	DrawRectComponent& operator=(const DrawRectComponent&) = delete;

	virtual void setRect(const Rectangle rectP);
	virtual void setColor(const Color colorP);
	virtual void draw(Renderer& renderer) override;

	Rectangle getRect() const { return rect; }
	Color getColor() const { return color; }

protected:
	Rectangle rect;
	Color color;
};

