#include "PongScene.h"
#include <SimpleEngine/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/PongBall.h"
#include "ActorsComponents/PlayerPaddle.h"
#include "ActorsComponents/CPUPaddle.h"
#include "ActorsComponents/PongManager.h"

void PongScene::load(Game* game)
{
	Assets::setAssetsPath("Games/Pong/Assets/");

	Assets::loadFont("Pixeled.ttf", "pixeled30", 30);


	auto ball = new PongBall();

	auto left_paddle = new PlayerPaddle();
	left_paddle->setPosition(Vector2{ 10.0f, 300.0f });

	auto right_paddle = new CPUPaddle(Vector2{ game->getScreenWidth() - 20.0f, 300.0f });

	auto manager = new PongManager(ball, left_paddle, right_paddle, Assets::getFont("pixeled30"));


	game->getCamera().setCamPos(Vector2{ 0.0f, 0.0f });
}