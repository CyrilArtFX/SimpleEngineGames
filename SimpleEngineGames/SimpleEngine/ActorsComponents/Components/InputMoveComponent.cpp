#include "InputMoveComponent.h"

void InputMoveComponent::processInput(const Uint8* keyState, const Uint32 mouseState)
{
	if (enableYAxis)
	{
		velocity.y = 0.0f;
		if (keyState[forwardKey])
		{
			velocity.y = -1.0f;
		}
		else if (keyState[backKey])
		{
			velocity.y = 1.0f;
		}
	}

	if (enableXAxis)
	{
		velocity.x = 0.0f;
		if (keyState[rightKey])
		{
			velocity.x = 1.0f;
		}
		else if (keyState[leftKey])
		{
			velocity.x = -1.0f;
		}
	}
}

void InputMoveComponent::setForwardKey(SDL_Scancode key)
{
	forwardKey = key;
}

void InputMoveComponent::setBackKey(SDL_Scancode key)
{
	backKey = key;
}

void InputMoveComponent::setRightKey(SDL_Scancode key)
{
	rightKey = key;
}

void InputMoveComponent::setLeftKey(SDL_Scancode key)
{
	leftKey = key;
}