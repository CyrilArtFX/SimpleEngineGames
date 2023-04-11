#include "SpaceShip.h"
#include <SimpleEngine/Game.h>

SpaceShip::SpaceShip(Texture& shipTextureP) : Actor()
{
	drawSpriteComp = new DrawSpriteComponent(this, shipTextureP, Vector2{ -8.0f, -8.0f }, Renderer::Flip::None);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(8.0f);

	moveComp = new SpaceShipMoveComponent(this);


	setPosition(Vector2{ 400.0f, 300.0f });
}

void SpaceShip::updateActor(float dt)
{
	Vector2 pos = getPosition();

	if (pos.y < 0.0f)
	{
		pos.y = getGame().getScreenHeight();
	}
	else if (pos.y > getGame().getScreenHeight())
	{
		pos.y = 0.0f;
	}

	if (pos.x < 0.0f)
	{
		pos.x = getGame().getScreenWidth();
	}
	else if (pos.x > getGame().getScreenWidth())
	{
		pos.x = 0;
	}

	setPosition(pos);
}
