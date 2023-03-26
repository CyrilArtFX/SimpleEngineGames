#include "WarriorManager.h"
#include <SimpleEngine/Game.h>
#include <SimpleEngine/Assets/Assets.h>
#include <string>

WarriorManager::WarriorManager(WarriorGrids* gridsP, WarriorPlayer* playerP) : Actor(), grids(gridsP), player(playerP)
{
	player->setPosition(grids->GetPlayerStartPos(4));

	keyCountTextComp = new DrawTextComponent(this, Assets::getFont("pixeled20"), "Keys in hand : 0", Color::black, Vector2{ 25.0f, -5.0f }, false);
	SetKeyCountText();
	resetTextComp = new DrawTextComponent(this, Assets::getFont("pixeled20"), "Press R to reset", Color::black, Vector2{ 510.0f, 545.0f }, false);

	trophyDrawComp = new DrawSpriteComponent(this, Assets::getTexture("trophy"), Vector2{ 409.0f, 459.0f }, Renderer::Flip::None);
	trophyColComp = new RectangleCollisionComponent(this);
	trophyColComp->setRectangle(Rectangle{ 409.0f, 459.0f, 32.0f, 32.0f });
}

void WarriorManager::updateActor(float dt)
{
	if (getGame().isKeyPressed(SDL_SCANCODE_R))
	{
		ResetGame();
	}

	if (keysInHand > 0)
	{
		int door_pos_x, door_pos_y;
		if (player->TestGridInteraction(grids->GetDoorsGridComp(), &door_pos_x, &door_pos_y))
		{
			keysInHand--;
			SetKeyCountText();
			grids->RemoveDoor(door_pos_x, door_pos_y);
		}
	}

	player->TestWallGridCol(grids->GetWallsGridComp());

	int key_pos_x, key_pos_y;
	if (player->TestGridInteraction(grids->GetKeysGridComp(), &key_pos_x, &key_pos_y))
	{
		keysInHand++;
		SetKeyCountText();
		grids->RemoveKey(key_pos_x, key_pos_y);
	}

	if (player->TestTrophyTrigger(*trophyColComp))
	{
		ResetGame();
	}
}

void WarriorManager::ResetGame()
{
	keysInHand = 0;
	SetKeyCountText();
	grids->ResetGrids();
	player->setPosition(grids->GetPlayerStartPos(4));
}

void WarriorManager::SetKeyCountText()
{
	std::string text = "Keys in hand : ";
	text += std::to_string(keysInHand);
	keyCountTextComp->setText(text);
}