#include "SpaceUFO.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Utils/Random.h>
#include <SimpleEngine/Maths/Maths.h>

SpaceUFO::SpaceUFO(Texture& ufoTextureP, float speedP, float timePerDirectionP, float ScaleFactorP) : SpaceActor(), timePerDirection(timePerDirectionP)
{
	setScale(ScaleFactorP);

	drawSpriteComp = new DrawSpriteComponent(this, ufoTextureP, Vector2{ -8.0f * ScaleFactorP, -8.0f * ScaleFactorP }, Renderer::Flip::None);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(10.0f);

	moveComp = new VelocityMoveComponent(this);
	moveComp->setSpeed(speedP);

	Reset();
}

void SpaceUFO::Reset()
{
	setPosition(Vector2{ Random::getFloatRange(0, getGame().getScreenWidth()), Random::getFloatRange(0, getGame().getScreenHeight()) });
	ChangeDirection();
}

void SpaceUFO::RunTimer(float deltaTime)
{
	cooldown += deltaTime;
	if (cooldown > timePerDirection)
	{
		cooldown -= timePerDirection;
		ChangeDirection();
	}
}

void SpaceUFO::ChangeDirection()
{
	float angle = Random::getFloatRange(0, Maths::twoPi);
	moveComp->setVelocity(Vector2{ Maths::cos(angle), Maths::sin(angle) });
}
