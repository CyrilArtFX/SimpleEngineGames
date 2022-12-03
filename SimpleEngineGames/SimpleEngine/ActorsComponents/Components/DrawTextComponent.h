#pragma once
#include "DrawComponent.h"
#include <SimpleEngine/Utils/Font.h>
#include <SimpleEngine/Utils/Color.h>
#include <string>
using std::string;

class DrawTextComponent : public DrawComponent
{
public:
	DrawTextComponent(Actor* ownerP, Font* fontP, string textP, Color colorP, int drawOrderP = 100);
	virtual ~DrawTextComponent();
	DrawTextComponent() = delete;
	DrawTextComponent(const DrawTextComponent&) = delete;
	DrawTextComponent& operator=(const DrawTextComponent&) = delete;

	virtual void recalculateSDLTexture();
	virtual void setFont(Font* fontP);
	virtual void setText(const string textP);
	virtual void draw(Renderer& renderer) override;

	string getText() const { return text; }
	SDL_Texture* toSDLTexture() const { return SDLTexture; }

protected:
	Font* font{ nullptr };
	string text;
	Color color;
	SDL_Texture* SDLTexture{ nullptr };
	int width{ 0 };
	int height{ 0 };
};

