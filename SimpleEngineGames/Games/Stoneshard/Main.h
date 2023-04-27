#pragma once
#include <SimpleEngine/Game.h>
#include "StoneshardScene.h"

void run()
{
	auto& game = Game::instance();
	bool is_game_init = game.initialize("Stoneshard", 1920, 1080, Color::black);

	if (is_game_init)
	{
		game.loadScene(new StoneshardScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}
