#include "MouseMoveComponent.h"
#include "../Actor.h"
#include <SimpleEngine/Game.h>

void MouseMoveComponent::update(float dt)
{
	actorPosBeforeMovement = owner.getPosition();
	Vector2 new_position = owner.getPosition();

	if (enableXAxis)
	{
		new_position.x = mouseX;
	}

	if (enableYAxis)
	{
		new_position.y = mouseY;
	}

	owner.setPosition(new_position);
}

void MouseMoveComponent::processInput(const Uint8* keyState, const Uint32 mouseState, int mousePosX, int mousePosY)
{
	mouseX = mousePosX;
	mouseY = mousePosY;
}
