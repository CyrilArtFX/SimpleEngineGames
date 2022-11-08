#include "MoveComponent.h"
#include "../../Utils/Maths.h"
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