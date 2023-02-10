#include "DrawSpriteComponent.h"
#include <SimpleEngine/Utils/Rectangle.h>

DrawSpriteComponent::DrawSpriteComponent(Actor* ownerP, Texture& textureP, Vector2 offsetP, Renderer::Flip spriteFlipP, int drawOrderP) :
	DrawComponent(ownerP, drawOrderP), texture(textureP), texWidth(textureP.getWidth()), texHeight(textureP.getHeight()), offset(offsetP), spriteFlip(spriteFlipP)
{
}

DrawSpriteComponent::~DrawSpriteComponent()
{
}

void DrawSpriteComponent::setTexture(const Texture& textureP)
{
	texture = textureP;
	texture.updateInfo(texWidth, texHeight);
}

void DrawSpriteComponent::draw(Renderer& renderer)
{
	if (willDraw)
	{
		Vector2 origin{ texWidth / 2.0f, texHeight / 2.0f };
		renderer.drawSprite(owner, texture, Rectangle::nullRect, Vector2::zero, spriteFlip, offset);
	}
}
