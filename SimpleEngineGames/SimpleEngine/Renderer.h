#pragma once
#include <SDL.h>
#include "ActorsComponents/Actor.h"
#include "Utils/Color.h"

class Window;
struct Rectangle;
struct Vector2;

class Renderer
{
public:
	enum class Flip
	{
		None = SDL_FLIP_NONE,
		Horizontal = SDL_FLIP_HORIZONTAL,
		Vertical = SDL_FLIP_VERTICAL
	};

	Renderer();
	~Renderer();
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

	SDL_Renderer* toSDLRenderer() const { return SDLRenderer; }

	bool initialize(Window& window, Color backgroundColorP);
	void beginDraw();
	void draw();
	void endDraw();
	void close();

	void addDrawComponent(class DrawComponent* drawComponent);
	void removeDrawComponent(class DrawComponent* drawComponent);
	void drawDrawComponents();
	void drawRect(const Rectangle& rect, Color color);
	void drawSprite(const Actor& actor, const class Texture& tex, Rectangle srcRect, Vector2 origin, Flip flip) const;

private:
	SDL_Renderer* SDLRenderer{ nullptr };
	Color backgroundColor{ Color::black };
	std::vector<DrawComponent*> drawComponents;
};

