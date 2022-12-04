#include "TestScene.h"
#include <SimpleEngine/Assets.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawRectComponent.h>
#include <SimpleEngine/ActorsComponents/Components/DrawCircleComponent.h>
#include <SimpleEngine/ActorsComponents/Components/DrawTextComponent.h>
#include <SimpleEngine/ActorsComponents/Components/CircleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/RectangleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/InputMoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>
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

	auto testCircle = new Actor();
	testCircle->setPosition(Vector2{ 250.0f, 400.0f });
	testCircle->setScale(0.3f);
	auto dcc = new DrawCircleComponent(testCircle, Vector2{ 0.0f, 0.0f }, 50.0f, Color::magenta, 50);
	auto ccc2 = new CircleCollisionComponent(testCircle);
	ccc2->setRadius(50.0f);
	ccc2->setOffset(Vector2{ 0.0f, 0.0f });
	auto mc = new MoveComponent(testCircle);
	mc->setSpeed(450.0f);
	mc->setVelocity(Vector2{ 0.8f, 0.3f });
	auto sbic = new ScreenBorderInteractionComponent(testCircle, mc, ccc2);
	sbic->SetInteractions(ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce);
	sbic->autoUpdate = true;

	auto testRect2 = new Actor();
	auto drc2 = new DrawRectComponent(testRect2, Rectangle{ 200.0f, 200.0f, 200.0f, 200.0f }, Color::red, 150);
	auto rcc = new RectangleCollisionComponent(testRect2);
	rcc->setRectangle(Rectangle{ 200.0f, 200.0f, 200.0f, 200.0f });
	auto imc = new InputMoveComponent(testRect2);
	imc->setSpeed(100.0f);
	auto sbic2 = new ScreenBorderInteractionComponent(testRect2, imc, rcc);
	sbic2->SetInteractions(ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block);
	sbic2->autoUpdate = true;

	auto testText = new Actor();
	testText->setPosition(Vector2{ 0.0f, 200.0f });
	auto dtc = new DrawTextComponent(testText, Assets::getFont("pixeled20"), "LET'S GO CA MARCHE", Color::green, 200);

	game->getCamera().setCamPos(Vector2{ -100.0f, 0.0f });
}