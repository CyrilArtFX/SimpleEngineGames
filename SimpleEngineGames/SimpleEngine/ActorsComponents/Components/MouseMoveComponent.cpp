#include "MouseMoveComponent.h"
#include "../Actor.h"
#include <SimpleEngine/Game.h>

void MouseMoveComponent::update(float dt)
{
	actorPosBeforeMovement = owner.getPosition();
	Vector2 new_position = owner.getPosition();

	Vector2 mouse_position = owner.getGame().getMousePosition();

	if (enableXAxis)
	{
		new_position.x = mouse_position.x;
	}

	if (enableYAxis)
	{
		new_position.y = mouse_position.y;
	}

	owner.setPosition(new_position);
}
