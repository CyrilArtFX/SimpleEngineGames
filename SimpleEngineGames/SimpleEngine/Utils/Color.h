#pragma once

struct Color
{
	int r{ 0 };
	int g{ 0 };
	int b{ 0 };
	int a{ 0 };

	static const Color black;
	static const Color white;
	static const Color red;
	static const Color green;
	static const Color blue;

	Color() = default;
	Color(int rP, int gP, int bP, int aP) : r{ rP }, g{ gP }, b{ bP }, a{ aP } {}

	void set(int rP, int gP, int bP, int aP);
};

