#include "SpaceShip.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Utils/Random.h>
#include <SimpleEngine/Maths/Maths.h>

SpaceShip::SpaceShip(Texture& shipTextureP, float ScaleFactorP) : SpaceActor()
{
	setScale(ScaleFactorP);

	drawSpriteComp = new DrawSpriteComponent(this, shipTextureP, Vector2{ -8.0f * ScaleFactorP, -8.0f * ScaleFactorP }, Renderer::Flip::None);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(8.0f);

	moveComp = new SpaceShipMoveComponent(this);


	Reset();
}

void SpaceShip::Reset()
{
	//  small trick used to avoid player and ufo spawning at the same coordinates at the beginning
	setPosition(Vector2{ 
		Maths::fmod((Random::getFloatRange(0, getGame().getScreenWidth()) * 2.0f), getGame().getScreenWidth()),
		Maths::fmod((Random::getFloatRange(0, getGame().getScreenHeight()) * 2.0f), getGame().getScreenHeight())
		});
	moveComp->setVelocity(Vector2::zero);
	set2DRotation(Random::getFloatRange(0, Maths::twoPi));
}

Vector2 SpaceShip::GetVelocity()
{
	return moveComp->getVelocity();
}

bool SpaceShip::CheckForUFO(CircleCollisionComponent& ufoCollision)
{
	return ufoCollision.intersectWithCircleCollision(*circleColComp);
}
