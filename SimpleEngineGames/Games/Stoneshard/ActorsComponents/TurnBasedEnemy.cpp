#include "TurnBasedEnemy.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Algorithms/AStar.h>

TurnBasedEnemy::TurnBasedEnemy(const Actor& playerP, const class GridComponent& mapGridP, float sqPlayerDetectionDistP) : 
	Actor(), player(playerP), mapGrid(mapGridP), sqPlayerDetectionDist(sqPlayerDetectionDistP)
{
	drawSpriteComp = new DrawSpriteComponent(this, Assets::getTexture("enemy"), Vector2{ -16.0f, -48.0f }, Renderer::Flip::None);

	rectColComp = new RectangleCollisionComponent(this);
	rectColComp->setRectangle(Rectangle{ -16.0f, -16.0f, 32.0f, 32.0f });

	moveComp = new AToBMoveComponent(this);
	moveComp->setSpeed(200.0f);
}

void TurnBasedEnemy::TurnAction()
{
	if (!playerDetected)
	{
		if ((player.getPosition() - getPosition()).lengthSq() < sqPlayerDetectionDist)
		{
			playerDetected = true;
		}
	}
	else
	{

	}

	drawSpriteComp->setFlip((playerDetected != player.getPosition().x > getPosition().x) ? Renderer::Flip::None : Renderer::Flip::Horizontal);
}

bool TurnBasedEnemy::IsUnderMouse(Vector2 mousePos) const
{
	return false;
}
