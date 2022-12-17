#include "DrawTextComponent.h"
#include <SimpleEngine/Game.h>

DrawTextComponent::DrawTextComponent(Actor* ownerP, Font* fontP, string textP, Color colorP, Vector2 offsetP, int drawOrderP) :
	DrawComponent(ownerP, drawOrderP), font(fontP), text(textP), color(colorP), offset(offsetP)
{
	recalculateSDLTexture();
}

DrawTextComponent::~DrawTextComponent()
{
	if (SDLTexture)
	{
		SDL_DestroyTexture(SDLTexture);
	}
}

void DrawTextComponent::setFont(Font* fontP)
{
	font = fontP;
	recalculateSDLTexture();
}

void DrawTextComponent::setText(const string textP)
{
	text = textP;
	recalculateSDLTexture();
}

void DrawTextComponent::recalculateSDLTexture()
{
	if (font == nullptr) return;

	if (SDLTexture)
	{
		SDL_DestroyTexture(SDLTexture);
	}

	auto sdl_surface = TTF_RenderText_Solid(font->getSdlFont(), text.c_str(), color.toSDLColor());
	SDLTexture = SDL_CreateTextureFromSurface(owner.getGame().getRenderer().toSDLRenderer(), sdl_surface);

	width = sdl_surface->w;
	height = sdl_surface->h;

	SDL_FreeSurface(sdl_surface);
}

void DrawTextComponent::draw(Renderer& renderer)
{
	if (willDraw)
	{
		renderer.drawText(owner, this, width, height, offset);
	}
}