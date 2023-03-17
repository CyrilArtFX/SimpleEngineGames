#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/CircleCollisionComponent.h>
#include <Components/MoveComponents/RotationInputMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>

class PlayerCar : public Actor
{
public:
	PlayerCar(Texture& carTextureP, bool moveWithArrows);
	PlayerCar() = delete;
	PlayerCar(const PlayerCar&) = delete;
	PlayerCar& operator=(const PlayerCar&) = delete;

	void TestGridCol(class GridComponent& grid);
	bool TestFinishLineTrigger(class RectangleCollisionComponent& finishLine);

	void Reset(Vector2 position, float rotation);
	void SetDrawValue(bool draw);

private:
	DrawSpriteComponent* drawSpriteComp;
	CircleCollisionComponent* circleColComp;
	RotationInputMoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

