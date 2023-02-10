#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawSpriteComponent.h>
#include <SimpleEngine/ActorsComponents/Components/CircleCollisionComponent.h>
#include <SimpleEngine/ActorsComponents/Components/RotationInputMoveComponent.h>
#include <SimpleEngine/ActorsComponents/Components/ScreenBorderInteractionComponent.h>

class PlayerCar : public Actor
{
public:
	PlayerCar(Texture& carTextureP);
	PlayerCar() = delete;
	PlayerCar(const PlayerCar&) = delete;
	PlayerCar& operator=(const PlayerCar&) = delete;

	void updateActor(float dt) override;

private:
	DrawSpriteComponent* drawSpriteComp;
	CircleCollisionComponent* circleColComp;
	RotationInputMoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

