#include "DrawSpriteComponent.h"
#include "../../Utils/Rectangle.h"

DrawSpriteComponent::DrawSpriteComponent(Actor* ownerP, Texture& textureP, int drawOrderP) :
	DrawComponent(ownerP, drawOrderP), texture(textureP), texWidth(textureP.getWidth()), texHeight(textureP.getHeight())
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
	Vector2 origin{ texWidth / 2.0f, texHeight / 2.0f };
	renderer.drawSprite(owner, texture, Rectangle::nullRect, origin, Renderer::Flip::None);
}
