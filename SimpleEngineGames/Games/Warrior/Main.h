#pragma once
#include <SimpleEngine/Game.h>
#include "WarriorScene.h"

void run()
{
	auto& game = Game::instance();
	bool is_game_init = game.initialize("Warrior Legends", 800, 600, Color::black);

	if (is_game_init)
	{
		game.loadScene(new WarriorScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}