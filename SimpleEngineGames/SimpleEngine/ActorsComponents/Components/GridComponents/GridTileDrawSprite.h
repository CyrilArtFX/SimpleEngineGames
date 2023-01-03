#pragma once
#include "GridTileDraw.h"
#include <SimpleEngine/Texture.h>

class GridTileDrawSprite : public GridTileDraw
{
public:
	GridTileDrawSprite(Texture& textureP);
	GridTileDrawSprite() = delete;
	virtual ~GridTileDrawSprite();

	void draw(Renderer& renderer, Rectangle tile) override;

private:
	Texture& texture;
};

