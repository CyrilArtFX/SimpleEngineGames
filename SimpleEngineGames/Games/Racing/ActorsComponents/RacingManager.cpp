#include "RacingManager.h"
#include <iostream>
#include <SimpleEngine/Assets/Assets.h>
#include <SimpleEngine/Game.h>

RacingManager::RacingManager(RacingTrack* trackP, PlayerCar* playerOneCarP, PlayerCar* playerTwoCarP) : Actor(), track(trackP), playerOneCar(playerOneCarP), playerTwoCar(playerTwoCarP)
{
	playerOneCar->Reset(track->GetPlayerStartPos(6), Maths::pi * 0.5f);
	playerTwoCar->Reset(track->GetPlayerStartPos(6), Maths::pi * 0.5f);

	finishLineTrigger = new RectangleCollisionComponent(this);
	finishLineTrigger->setRectangle(Rectangle{ 40.0f, 480.0f, 40.0f, 80.0f });

	victoryTextComp = new DrawTextComponent(this, Assets::getFont("pixeled30"), "BLACK CAR WIN !", Color::white,
		Vector2{ getGame().getScreenWidth() / 2.0f, getGame().getScreenHeight() / 15.0f }, true);
	victoryTextComp->setWillDraw(false);
	resetTextComp = new DrawTextComponent(this, Assets::getFont("pixeled30"), "PRESS LEFT CLICK TO RESET", Color::white,
		Vector2{ getGame().getScreenWidth() / 2.0f, getGame().getScreenHeight() / 3.0f }, true);
	resetTextComp->setWillDraw(false);
}

void RacingManager::updateActor(float dt)
{
	if (isPaused)
	{
		if (getGame().isKeyPressed(SDL_MOUSE_LEFT))
		{
			ResumeGame();
		}
	}
	else
	{
		playerOneCar->TestGridCol(track->GetGridComp());
		playerTwoCar->TestGridCol(track->GetGridComp());

		if (playerOneCar->TestFinishLineTrigger(*finishLineTrigger))
		{
			PauseGame(false);
		}
		else if (playerTwoCar->TestFinishLineTrigger(*finishLineTrigger))
		{
			PauseGame(true);
		}
	}
}

void RacingManager::PauseGame(bool playerTwoWin)
{
	isPaused = true;

	playerOneCar->SetDrawValue(false);
	playerTwoCar->SetDrawValue(false);

	victoryTextComp->setText(playerTwoWin ? "GREEN CAR WIN !" : "RED CAR WIN !");
	victoryTextComp->setWillDraw(true);
	resetTextComp->setWillDraw(true);
}

void RacingManager::ResumeGame()
{
	victoryTextComp->setWillDraw(false);
	resetTextComp->setWillDraw(false);

	track->ResetTrack();
	playerOneCar->Reset(track->GetPlayerStartPos(6), Maths::pi * 0.5f);
	playerTwoCar->Reset(track->GetPlayerStartPos(6), Maths::pi * 0.5f);
	playerOneCar->SetDrawValue(true);
	playerTwoCar->SetDrawValue(true);

	isPaused = false;
}
