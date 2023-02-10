#pragma once
#include "DrawComponent.h"
#include <SimpleEngine/Texture.h>
#include <SimpleEngine/Renderer.h>

class DrawSpriteComponent : public DrawComponent
{
public:
	DrawSpriteComponent(Actor* ownerP, Texture& textureP, Vector2 offsetP, Renderer::Flip spriteFlipP, int drawOrderP = 100);
	virtual ~DrawSpriteComponent();
	DrawSpriteComponent() = delete;
	DrawSpriteComponent(const DrawSpriteComponent&) = delete;
	DrawSpriteComponent& operator=(const DrawSpriteComponent&) = delete;

	virtual void setTexture(const Texture& textureP);
	virtual void draw(Renderer& renderer) override;

	int getTexWidth() const { return texWidth; }
	int getTexHeight() const { return texHeight; }

protected:
	Texture texture;
	int texWidth;
	int texHeight;
	Vector2 offset{ Vector2::zero };
	Renderer::Flip spriteFlip{ Renderer::Flip::None };
};

