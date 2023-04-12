#include "SpaceShip.h"

SpaceShip::SpaceShip(Texture& shipTextureP) : SpaceActor()
{
	drawSpriteComp = new DrawSpriteComponent(this, shipTextureP, Vector2{ -8.0f, -8.0f }, Renderer::Flip::None);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(8.0f);

	moveComp = new SpaceShipMoveComponent(this);


	setPosition(Vector2{ 400.0f, 300.0f });
}

Vector2 SpaceShip::GetVelocity()
{
	return moveComp->getVelocity();
}
