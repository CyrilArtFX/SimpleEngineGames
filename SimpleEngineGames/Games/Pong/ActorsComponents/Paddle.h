#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/ActorsComponents/Components/DrawRectComponent.h>
#include <SimpleEngine/ActorsComponents/Components/RectangleCollisionComponent.h>

class Paddle : public Actor
{
public:
	Paddle();
	Paddle(const Paddle&) = delete;
	Paddle& operator=(const Paddle&) = delete;

	RectangleCollisionComponent* GetCol() { return rectColComp; }

protected:
	DrawRectComponent* drawRectComp;
	RectangleCollisionComponent* rectColComp;
};

