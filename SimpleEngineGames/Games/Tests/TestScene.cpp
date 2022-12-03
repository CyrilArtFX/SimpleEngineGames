#include "TestScene.h"
#include <SimpleEngine/Assets.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawRectComponent.h>
#include <SimpleEngine/ActorsComponents/Components/DrawTextComponent.h>
#include <SimpleEngine/ActorsComponents/Components/CircleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/RectangleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/InputMoveComponent.h>
#include <SimpleEngine/Utils/Vector2.h>
#include <SimpleEngine/Utils/Rectangle.h>
#include <SimpleEngine/Utils/Color.h>

TestScene::TestScene() : Scene()
{
}

TestScene::~TestScene()
{
}

void TestScene::load(Game* game)
{
	//  load assets, create actors and setup base pos of camera here
	Assets::setAssetsPath("Games/Tests/Assets/");

	Assets::loadFont("Pixeled.ttf", "pixeled20", 20);

	auto testRect = new Actor();
	testRect->setPosition(Vector2{ 100.0f, 100.0f });
	auto drc = new DrawRectComponent(testRect, Rectangle{ 0.0f, 0.0f, 200.0f, 200.0f }, Color::blue, 100);
	auto ccc = new CircleCollisionComponent(testRect);
	ccc->setRadius(100.0f);
	ccc->setOffset(Vector2{ 100.0f, 100.0f });

	auto testRect2 = new Actor();
	auto drc2 = new DrawRectComponent(testRect2, Rectangle{ 200.0f, 200.0f, 200.0f, 200.0f }, Color::red, 150);
	auto rcc = new RectangleCollisionComponent(testRect2);
	rcc->setRectangle(Rectangle{ 200.0f, 200.0f, 200.0f, 200.0f });
	auto imc = new InputMoveComponent(testRect2);
	imc->setSpeed(100.0f);

	auto testText = new Actor();
	testText->setPosition(Vector2{ 0.0f, 200.0f });
	auto dtc = new DrawTextComponent(testText, Assets::getFont("pixeled20"), "LET'S GO CA MARCHE", Color::green, 200);

	game->getCamera().setCamPos(Vector2{ -100.0f, 0.0f });
}