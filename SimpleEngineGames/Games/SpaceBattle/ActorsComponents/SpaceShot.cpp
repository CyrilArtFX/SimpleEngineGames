#include "SpaceShot.h"
#include <SimpleEngine/Maths/Maths.h>

SpaceShot::SpaceShot(Texture& shotTextureP, float speedP, float lifetimeP, float ScaleFactorP) : SpaceActor(), speed(speedP), lifetime(lifetimeP)
{
	setScale(ScaleFactorP);

	drawSpriteComp = new DrawSpriteComponent(this, shotTextureP, Vector2{ -8.0f * ScaleFactorP, -8.0f * ScaleFactorP }, Renderer::Flip::None);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(6.0f);

	moveComp = new VelocityMoveComponent(this);
	moveComp->setSpeed(speedP);

	Reset();
}

void SpaceShot::Fire(Vector2 firingPosition, float firingRotation, Vector2 firingVelocity, float deltaTime)
{
	if (activated) return;

	activated = true;
	drawSpriteComp->setWillDraw(true);

	Vector2 vel = Vector2{ Maths::cos(firingRotation) * speed * deltaTime + firingVelocity.x, -Maths::sin(firingRotation) * speed * deltaTime + firingVelocity.y };
	vel.normalize();

	setPosition(firingPosition);
	set2DRotation(Maths::atan2(vel.x, vel.y) + Maths::pi / 2.0f);
	moveComp->setVelocity(vel);
	moveComp->setSpeed(speed + firingVelocity.length() / deltaTime);
}

void SpaceShot::Reset()
{
	activated = false;
	drawSpriteComp->setWillDraw(false);
	moveComp->setVelocity(Vector2::zero);
	cooldown = 0.0f;
}

void SpaceShot::RunTimer(float deltaTime)
{
	if (!activated) return;
	
	cooldown += deltaTime;
	if (cooldown > lifetime)
	{
		Reset();
	}
}

bool SpaceShot::CheckForUFO(CircleCollisionComponent& ufoCollision)
{
	if (!activated) return false;

	return ufoCollision.intersectWithCircleCollision(*circleColComp);
}