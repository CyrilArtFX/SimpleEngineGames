#include "InputMoveComponent.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Maths/Maths.h>

void InputMoveComponent::update(float dt)
{
	if (enableYAxis)
	{
		velocity.y = 0.0f;
		if (owner.getGame().isKeyDown(forwardKey))
		{
			velocity.y = -1.0f;
		}
		else if (owner.getGame().isKeyDown(backKey))
		{
			velocity.y = 1.0f;
		}
	}

	if (enableXAxis)
	{
		velocity.x = 0.0f;
		if (owner.getGame().isKeyDown(rightKey))
		{
			velocity.x = 1.0f;
		}
		else if (owner.getGame().isKeyDown(leftKey))
		{
			velocity.x = -1.0f;
		}
	}


	//  why does c++ is not capable of doing 'base.update(dt);' I am crying :((((((((((
	actorPosBeforeMovement = owner.getPosition();
	if (!Maths::nearZero(speed))
	{
		if (!Maths::nearZero(velocity.lengthSq()))
		{
			velocity.normalize();
		}
		Vector2 new_position = owner.getPosition() + velocity * speed * dt;
		owner.setPosition(new_position);
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