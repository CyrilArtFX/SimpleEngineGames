#include "AToBMoveComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>

void AToBMoveComponent::setSpeed(float speedP)
{
	speed = speedP;
}

void AToBMoveComponent::setDestination(Vector2 destinationP)
{
	needToMove = true;
	destination = destinationP;
}

void AToBMoveComponent::update(float dt)
{
	if (needToMove)
	{
		actorPosBeforeMovement = owner.getPosition();

		Vector2 actor_to_destination = destination - owner.getPosition();
		Vector2 direction = actor_to_destination;
		direction.normalize();
		direction *= speed * dt;

		if (direction.lengthSq() >= actor_to_destination.lengthSq())
		{
			owner.setPosition(destination);
			needToMove = false;
			return;
		}

		owner.setPosition(owner.getPosition() - direction);
	}
}