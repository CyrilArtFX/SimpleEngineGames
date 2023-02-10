#pragma once
#include <SimpleEngine/Game.h>
#include "RacingScene.h"

void run()
{
	auto& game = Game::instance();
	bool is_game_init = game.initialize("Racing Game", 800, 600, Color::black);

	if (is_game_init)
	{
		game.loadScene(new RacingScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}