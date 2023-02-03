#include "InputMoveComponent.h"
#include <SimpleEngine/Game.h>

void InputMoveComponent::update(float dt)
{
	if (enableYAxis)
	{
		velocity.y = 0.0f;
		if (owner.getGame().getKeyState(SDL_SCANCODE_Z) == Pressed || owner.getGame().getKeyState(SDL_SCANCODE_Z) == Down)
		{
			velocity.y = -1.0f;
		}
		else if (owner.getGame().getKeyState(SDL_SCANCODE_S) == Pressed || owner.getGame().getKeyState(SDL_SCANCODE_S) == Down)
		{
			velocity.y = 1.0f;
		}
	}

	if (enableXAxis)
	{
		velocity.x = 0.0f;
		if (owner.getGame().getKeyState(SDL_SCANCODE_D) == Pressed || owner.getGame().getKeyState(SDL_SCANCODE_D) == Down)
		{
			velocity.x = 1.0f;
		}
		else if (owner.getGame().getKeyState(SDL_SCANCODE_Q) == Pressed || owner.getGame().getKeyState(SDL_SCANCODE_Q) == Down)
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