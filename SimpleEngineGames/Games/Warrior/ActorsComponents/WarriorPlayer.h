#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>
#include <Components/MoveComponents/InputMoveComponent.h>
#include <Components/ScreenBorderInteractionComponent.h>

class WarriorPlayer : public Actor
{
public:
	WarriorPlayer(Texture& textureP);
	WarriorPlayer() = delete;
	WarriorPlayer(const WarriorPlayer&) = delete;
	WarriorPlayer operator=(const WarriorPlayer&) = delete;

	void TestWallGridCol(class GridComponent& wallGrid);
	bool TestGridInteraction(class GridComponent& interactableGrid);
	bool TestTrophyTrigger(class RectangleCollisionComponent& trophy);

private:
	DrawSpriteComponent* drawSpriteComp;
	RectangleCollisionComponent* rectColComp;
	InputMoveComponent* moveComp;
	ScreenBorderInteractionComponent* screenBorderInterComp;
};

