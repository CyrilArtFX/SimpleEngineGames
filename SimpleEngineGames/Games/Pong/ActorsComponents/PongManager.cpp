#include "PongManager.h"

PongManager::PongManager(PongBall* ballP, PlayerPaddle* leftPaddleP, CPUPaddle* rightPaddleP, Font* fontP) : Actor(), ball(ballP), leftPaddle(leftPaddleP), rightPaddle(rightPaddleP), font(fontP)
{
	leftDrawTextComp = new DrawTextComponent(this, font, "0",
		Color::white, Vector2{ 90.0f, 0.0f }, 1000);

	rightDrawTextComp = new DrawTextComponent(this, font, "0",
		Color::white, Vector2{ 700.0f, 0.0f }, 1000);

	victoryDrawTextComp = new DrawTextComponent(this, font, "NO PLAYER WINS !", 
		Color::white, Vector2{ 170.0f, 200.0f }, 1000);
	victoryDrawTextComp->setWillDraw(false);

	ball->setManager(this);
}

void PongManager::updateActor(float dt)
{
	if(!isGamePaused)
	{
		ball->testCollision(leftPaddle->GetCol(), false);
		ball->testCollision(rightPaddle->GetCol(), true);

		rightPaddle->updateVelocity(ball->getPosition().y);
	}
}

void PongManager::actorInput(const Uint8* keyState, const Uint32 mouseState)
{
	if (mouseState == SDL_BUTTON_LEFT)
	{
		ResumeGame();
		ResetScores();
	}
}

void PongManager::ScoreAtLeft()
{
	scoreRight++;
	if (scoreRight >= maxScore)
	{
		ball->resetPos();
		rightDrawTextComp->setText(std::to_string(scoreRight));
		victoryDrawTextComp->setText("RIGHT PLAYER WINS !");
		PauseGame();
	}
	else
	{
		ball->resetPos();
		rightDrawTextComp->setText(std::to_string(scoreRight));
		rightPaddle->resetPos();
	}
}

void PongManager::ScoreAtRight()
{
	scoreLeft++;
	if (scoreLeft >= maxScore)
	{
		ball->resetPos();
		leftDrawTextComp->setText(std::to_string(scoreLeft));
		victoryDrawTextComp->setText("LEFT PLAYER WINS !");
		PauseGame();
	}
	else
	{
		ball->resetPos();
		leftDrawTextComp->setText(std::to_string(scoreLeft));
		rightPaddle->resetPos();
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
	ball->pauseMovement();
	ball->SetDrawValue(false);
	leftPaddle->SetDrawValue(false);
	rightPaddle->SetDrawValue(false);
	victoryDrawTextComp->setWillDraw(true);
}

void PongManager::ResumeGame()
{
	isGamePaused = false;
	ball->resumeMovement();
	ball->SetDrawValue(true);
	leftPaddle->SetDrawValue(true);
	rightPaddle->SetDrawValue(true);
	victoryDrawTextComp->setWillDraw(false);
}
