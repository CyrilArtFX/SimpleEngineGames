#pragma once
#include <SimpleEngine/Game.h>
#include "PongScene.h"

void run()
{
	auto& game = Game::instance();
	bool is_game_init = game.initialize("Pong", 800, 600, Color::black);

	if (is_game_init)
	{
		game.loadScene(new PongScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}