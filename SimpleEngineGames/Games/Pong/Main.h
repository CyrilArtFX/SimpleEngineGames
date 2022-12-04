#pragma once
#include <SimpleEngine/Game.h>
#include "PongScene.h"

void run()
{
	auto& game = Game::instance();
	bool isGameInit = game.initialize("Pong", 800, 600, Color::black);

	if (isGameInit)
	{
		game.loadScene(new PongScene());
		game.loop();
		game.unloadScene();
	}

	game.close();
}