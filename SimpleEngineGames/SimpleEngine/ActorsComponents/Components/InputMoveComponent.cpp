#include "InputMoveComponent.h"
#include "../../Utils/Maths.h"
#include "../Actor.h"
#include "RectangleCollisionComponent.h"
#include "../../Game.h"
#include <iostream>

InputMoveComponent::InputMoveComponent(Actor* ownerP, CircleCollisionComponent* collisionP) : MoveComponent(ownerP), collision(collisionP)
{
}

void InputMoveComponent::processInput(const Uint8* keyState)
{
	float forwardSpeed = 0.0f;
	if (keyState[forwardKey])
	{
		forwardSpeed += maxForwardSpeed;
	}
	if (keyState[backKey])
	{
		forwardSpeed -= maxForwardSpeed;
	}
	setForwardSpeed(forwardSpeed);

	float angularSpeed = 0.0f;
	if (keyState[clockwiseKey])
	{
		angularSpeed -= maxAngularSpeed;
	}
	if (keyState[counterClockwiseKey])
	{
		angularSpeed += maxAngularSpeed;
	}
	setAngularSpeed(angularSpeed);
}

void InputMoveComponent::update(float dt)
{
	if (!Maths::nearZero(angularSpeed))
	{
		float newRotation = owner.getRotation() + angularSpeed * dt;
		owner.setRotation(newRotation);
	}

	if (!Maths::nearZero(forwardSpeed))
	{
		Vector2 newPosition = owner.getPosition() + owner.getForward() * forwardSpeed * dt;
		owner.setPosition(newPosition);
	}
}


void InputMoveComponent::setMaxForwardSpeed(float maxForwardSpeedP)
{
	maxForwardSpeed = maxForwardSpeedP;
}

void InputMoveComponent::setMaxAngularSpeed(float maxAngularSpeedP)
{
	maxAngularSpeed = maxAngularSpeedP;
}

void InputMoveComponent::setForwardKey(int key)
{
	forwardKey = key;
}

void InputMoveComponent::setBackKey(int key)
{
	backKey = key;
}

void InputMoveComponent::setClockwiseKey(int key)
{
	clockwiseKey = key;
}

void InputMoveComponent::setCounterClockwiseKey(int key)
{
	counterClockwiseKey = key;
}