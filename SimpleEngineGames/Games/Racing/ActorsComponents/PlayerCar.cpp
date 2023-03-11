#include "PlayerCar.h"
#include <SimpleEngine/Maths/Maths.h>
#include <Components/GridComponents/GridComponent.h>

PlayerCar::PlayerCar(Texture& carTextureP) : Actor()
{
	drawSpriteComp = new DrawSpriteComponent(this, carTextureP, Vector2{ -10.0f, -5.0f }, Renderer::Flip::Horizontal);

	circleColComp = new CircleCollisionComponent(this);
	circleColComp->setRadius(10.0f);

	moveComp = new RotationInputMoveComponent(this, Maths::pi * 0.5f);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, circleColComp);
	screenBorderInterComp->setInteractions(ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block);
	screenBorderInterComp->autoUpdate = true;
}

void PlayerCar::TestGridCol(GridComponent& grid)
{
	if (grid.intersectWithCircleCol(*circleColComp))
	{
		moveComp->revertLastMovement(true, true);
		moveComp->setSpeed(0.0f);
	}
}