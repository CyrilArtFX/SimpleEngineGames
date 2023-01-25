#include "BreakerScene.h"
#include <SimpleEngine/Assets.h>
#include <SimpleEngine/Game.h>
#include "ActorsComponents/BreakerBall.h"
#include "ActorsComponents/BreakerPaddle.h"
#include "ActorsComponents/BreakerManager.h"
#include "ActorsComponents/BreakerGrid.h"

void BreakerScene::load(Game* game)
{
	Assets::setAssetsPath("Games/BrickBreaker/Assets/");


	auto ball = new BreakerBall();

	auto paddle = new BreakerPaddle();
	paddle->setPosition(Vector2{ 400.0f, 500.0f });

	auto grid = new BreakerGrid(10, 11, Vector2{ 80.0f, 20.0f }, Color::blue);
	grid->setPosition(Vector2{0.0f, 60.0f});

	auto manager = new BreakerManager(ball, paddle, grid);


	game->getCamera().setCamPos(Vector2{ 0.0f, 0.0f });
}
