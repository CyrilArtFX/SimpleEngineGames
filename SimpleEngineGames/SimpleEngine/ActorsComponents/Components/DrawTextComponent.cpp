#include "DrawTextComponent.h"
#include "../../Game.h"

DrawTextComponent::DrawTextComponent(Actor* ownerP, Font* fontP, string textP, Color colorP, int drawOrderP) :
	DrawComponent(ownerP, drawOrderP), font(fontP), text(textP), color(colorP)
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

	auto sdlSurface = TTF_RenderText_Solid(font->getSdlFont(), text.c_str(), color.toSDLColor());
	SDLTexture = SDL_CreateTextureFromSurface(owner.getGame().getRenderer().toSDLRenderer(), sdlSurface);

	width = sdlSurface->w;
	height = sdlSurface->h;

	SDL_FreeSurface(sdlSurface);
}

void DrawTextComponent::draw(Renderer& renderer)
{
	renderer.drawText(owner, this, width, height);
}