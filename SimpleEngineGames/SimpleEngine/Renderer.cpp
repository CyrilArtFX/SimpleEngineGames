#include "Renderer.h"
#include <SDL_image.h>
#include "Utils/Log.h"
#include "Window.h"
#include "Utils/Rectangle.h"
#include "Utils/Vector2.h"
#include "Texture.h"
#include "Utils/Maths.h"
#include "ActorsComponents/Components/DrawComponent.h"
#include "Game.h"
#include <iostream>
#include <SDL_ttf.h>

Renderer::Renderer() : SDLRenderer(nullptr)
{
}

Renderer::~Renderer()
{
}

bool Renderer::initialize(Window& window, Color backgroundColorP)
{
	SDLRenderer = SDL_CreateRenderer(
		window.getSDLWindow(), -1,
		SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC
	);

	if (!SDLRenderer)
	{
		Log::error(LogCategory::Video, "Failed to create renderer");
		return false;
	}
	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		Log::error(LogCategory::Video, "Unable to initialize SDL_image");
		return false;
	}
	backgroundColor = backgroundColorP;
	return true;
}

void Renderer::beginDraw()
{
	SDL_SetRenderDrawColor(SDLRenderer, backgroundColor.r, backgroundColor.g, backgroundColor.b, backgroundColor.a);
	SDL_RenderClear(SDLRenderer);
}

void Renderer::draw()
{
	drawDrawComponents();
}

void Renderer::endDraw()
{
	TTF_Font* pixelFont = TTF_OpenFont("Sans.ttf", 24);
	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(pixelFont, "test", SDL_Color{ 255, 255, 255 });
	SDL_Texture* message = SDL_CreateTextureFromSurface(SDLRenderer, surfaceMessage);
	SDL_Rect messageRect = SDL_Rect{ 50, 50, 100, 100 };
	SDL_RenderCopy(SDLRenderer, message, NULL, &messageRect);

	SDL_RenderPresent(SDLRenderer);
}

void Renderer::drawRect(const Rectangle& rect, Color color)
{
	Vector2 camPos = Game::instance().getCamera().getCamPos();
	SDL_SetRenderDrawColor(SDLRenderer, color.r, color.g, color.b, color.a);
	Rectangle test = Rectangle{ rect.x - camPos.x, rect.y - camPos.y, rect.width, rect.height };
	auto drawRect = test.toSDLRect();
	SDL_RenderFillRect(SDLRenderer, &drawRect);
}

void Renderer::drawDrawComponents()
{
	for (auto drawComponent : drawComponents)
	{
		drawComponent->draw(*this);
	}
}

void Renderer::drawSprite(const Actor& actor, const Texture& tex, Rectangle srcRect, Vector2 origin, Flip flip) const
{
	Vector2 camPos = Game::instance().getCamera().getCamPos();
	SDL_Rect dstRect;
	Vector2 position = actor.getPosition() - camPos;
	float rotation = actor.getRotation();
	float scale = actor.getScale();

	dstRect.w = static_cast<int>(tex.getWidth() * scale);
	dstRect.h = static_cast<int>(tex.getHeight() * scale);

	dstRect.x = static_cast<int>(position.x - origin.x);
	dstRect.y = static_cast<int>(position.y - origin.y);

	SDL_Rect* srcSDL = nullptr;
	if (srcRect != Rectangle::nullRect)
	{
		srcSDL = new SDL_Rect{ Maths::round(srcRect.x), Maths::round(srcRect.y), 
			Maths::round(srcRect.width), Maths::round(srcRect.height) };
	}

	SDL_RenderCopyEx(SDLRenderer, tex.toSDLTexture(), srcSDL, &dstRect, -Maths::toDegrees(rotation), nullptr, SDL_FLIP_NONE);
	delete srcSDL;
}

void Renderer::close()
{
	SDL_DestroyRenderer(SDLRenderer);
}

void Renderer::addDrawComponent(DrawComponent* drawComponent)
{
	int spriteDrawOrder = drawComponent->getDrawOrder();
	auto iter = begin(drawComponents);
	for (; iter != end(drawComponents); ++iter)
	{
		if (spriteDrawOrder < (*iter)->getDrawOrder())
		{
			break;
		}
	}
	drawComponents.insert(iter, drawComponent);
}

void Renderer::removeDrawComponent(DrawComponent* drawComponent)
{
	auto iter = std::find(begin(drawComponents), end(drawComponents), drawComponent);
	drawComponents.erase(iter);
}