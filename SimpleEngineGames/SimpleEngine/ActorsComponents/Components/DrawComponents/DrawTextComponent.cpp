#include "DrawTextComponent.h"
#include <SimpleEngine/Game.h>

DrawTextComponent::DrawTextComponent(Actor* ownerP, Font* fontP, string textP, Color colorP, Vector2 offsetP, bool centeredP, int drawOrderP) :
	DrawComponent(ownerP, drawOrderP), font(fontP), text(textP), color(colorP), offset(offsetP), centered(centeredP)
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

	if (centered)
	{
		centeredOffsetX = width / 2.0f;
	}

	SDL_FreeSurface(sdl_surface);
}

void DrawTextComponent::draw(Renderer& renderer)
{
	if (willDraw)
	{
		renderer.drawText(owner, this, width, height, getRealOffset());
	}
}

void DrawTextComponent::setCentered(bool centeredP)
{
	centered = centeredP;
	if (centered)
	{
		centeredOffsetX = width / 2.0f;
	}
	else
	{
		centeredOffsetX = 0.0f;
	}
}

Vector2 DrawTextComponent::getRealOffset()
{
	if (centered)
	{
		return Vector2{ offset.x - centeredOffsetX, offset.y };
	}
	else
	{
		return offset;
	}
}
