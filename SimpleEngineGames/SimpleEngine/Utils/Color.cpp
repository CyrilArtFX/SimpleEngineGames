#include "Color.h"

const Color Color::black{ 0, 0, 0, 255 };
const Color Color::white{ 255, 255, 255, 255 };
const Color Color::red{ 255, 0, 0, 255 };
const Color Color::green{ 0, 255, 0, 255 };
const Color Color::blue{ 0, 0, 255, 255 };

void Color::set(int rP, int gP, int bP, int aP)
{
	r = rP;
	g = gP;
	b = bP;
	a = aP;
}
