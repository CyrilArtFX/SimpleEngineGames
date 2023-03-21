#pragma once
#include "../Component.h"
#include "MoveComponents/MoveComponent.h"
#include <Components/CollisionComponents/ICollision.h>

//  this component must be added to actors who already has a move component and a collision component
//  this component will do interactions when the collision of the actor intersect with a border of the screen
//  these interactions are : block, bounce and return value (see the enum below)
//  for this component to work, its 'CheckBordersInteractions' function must be called after the move component's update

enum class ScreenBorderInteractions
{
	Block, //  this interaction will nullify the movement that causes the interaction (will return 0)
	Bounce, //  this interaction will nullify the movement that causes the interaction and negate the x or y velocity to produce a bounce effect (will return 0)
	SmoothBlock, //  like 'Block', but will bring the actor the nearest possible of the border (ideal for high velocity or mouse controlled actors, but heavier for the computer) (will return 0)
	SmoothBounce, //  like 'SmoothBlock', but will the negation of velocity to produce the bounce effect (will return 0)
	Return //  this interaction will return a value depending of the border that interact with the collision (1 for up, 2 for down, 3 for left, 4 for right) 

		//  in case of a multiple borders interactions and if all these borders has the interaction type 'Return', it will return the following :
		//  5 for up-left, 6 for up-right, 7 for down-left, 8 for down-right
		//  (if you made an actor that interact with three or four borders, why do you use this component on it ?)
};

class ScreenBorderInteractionComponent : public Component
{
public:
	ScreenBorderInteractionComponent(Actor* ownerP, MoveComponent* moveComponentP, ICollision* colComponentP) : Component(ownerP, 200), moveComponent(moveComponentP), colComponent(colComponentP) {}
	ScreenBorderInteractionComponent() = delete;
	ScreenBorderInteractionComponent(const ScreenBorderInteractionComponent&) = delete;
	ScreenBorderInteractionComponent& operator=(const ScreenBorderInteractionComponent&) = delete;

	void setInteractions(ScreenBorderInteractions upInteractionP, ScreenBorderInteractions downInteractionP, ScreenBorderInteractions leftInteractionP, ScreenBorderInteractions rightInteractionP);
	int checkBordersInteractions();

	void update(float dt) override;
	bool autoUpdate = false; //  if true, the update will run the 'CheckBordersInteractions' function (the block and bounce intersections types will work, but not the return one)

private:
	MoveComponent* moveComponent;
	ICollision* colComponent;

	ScreenBorderInteractions upInteraction = ScreenBorderInteractions::Return;
	ScreenBorderInteractions downInteraction = ScreenBorderInteractions::Return;
	ScreenBorderInteractions leftInteraction = ScreenBorderInteractions::Return;
	ScreenBorderInteractions rightInteraction = ScreenBorderInteractions::Return;
};

