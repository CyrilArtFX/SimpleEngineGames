#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/CircleCollisionComponent.h>
#include <Components/MoveComponents/RotationInputMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>

class PlayerCar : public Actor
{
public:
	PlayerCar(Texture& carTextureP);
	PlayerCar() = delete;
	PlayerCar(const PlayerCar&) = delete;
	PlayerCar& operator=(const PlayerCar&) = delete;

	void TestGridCol(class GridComponent& grid);

private:
	DrawSpriteComponent* drawSpriteComp;
	CircleCollisionComponent* circleColComp;
	RotationInputMoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

