#include "PongManager.h"

PongManager::PongManager(PongBall* ballP, Font* fontP) : Actor(), ball(ballP), font(fontP)
{
	leftDrawTextComp = new DrawTextComponent(this, font, "0",
		Color::white, Vector2{ 90.0f, 0.0f }, 1000);

	rightDrawTextComp = new DrawTextComponent(this, font, "0",
		Color::white, Vector2{ 700.0f, 0.0f }, 1000);

	ball->setManager(this);
}

void PongManager::ScoreAtLeft()
{
	scoreRight++;
	if (scoreRight >= maxScore)
	{
		ResetScores();
	}
	else
	{
		rightDrawTextComp->setText(std::to_string(scoreRight));
	}
	ball->resetPos();
}

void PongManager::ScoreAtRight()
{
	scoreLeft++;
	if (scoreLeft >= maxScore)
	{
		ResetScores();
	}
	else
	{
		leftDrawTextComp->setText(std::to_string(scoreLeft));
	}
	ball->resetPos();
}

void PongManager::ResetScores()
{
	scoreLeft = 0;
	scoreRight = 0;
	leftDrawTextComp->setText(std::to_string(scoreLeft));
	rightDrawTextComp->setText(std::to_string(scoreRight));
}
