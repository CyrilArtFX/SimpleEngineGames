#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawTextComponent.h>
#include <Components/DrawComponents/DrawRectComponent.h>
#include "PongBall.h"
#include "PlayerPaddle.h"
#include "CPUPaddle.h"

class PongManager : public Actor
{
public:
	PongManager(PongBall* ballP, PlayerPaddle* leftPaddleP, CPUPaddle* rightPaddleP, Font* fontP);
	PongManager() = delete;
	PongManager(const PongManager&) = delete;
	PongManager& operator=(const PongManager&) = delete;

	void updateActor(float dt) override;

	void ScoreAtLeft();
	void ScoreAtRight();

private:
	void ResetScores();
	void PauseGame();
	void ResumeGame();

	DrawTextComponent* leftDrawTextComp;
	DrawTextComponent* rightDrawTextComp;
	DrawTextComponent* victoryDrawTextComp;
	DrawTextComponent* resetDrawTextComp;

	DrawRectComponent* lineDrawRectComps[15];

	Font* font;

	PongBall* ball;
	PlayerPaddle* leftPaddle;
	CPUPaddle* rightPaddle;

	int scoreLeft{ 0 };
	int scoreRight{ 0 };
	int maxScore{ 3 };

	bool isGamePaused{ true };
};

