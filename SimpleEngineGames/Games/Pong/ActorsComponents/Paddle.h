#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawRectComponent.h>
#include <Components/CollisionComponents/RectangleCollisionComponent.h>

class Paddle : public Actor
{
public:
	Paddle();
	Paddle(const Paddle&) = delete;
	Paddle& operator=(const Paddle&) = delete;

	RectangleCollisionComponent* GetCol() { return rectColComp; }
	void SetDrawValue(bool value);

protected:
	DrawRectComponent* drawRectComp;
	RectangleCollisionComponent* rectColComp;
};

