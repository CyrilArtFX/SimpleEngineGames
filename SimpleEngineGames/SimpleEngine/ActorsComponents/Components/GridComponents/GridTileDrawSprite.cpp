#include "GridTileDrawSprite.h"

GridTileDrawSprite::GridTileDrawSprite(Texture& textureP) : GridTileDraw(), texture(textureP)
{
}

GridTileDrawSprite::~GridTileDrawSprite()
{
}

void GridTileDrawSprite::draw(Renderer& renderer, Rectangle tile, int traductionIndex)
{
	renderer.drawTileSprite(tile, texture, Rectangle::nullRect, Vector2::zero, Renderer::Flip::None);
}
