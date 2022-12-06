#include "PongScene.h"
#include <SimpleEngine/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/PongBall.h"
#include "ActorsComponents/PlayerPaddle.h"

void PongScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Pong/Assets/");

	Assets::loadFont("Pixeled.ttf", "pixeled30", 30);


	auto ball = new PongBall();

	auto leftPaddle = new PlayerPaddle();
	leftPaddle->setPosition(Vector2{ 10.0f, 300.0f });


	ball->setPaddles(leftPaddle, nullptr);


	game->getCamera().setCamPos(Vector2{ 0.0f, 0.0f });
}