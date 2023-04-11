#include "SpaceShipMoveComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/Game.h>

SpaceShipMoveComponent::SpaceShipMoveComponent(Actor* ownerP, int updateOrderP) : InputMoveComponent(ownerP, updateOrderP)
{
}

void SpaceShipMoveComponent::update(float dt)
{
	if (owner.getGame().isKeyDown(forwardKey))
	{
		Vector2 forward_direction = GetPlayerDirection();
		velocity += forward_direction * (forwardAccelerationInputValue * dt);
		velocity.clampMagnitude(maxSpeed);
	}

	if (owner.getGame().isKeyDown(leftKey))
	{
		ChangePlayerRotation(angleInputValue * dt);
	}
	if (owner.getGame().isKeyDown(rightKey))
	{
		ChangePlayerRotation(-angleInputValue * dt);
	}



	actorPosBeforeMovement = owner.getPosition();
	Vector2 new_position = owner.getPosition() + velocity;
	owner.setPosition(new_position);

	velocity *= (1 - (persistantSpeedLoss * dt));
}

void SpaceShipMoveComponent::SetInputValues(float forwardAccelerationInputValueP, float angleInputValueP)
{
	forwardAccelerationInputValue = forwardAccelerationInputValueP;
	angleInputValue = angleInputValueP;
}

void SpaceShipMoveComponent::SetMotionValues(float persistantSpeedLossP, float maxSpeedP)
{
	persistantSpeedLoss = persistantSpeedLossP;
	maxSpeed = maxSpeedP;
}

Vector2 SpaceShipMoveComponent::GetPlayerDirection()
{
	float angle = owner.get2DRotation();
	return Vector2{ Maths::cos(-angle), Maths::sin(-angle) };
}

void SpaceShipMoveComponent::ChangePlayerRotation(float rotationAdd)
{
	float angle = owner.get2DRotation();
	angle += rotationAdd;
	owner.set2DRotation(angle);
}
