#pragma once
#include <SimpleEngine/Renderer.h>
#include <SimpleEngine/Utils/Rectangle.h>

class GridTileDraw
{
public:
	GridTileDraw();
	virtual ~GridTileDraw();

	virtual void draw(Renderer& renderer, Rectangle tile);
};

