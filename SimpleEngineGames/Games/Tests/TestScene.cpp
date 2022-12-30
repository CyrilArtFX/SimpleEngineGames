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

void TestScene::load(Game* game)
{
	//  load assets, create actors and setup base pos of camera here
	Assets::setAssetsPath("Games/Tests/Assets/");

	Assets::loadFont("Pixeled.ttf", "pixeled20", 20);

	/*auto test_rect = new Actor();
	test_rect->setPosition(Vector2{ 100.0f, 100.0f });
	auto drc = new DrawRectComponent(test_rect, Rectangle{ 0.0f, 0.0f, 200.0f, 200.0f }, Color::blue, 100);
	auto ccc = new CircleCollisionComponent(test_rect);
	ccc->setRadius(100.0f);
	ccc->setOffset(Vector2{ 100.0f, 100.0f });

	auto test_circle = new Actor();
	test_circle->setPosition(Vector2{ 250.0f, 400.0f });
	test_circle->setScale(0.3f);
	auto dcc = new DrawCircleComponent(test_circle, Vector2{ 0.0f, 0.0f }, 50.0f, Color::magenta, 50);
	auto ccc2 = new CircleCollisionComponent(test_circle);
	ccc2->setRadius(50.0f);
	ccc2->setOffset(Vector2{ 0.0f, 0.0f });
	auto vmc = new VelocityMoveComponent(test_circle);
	vmc->setSpeed(450.0f);
	vmc->setVelocity(Vector2{ 0.8f, 0.3f });
	auto sbic = new ScreenBorderInteractionComponent(test_circle, vmc, ccc2);
	sbic->setInteractions(ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce, ScreenBorderInteractions::Bounce);
	sbic->autoUpdate = true;

	auto test_rect_2 = new Actor();
	auto drc2 = new DrawRectComponent(test_rect_2, Rectangle{ 200.0f, 200.0f, 200.0f, 200.0f }, Color::red, 150);
	auto rcc = new RectangleCollisionComponent(test_rect_2);
	rcc->setRectangle(Rectangle{ 200.0f, 200.0f, 200.0f, 200.0f });
	auto imc = new InputMoveComponent(test_rect_2);
	imc->setSpeed(100.0f);
	auto sbic2 = new ScreenBorderInteractionComponent(test_rect_2, imc, rcc);
	sbic2->setInteractions(ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block);
	sbic2->autoUpdate = true;

	auto test_text = new Actor();
	test_text->setPosition(Vector2{ 0.0f, 200.0f });
	auto dtc = new DrawTextComponent(test_text, Assets::getFont("pixeled20"), "LET'S GO CA MARCHE", Color::green, Vector2::zero, 200);

	game->getCamera().setCamPos(Vector2{ -100.0f, 0.0f });*/

	auto test_grid = new Actor();
}