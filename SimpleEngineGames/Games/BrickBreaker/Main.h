#pragma once
#include <SimpleEngine/Game.h>
#include "BreakerScene.h"

void run()
{
	auto& game = Game::instance();
	bool is_game_init = game.initialize("Brick Breaker", 800, 600, Color::black);

	if (is_game_init)
	{
		game.loadScene(new BreakerScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}