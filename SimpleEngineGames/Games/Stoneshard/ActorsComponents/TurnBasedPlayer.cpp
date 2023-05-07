#include "TurnBasedPlayer.h"
#include <SimpleEngine/Game.h>

TurnBasedPlayer::TurnBasedPlayer(Texture& playerTextureP) : Actor()
{
	drawSpriteComp = new DrawSpriteComponent(this, playerTextureP, Vector2{ -16.0f, -48.0f }, Renderer::Flip::None);

	rectColComp = new RectangleCollisionComponent(this);
	rectColComp->setRectangle(Rectangle{ -16.0f, -16.0f, 32.0f, 32.0f });

	moveComp = new AToBMoveComponent(this);
	moveComp->setSpeed(200.0f);
}

void TurnBasedPlayer::TurnAction()
{
	if (!movementList.empty())
	{
		Vector2 destination = *(movementList.end() - 1);
		if (destination.x > getPosition().x)
		{
			drawSpriteComp->setFlip(Renderer::Flip::None);
		}
		else if (destination.x < getPosition().x)
		{
			drawSpriteComp->setFlip(Renderer::Flip::Horizontal);
		}
		moveComp->setDestination(destination);
		movementList.pop_back();
	}
}

bool TurnBasedPlayer::IsUnderMouse(Vector2 mousePos) const
{
	Vector2 reel_mouse_pos = mousePos + getGame().getCamera().getCamPos();

	return rectColComp->intersectWithPoint(reel_mouse_pos);
}

bool TurnBasedPlayer::MovingBetweenTiles() const
{
	return !moveComp->isOnDestination();
}

void TurnBasedPlayer::SetMovementList(std::vector<Vector2> movementListP)
{
	movementList.clear();
	movementList = movementListP;
}

void TurnBasedPlayer::ForceClearMovement()
{
	movementList.clear();
}

bool TurnBasedPlayer::HasMovementWaiting() const
{
	return !movementList.empty() || MovingBetweenTiles();
}
