#include "WarriorPlayer.h"
#include <Components/GridComponents/GridComponent.h>

WarriorPlayer::WarriorPlayer(Texture& textureP) : Actor()
{
	drawSpriteComp = new DrawSpriteComponent(this, textureP, Vector2{ -16.0f, -16.0f }, Renderer::Flip::None);

	rectColComp = new RectangleCollisionComponent(this);
	rectColComp->setRectangle(Rectangle{ -16.0f, -16.0f, 32.0f, 32.0f });

	moveComp = new InputMoveComponent(this);
	moveComp->setSpeed(150.0f);

	screenBorderInterComp = new ScreenBorderInteractionComponent(this, moveComp, rectColComp);
	screenBorderInterComp->setInteractions(ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block);
	screenBorderInterComp->autoUpdate = true;
}

void WarriorPlayer::TestWallGridCol(GridComponent& wallGrid)
{
	Vector2 pos = getPosition();

	setPosition(moveComp->getCustomRevertedPosition(false, true));
	bool revert_movement_x = wallGrid.intersectWithRectangleCol(*rectColComp);
	setPosition(pos);

	setPosition(moveComp->getCustomRevertedPosition(true, false));
	bool revert_movement_y = wallGrid.intersectWithRectangleCol(*rectColComp);
	setPosition(pos);

	moveComp->revertLastMovement(revert_movement_x, revert_movement_y);
}

bool WarriorPlayer::TestGridInteraction(GridComponent& interactableGrid, int* gridPosReturnX, int* gridPosReturnY)
{
	return interactableGrid.intersectWithRectangleCol(*rectColComp, gridPosReturnX, gridPosReturnY);
}

bool WarriorPlayer::TestTrophyTrigger(RectangleCollisionComponent& trophy)
{
	return trophy.intersectWithRectCollision(*rectColComp);
}
