#include "TestScene.h"
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawRectComponent.h>
#include <Components/DrawComponents/DrawCircleComponent.h>
#include <Components/DrawComponents/DrawTextComponent.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/CircleCollisionComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>
#include <Components/MoveComponents/InputMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>
#include <Components/GridComponents/GridComponent.h>
#include <Components/GridComponents/GridTileDrawRectangle.h>
#include <Components/GridComponents/GridTileDrawSprite.h>
#include <SimpleEngine/Maths/Vector2.h>
#include <SimpleEngine/Maths/Vector3.h>
#include <SimpleEngine/Maths/Rectangle.h>
#include <SimpleEngine/Utils/Color.h>

void TestScene::load(Game* game)
{
	//  load assets, create actors and setup base pos of camera here
	Assets::setAssetsPath("Games/Tests/Assets/");

	Assets::loadFont("Pixeled.ttf", "pixeled20", 20);
	Assets::loadTexture(game->getRenderer(), "Bekipan.png", "bekipan");
	Assets::loadGridMap("RacingTrackV1.lua", "testgrid");
	Assets::loadGridMap("zfq", "nullgrid");

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

	game->getCamera().setCamPos(Vector2{ -100.0f, 0.0f });*/

	auto test_text = new Actor();
	test_text->setPosition(Vector2{ 0.0f, 200.0f });
	auto dtc = new DrawTextComponent(test_text, Assets::getFont("pixeled20"), "LET'S GO CA MARCHE", Color::green, Vector2::zero, 200);


	auto test_sprite = new Actor();
	auto dsc = new DrawSpriteComponent(test_sprite, Assets::getTexture("bekipan"), Vector2{ 0.0f, 0.0f }, Renderer::Flip::None);
	auto rcc = new RectangleCollisionComponent(test_sprite);
	rcc->setRectangle(Rectangle{ 0.0f, 0.0f, 200.0f, 200.0f });
	auto imc = new InputMoveComponent(test_sprite);
	imc->setSpeed(100.0f);
	auto sbic2 = new ScreenBorderInteractionComponent(test_sprite, imc, rcc);
	sbic2->setInteractions(ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block, ScreenBorderInteractions::Block);
	sbic2->autoUpdate = true;
	test_sprite->setPosition(Vector2{ 300.0f, 200.0f });

	auto test_grid = new Actor();
	auto gc = new GridComponent(test_grid);

	gc->setGridSize(6, 4);
	gc->setTileSize(Vector2{ 50.0f, 35.0f });

	gc->setTileTraduction(0, new TileTraduction{ new GridTileDrawRectangle(Color::yellow, Rectangle{ 0.05f, 0.05f, 0.9f, 0.9f }), true });
	gc->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle(Color::magenta, Rectangle{ 0.05f, 0.05f, 0.9f, 0.9f }), false });
	gc->setTileTraduction(5, new TileTraduction{ new GridTileDrawRectangle(Color::cyan, Rectangle{ 0.05f, 0.05f, 0.9f, 0.9f }), false });
	gc->setTileTraduction(3, new TileTraduction{ new GridTileDrawSprite(Assets::getTexture("bekipan")), true });

	gc->setGridElement(0, 2, 1);
	gc->setGridElement(1, 1, 1);
	gc->setGridElement(1, 3, 1);
	gc->setGridElement(3, 0, 1);
	gc->setGridElement(5, 2, 1);
	gc->setGridElement(0, 0, 3);
	gc->setGridElement(4, 3, 5);

	test_grid->setPosition(Vector2{ 156.0f, 243.0f });


	auto test_grid_2 = new Actor();
	auto gc2 = new GridComponent(test_grid_2, Assets::getGridMap("testgrid"), 20);

	gc2->setTileSize(Vector2{ 15.0f, 15.0f });
	gc2->setTileTraduction(1, new TileTraduction{ new GridTileDrawRectangle(Color::blue, Rectangle::unitRect), true });
	test_grid_2->setScale(1.2f);

	test_grid_2->setPosition(Vector2{ 30.0f, 30.0f });

	auto test_grid_3 = new Actor();
	auto gc3 = new GridComponent(test_grid_3, Assets::getGridMap("nullgrid"));

	//game->getCamera().setCamPos(Vector2{ 140.0f, -100.0f });
}