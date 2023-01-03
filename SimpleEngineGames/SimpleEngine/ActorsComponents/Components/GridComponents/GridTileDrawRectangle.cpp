#include "GridTileDrawRectangle.h"

GridTileDrawRectangle::GridTileDrawRectangle(Color colorP) : GridTileDraw(), color(colorP)
{
}

GridTileDrawRectangle::~GridTileDrawRectangle()
{
}

void GridTileDrawRectangle::draw(Renderer& renderer, Rectangle tile)
{
	renderer.drawTileRect(tile, color);
}
