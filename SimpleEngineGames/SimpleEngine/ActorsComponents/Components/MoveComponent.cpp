#include "MoveComponent.h"
#include <SimpleEngine/Utils/Maths.h>
#include "../Actor.h"

void MoveComponent::setVelocity(Vector2 velocityP) 
{
	velocity = velocityP;
}

void MoveComponent::setSpeed(float speedP)
{
	speed = speedP;
}

void MoveComponent::update(float dt)
{
	actorPosBeforeMovement = owner.getPosition();
	if (!Maths::nearZero(speed))
	{
		if (!Maths::nearZero(velocity.lengthSq()))
		{
			velocity.normalize();
		}
		Vector2 newPosition = owner.getPosition() + velocity * speed * dt;
		owner.setPosition(newPosition);
	}
}

void MoveComponent::revertLastMovement(bool revertOnlyX, bool revertOnlyY)
{
	if (revertOnlyX)
	{
		owner.setPosition(Vector2{ actorPosBeforeMovement.x, owner.getPosition().y });
	}
	else if (revertOnlyY)
	{
		owner.setPosition(Vector2{ owner.getPosition().x, actorPosBeforeMovement.y });
	}
	else
	{
		owner.setPosition(actorPosBeforeMovement);
	}
}
