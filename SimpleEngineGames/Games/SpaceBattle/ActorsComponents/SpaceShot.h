#pragma once
#include "SpaceActor.h"
#include <Components/MoveComponents/VelocityMoveComponent.h>

class SpaceShot : public SpaceActor
{
public:
	SpaceShot(Texture& shotTextureP, float speedP, float lifetimeP);
	SpaceShot() = delete;
	SpaceShot(const SpaceShot&) = delete;
	SpaceShot& operator=(const SpaceShot&) = delete;

	void Fire(Vector2 firingPosition, float firingRotation, Vector2 firingVelocity, float deltaTime);
	void Reset();

	void RunTimer(float deltaTime);
	bool CheckForUFO(CircleCollisionComponent& ufoCollision);

private:
	VelocityMoveComponent* moveComp;

	float speed;
	float lifetime;
	float cooldown{ 0.0f };
	bool activated{ false };
};

