#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawTextComponent.h>
#include "PongBall.h"

class PongManager : public Actor
{
public:
	PongManager(PongBall* ballP, Font* fontP);
	PongManager(const PongManager&) = delete;
	PongManager& operator=(const PongManager&) = delete;

	void ScoreAtLeft();
	void ScoreAtRight();

private:
	DrawTextComponent* leftDrawTextComp;
	DrawTextComponent* rightDrawTextComp;

	Font* font;

	PongBall* ball;

	int scoreLeft{ 0 };
	int scoreRight{ 0 };
};

