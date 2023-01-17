#include "MouseMoveComponent.h"
#include "../Actor.h"
#include <SimpleEngine/Game.h>

void MouseMoveComponent::update(float dt)
{
	actorPosBeforeMovement = owner.getPosition();
	int mouse_pos_x, mouse_pos_y;
	SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y);
	Vector2 new_position = owner.getPosition();

	if (enableXAxis)
	{
		new_position.x = mouse_pos_x;
	}

	if (enableYAxis)
	{
		new_position.y = mouse_pos_y;
	}

	owner.setPosition(new_position);
}
