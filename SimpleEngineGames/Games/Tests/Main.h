#pragma once
#include "SimpleEngine/Game.h"
#include "TestScene.h"

void run()
{
    auto& game = Game::instance();
    bool isGameInit = game.initialize("Test Game", 800, 600, Color::black);

    if (isGameInit)
    {
        game.loadScene(new TestScene());
        game.loop();
        game.unloadScene();
    }

    game.close();
}