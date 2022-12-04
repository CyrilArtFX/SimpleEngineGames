#include "Renderer.h"
#include <SDL_image.h>
#include "Utils/Log.h"
#include "Window.h"
#include "Utils/Rectangle.h"
#include "Utils/Vector2.h"
#include "Texture.h"
#include "Utils/Maths.h"
#include "Utils/Font.h"
#include "ActorsComponents/Components/DrawComponent.h"
#include "ActorsComponents/Components/DrawTextComponent.h"
#include "ActorsComponents/Components/CollisionComponent.h"
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
	if (TTF_Init() == -1)
	{
		Log::error(LogCategory::Video, "Unable to initialize SDL_ttf");
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
	SDL_RenderPresent(SDLRenderer);
}

void Renderer::drawDrawComponents()
{
	for (auto drawComponent : drawComponents)
	{
		drawComponent->draw(*this);
	}
}

void Renderer::drawDebugRect(const Actor& actor, const Rectangle& rect, Color color)
{
	Vector2 camPos = Game::instance().getCamera().getCamPos();
	SDL_Rect drawRect;
	Vector2 position = actor.getPosition() - camPos;
	float scale = actor.getScale();

	drawRect.w = static_cast<int>(rect.width * scale);
	drawRect.h = static_cast<int>(rect.height * scale);

	drawRect.x = static_cast<int>(rect.x + position.x);
	drawRect.y = static_cast<int>(rect.y + position.y);


	SDL_SetRenderDrawColor(SDLRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderDrawRect(SDLRenderer, &drawRect);

}

void Renderer::drawDebugCircle(const Actor& actor, const Vector2& circleOffset, int radius, Color color)
{
	//  midpoint circle algorithm 
	//  (found on https://stackoverflow.com/questions/38334081/howto-draw-circles-arcs-and-vector-graphics-in-sdl)
	Vector2 camPos = Game::instance().getCamera().getCamPos();
	const int centreX = static_cast<int>(actor.getPosition().x + circleOffset.x - camPos.x);
	const int centreY = static_cast<int>(actor.getPosition().y + circleOffset.y - camPos.y);

	radius *= actor.getScale();
	const int diameter = radius * 2;

	int x = radius - 1;
	int y = 0;
	int tx = 1;
	int ty = 1;
	int error = tx - diameter;

	while (x >= y)
	{
		SDL_SetRenderDrawColor(SDLRenderer, color.r, color.g, color.b, color.a);

		SDL_RenderDrawPoint(SDLRenderer, centreX + x, centreY - y);
		SDL_RenderDrawPoint(SDLRenderer, centreX + x, centreY + y);
		SDL_RenderDrawPoint(SDLRenderer, centreX - x, centreY - y);
		SDL_RenderDrawPoint(SDLRenderer, centreX - x, centreY + y);
		SDL_RenderDrawPoint(SDLRenderer, centreX + y, centreY - x);
		SDL_RenderDrawPoint(SDLRenderer, centreX + y, centreY + x);
		SDL_RenderDrawPoint(SDLRenderer, centreX - y, centreY - x);
		SDL_RenderDrawPoint(SDLRenderer, centreX - y, centreY + x);

		if (error <= 0)
		{
			y++;
			error += ty;
			ty += 2;
		}

		if (error > 0)
		{
			x--;
			tx += 2;
			error += tx - diameter;
		}
	}
}

void Renderer::drawRect(const Actor& actor, const Rectangle& rect, Color color)
{
	Vector2 camPos = Game::instance().getCamera().getCamPos();
	SDL_Rect drawRect;
	Vector2 position = actor.getPosition() - camPos;
	float scale = actor.getScale();
	
	drawRect.w = static_cast<int>(rect.width * scale);
	drawRect.h = static_cast<int>(rect.height * scale);

	drawRect.x = static_cast<int>(rect.x + position.x);
	drawRect.y = static_cast<int>(rect.y + position.y);


	SDL_SetRenderDrawColor(SDLRenderer, color.r, color.g, color.b, color.a);
	SDL_RenderFillRect(SDLRenderer, &drawRect);
}

void Renderer::drawCircle(const Actor& actor, const Vector2& circleOffset, int radius, Color color)
{
	//  surely not the best optimized circle algorithm
	//  (found on https://stackoverflow.com/questions/65723827/sdl2-function-to-draw-a-filled-circle)
	Vector2 camPos = Game::instance().getCamera().getCamPos();
	const int centreX = static_cast<int>(actor.getPosition().x + circleOffset.x - camPos.x);
	const int centreY = static_cast<int>(actor.getPosition().y + circleOffset.y - camPos.y);
	radius *= actor.getScale();

	SDL_SetRenderDrawColor(SDLRenderer, color.r, color.g, color.b, color.a);
	for (int w = 0; w < radius * 2; w++)
	{
		for (int h = 0; h < radius * 2; h++)
		{
			int dx = radius - w;
			int dy = radius - h;
			if ((dx * dx + dy * dy) <= (radius * radius))
			{
				SDL_RenderDrawPoint(SDLRenderer, centreX + dx, centreY + dy);
			}
		}
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

void Renderer::drawText(const Actor& actor, const class DrawTextComponent* text, int width, int height)
{
	Vector2 camPos = Game::instance().getCamera().getCamPos();
	SDL_Rect dstRect;
	Vector2 position = actor.getPosition() - camPos;
	float rotation = actor.getRotation();
	float scale = actor.getScale();

	dstRect.w = static_cast<int>(scale * width);
	dstRect.h = static_cast<int>(scale * height);

	dstRect.x = static_cast<int>(position.x);
	dstRect.y = static_cast<int>(position.y);

	SDL_Rect* srcSDL = nullptr;

	SDL_RenderCopyEx(SDLRenderer, text->toSDLTexture(), srcSDL, &dstRect, -Maths::toDegrees(rotation), nullptr, SDL_FLIP_NONE);
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