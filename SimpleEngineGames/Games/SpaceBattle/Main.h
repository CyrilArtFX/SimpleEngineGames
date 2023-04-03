#pragma once
#include <SimpleEngine/Game.h>
#include "SpaceScene.h"

void run()
{
	auto& game = Game::instance();
	bool is_game_init = game.initialize("Space Battle", 800, 600, Color::black);

	if (is_game_init)
	{
		game.loadScene(new SpaceScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}