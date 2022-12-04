#include "MouseMovComponent.h"
#include "../Actor.h"
#include <SimpleEngine/Game.h>

void MouseMovComponent::update(float dt)
{
	actorPosBeforeMovement = owner.getPosition();
	int mousePosX, mousePosY;
	SDL_GetMouseState(&mousePosX, &mousePosY);
	Vector2 newPosition = owner.getPosition();

	if (enableXAxis)
	{
		newPosition.x = mousePosX;
	}

	if (enableYAxis)
	{
		newPosition.y = mousePosY;
	}

	owner.setPosition(newPosition);
}

void MouseMovComponent::setEnableXMovement(bool enable)
{
	enableXAxis = enable;
	if (!enableXAxis)
	{
		velocity.x = 0.0f;
	}
}

void MouseMovComponent::setEnableYMovement(bool enable)
{
	enableYAxis = enable;
	if (!enableYAxis)
	{
		velocity.y = 0.0f;
	}
}
