#pragma once
#include "GridTileDraw.h"
#include <SimpleEngine/Utils/Color.h>

class GridTileDrawRectangle : public GridTileDraw
{
public:
	GridTileDrawRectangle(Color colorP);
	GridTileDrawRectangle() = delete;
	virtual ~GridTileDrawRectangle();

	void draw(Renderer& renderer, Rectangle tile) override;

private:
	Color color;
};

