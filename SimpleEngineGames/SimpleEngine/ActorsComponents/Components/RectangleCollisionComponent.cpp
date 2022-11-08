#include "RectangleCollisionComponent.h"
#include "../Actor.h"
#include "../../Game.h"
#include "../../Utils/Log.h"

Rectangle RectangleCollisionComponent::getTransformedRectangle() const
{
	return Rectangle{
		owner.getPosition().x + rectangle.x,
		owner.getPosition().y + rectangle.y,
		owner.getScale() * rectangle.width,
		owner.getScale() * rectangle.height
	};
}

void RectangleCollisionComponent::setRectangle(Rectangle rectangleP)
{
	rectangle = rectangleP;
}

bool RectangleCollisionComponent::intersectWithPoint(const Vector2& point) const
{
	Rectangle scaledRect = getTransformedRectangle();
	return point.x >= scaledRect.x && point.x <= scaledRect.x + scaledRect.width
		&& point.y >= scaledRect.y && point.y <= scaledRect.y + scaledRect.height;
}

bool RectangleCollisionComponent::intersectWithCircleCollision(const CircleCollisionComponent& collision) const
{
	return false;
}

bool RectangleCollisionComponent::intersectWithRectCollision(const RectangleCollisionComponent& collision) const
{
	Rectangle scaledRect1 = getTransformedRectangle();
	Rectangle scaledRect2 = collision.getTransformedRectangle();

	return intersectWithPoint(Vector2{ scaledRect2.x, scaledRect2.y })
		|| intersectWithPoint(Vector2{ scaledRect2.x + scaledRect2.width, scaledRect2.y })
		|| intersectWithPoint(Vector2{ scaledRect2.x, scaledRect2.y + scaledRect2.height })
		|| intersectWithPoint(Vector2{ scaledRect2.x + scaledRect2.width, scaledRect2.y + scaledRect2.height })
		|| collision.intersectWithPoint(Vector2{ scaledRect1.x, scaledRect1.y });
}

void RectangleCollisionComponent::debug(Renderer& renderer)
{
	int mousePosX, mousePosY;
	SDL_GetMouseState(&mousePosX, &mousePosY);
	Vector2 mousePos = Vector2{
		mousePosX + owner.getGame().getCamera().getCamPos().x,
		mousePosY + owner.getGame().getCamera().getCamPos().y
	};

	if (intersectWithPoint(mousePos))
	{
		drawDebug(renderer, Color::white);
	}
	else
	{
		drawDebug(renderer, Color::grey);
	}
}

void RectangleCollisionComponent::drawDebug(Renderer& renderer, Color debugColor)
{
	renderer.drawDebugRect(owner, rectangle, debugColor);
}
