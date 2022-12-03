#pragma once
#include "DrawComponent.h"
#include <SimpleEngine/Texture.h>

class DrawSpriteComponent : public DrawComponent
{
public:
	DrawSpriteComponent(Actor* ownerP, Texture& textureP, int drawOrderP = 100);
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
};

