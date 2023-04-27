#include "TurnBasedPlayer.h"

TurnBasedPlayer::TurnBasedPlayer(Texture& playerTextureP) : Actor()
{
	drawSpriteComp = new DrawSpriteComponent(this, playerTextureP, Vector2{ -16.0f, -16.0f }, Renderer::Flip::None);
}

void TurnBasedPlayer::TurnAction()
{
}
