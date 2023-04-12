#pragma once
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <Components/DrawComponents/DrawSpriteComponent.h>
#include <Components/CollisionComponents/CircleCollisionComponent.h>

class SpaceActor : public Actor
{
public:
	SpaceActor() : Actor() {}
	SpaceActor(const SpaceActor&) = delete;
	SpaceActor& operator=(const SpaceActor&) = delete;

	void EdgeWrap();

protected:
	DrawSpriteComponent* drawSpriteComp;
	CircleCollisionComponent* circleColComp;
};

