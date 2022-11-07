#include "font.h"
#include "Log.h"

Font::Font(string pathP, TTF_Font* sdlFontP, int sizeP) : path(pathP), sdlFont(sdlFontP), size(sizeP)
{
}

Font* Font::load(const string& pathP, int sizeP)
{
	TTF_Font* sdlFont = TTF_OpenFont(pathP.c_str(), sizeP);
	if (sdlFont == nullptr)
	{
		Log::error(LogCategory::Application, "Failed to load font file " + pathP);
		return nullptr;
	}

	return new Font(pathP, sdlFont, sizeP);
}