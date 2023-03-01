#include "VelocityMoveComponent.h"
#include <SimpleEngine/Maths/Maths.h>
#include <SimpleEngine/ActorsComponents/Actor.h>

void VelocityMoveComponent::setVelocity(Vector2 velocityP)
{
	velocity = velocityP;
}

void VelocityMoveComponent::setSpeed(float speedP)
{
	speed = speedP;
}

void VelocityMoveComponent::update(float dt)
{
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

void VelocityMoveComponent::stopXMovement()
{
	velocity.x = 0.0f;
}

void VelocityMoveComponent::stopYMovement()
{
	velocity.y = 0.0f;
}

void VelocityMoveComponent::reverseXMovement()
{
	velocity.x = -velocity.x;
}

void VelocityMoveComponent::reverseYMovement()
{
	velocity.y = -velocity.y;
}
