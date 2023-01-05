#pragma once
#include "GridTileDraw.h"
#include <SimpleEngine/Utils/Color.h>

class GridTileDrawRectangle : public GridTileDraw
{
public:
	GridTileDrawRectangle(Color colorP, Rectangle proportionP);
	GridTileDrawRectangle() = delete;
	virtual ~GridTileDrawRectangle();

	void draw(Renderer& renderer, Rectangle tile, int traductionIndex) override;

private:
	Color color;
	Rectangle proportion{ Rectangle::unitRect };
	bool proportionCorrect{ false };
};

