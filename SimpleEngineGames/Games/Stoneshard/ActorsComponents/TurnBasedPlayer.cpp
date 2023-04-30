#include "TurnBasedPlayer.h"
#include <SimpleEngine/Game.h>

TurnBasedPlayer::TurnBasedPlayer(Texture& playerTextureP) : Actor()
{
	halfTexSize = Vector2{ playerTextureP.getWidth() / 2.0f, playerTextureP.getHeight() / 2.0f };
	drawSpriteComp = new DrawSpriteComponent(this, playerTextureP, -halfTexSize, Renderer::Flip::None);

	rectColComp = new RectangleCollisionComponent(this);
	rectColComp->setRectangle(Rectangle{ -16.0f, -16.0f, 32.0f, 32.0f });
}

void TurnBasedPlayer::TurnAction()
{
	if (!movementList.empty())
	{
		setPosition(*(movementList.end() - 1));
		movementList.pop_back();
	}

	getGame().getCamera().setCamPos(getPosition() - Vector2{ static_cast<float>(getGame().getScreenWidth() / 2), static_cast<float>(getGame().getScreenHeight() / 2) });
}

bool TurnBasedPlayer::IsUnderMouse(Vector2 mousePos) const
{
	Vector2 reel_mouse_pos = mousePos + getGame().getCamera().getCamPos();

	return rectColComp->intersectWithPoint(reel_mouse_pos);
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
	return !movementList.empty();
}
