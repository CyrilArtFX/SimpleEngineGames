#include "PongManager.h"
#include <SimpleEngine/Game.h>

PongManager::PongManager(PongBall* ballP, PlayerPaddle* leftPaddleP, CPUPaddle* rightPaddleP, Font* fontP) : Actor(), ball(ballP), leftPaddle(leftPaddleP), rightPaddle(rightPaddleP), font(fontP)
{
	leftDrawTextComp = new DrawTextComponent(this, font, "0",
		Color::white, Vector2{ 100.0f, 0.0f }, true, 1000);

	rightDrawTextComp = new DrawTextComponent(this, font, "0",
		Color::white, Vector2{ 700.0f, 0.0f }, true, 1000);

	victoryDrawTextComp = new DrawTextComponent(this, font, "PONG",
		Color::white, Vector2{ 400.0f, 180.0f }, true, 1000);

	resetDrawTextComp = new DrawTextComponent(this, font, "PRESS LEFT CLICK TO PLAY",
		Color::white, Vector2{ 400.0f, 330.0f }, true, 1000);


	for (int i = 0; i < 15; i++)
	{
		lineDrawRectComps[i] = new DrawRectComponent(this, Rectangle{ 399.0f, i * 40.0f, 2.0f, 20.0f }, Color::white, 10);
		lineDrawRectComps[i]->setWillDraw(false);
	}

	ball->SetManager(this);
	ball->PauseMovement();
	ball->SetDrawValue(false);
	leftPaddle->SetDrawValue(false);
	rightPaddle->SetDrawValue(false);
}

void PongManager::updateActor(float dt)
{
	if(!isGamePaused)
	{
		ball->TestCollision(leftPaddle->GetCol(), false);
		ball->TestCollision(rightPaddle->GetCol(), true);

		rightPaddle->UpdateVelocity(ball->getPosition().y);
	}
	else 
	{
		if (getGame().getKeyState(SDL_MOUSE_LEFT) == Pressed)
		{
			ResumeGame();
			ResetScores();
		}
	}
}

void PongManager::ScoreAtLeft()
{
	scoreRight++;
	if (scoreRight >= maxScore)
	{
		ball->ResetPos();
		rightDrawTextComp->setText(std::to_string(scoreRight));
		victoryDrawTextComp->setText("RIGHT PLAYER WINS !");
		PauseGame();
	}
	else
	{
		ball->ResetPos();
		rightDrawTextComp->setText(std::to_string(scoreRight));
		rightPaddle->ResetPos();
	}
}

void PongManager::ScoreAtRight()
{
	scoreLeft++;
	if (scoreLeft >= maxScore)
	{
		ball->ResetPos();
		leftDrawTextComp->setText(std::to_string(scoreLeft));
		victoryDrawTextComp->setText("LEFT PLAYER WINS !");
		PauseGame();
	}
	else
	{
		ball->ResetPos();
		leftDrawTextComp->setText(std::to_string(scoreLeft));
		rightPaddle->ResetPos();
	}
}

void PongManager::ResetScores()
{
	scoreLeft = 0;
	scoreRight = 0;
	leftDrawTextComp->setText(std::to_string(scoreLeft));
	rightDrawTextComp->setText(std::to_string(scoreRight));
}

void PongManager::PauseGame()
{
	isGamePaused = true;
	ball->PauseMovement();
	ball->SetDrawValue(false);
	leftPaddle->SetDrawValue(false);
	rightPaddle->SetDrawValue(false);
	victoryDrawTextComp->setWillDraw(true);
	resetDrawTextComp->setWillDraw(true);
	for (int i = 0; i < 15; i++)
	{
		lineDrawRectComps[i]->setWillDraw(false);
	}
}

void PongManager::ResumeGame()
{
	isGamePaused = false;
	ball->ResumeMovement();
	ball->SetDrawValue(true);
	leftPaddle->SetDrawValue(true);
	rightPaddle->SetDrawValue(true);
	victoryDrawTextComp->setWillDraw(false);
	resetDrawTextComp->setWillDraw(false);
	for (int i = 0; i < 15; i++)
	{
		lineDrawRectComps[i]->setWillDraw(true);
	}
}
