#pragma once
#include <SimpleEngine/Game.h>
#include "TestScene.h"

void run()
{
    auto& game = Game::instance();
    bool is_game_init = game.initialize("Test Game", 800, 600, Color::black);

    if (is_game_init)
    {
        game.loadScene(new TestScene());
        game.loop();
        game.unloadScene();
    }

    game.close();
}