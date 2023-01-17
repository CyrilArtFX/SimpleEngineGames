#include "ScreenBorderInteractionComponent.h"
#include <SimpleEngine/Game.h>

void ScreenBorderInteractionComponent::setInteractions(ScreenBorderInteractions upInteractionP, ScreenBorderInteractions downInteractionP, ScreenBorderInteractions leftInteractionP, ScreenBorderInteractions rightInteractionP)
{
	upInteraction = upInteractionP;
	downInteraction = downInteractionP;
	leftInteraction = leftInteractionP;
	rightInteraction = rightInteractionP;
}

int ScreenBorderInteractionComponent::checkBordersInteractions()
{
	Vector2 actor_pos = owner.getPosition();
	float up_border_y = owner.getGame().getCamera().getCamPos().y;
	float down_border_y = owner.getGame().getScreenHeight() + owner.getGame().getCamera().getCamPos().y;
	float left_border_x = owner.getGame().getCamera().getCamPos().x;
	float right_border_x = owner.getGame().getScreenWidth() + owner.getGame().getCamera().getCamPos().x;
	int return_value = 0;

	//  check up interaction
	if (colComponent->intersectWithY(up_border_y))
	{
		switch (upInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = owner.getPosition().y;
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = owner.getPosition().y;
				moveComponent->reverseYMovement();
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = colComponent->nearestYPosOfY(up_border_y);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = colComponent->nearestYPosOfY(up_border_y);
				moveComponent->reverseYMovement();
				break;

			case ScreenBorderInteractions::Return:
				return_value = 1;
				break;

			default:
				break;
		}
	}

	//  check down interaction
	if (colComponent->intersectWithY(down_border_y))
	{
		switch (downInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = owner.getPosition().y;
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = owner.getPosition().y;
				moveComponent->reverseYMovement();
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = colComponent->nearestYPosOfY(down_border_y);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(false, true);
				actor_pos.y = colComponent->nearestYPosOfY(down_border_y);
				moveComponent->reverseYMovement();
				break;

			case ScreenBorderInteractions::Return:
				return_value = 2;
				break;

			default:
				break;
		}
	}

	//  check left interaction
	if (colComponent->intersectWithX(left_border_x))
	{
		switch (leftInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = owner.getPosition().x;
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = owner.getPosition().x;
				moveComponent->reverseXMovement();
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = colComponent->nearestXPosOfX(left_border_x);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = colComponent->nearestXPosOfX(left_border_x);
				moveComponent->reverseXMovement();
				break;

			case ScreenBorderInteractions::Return:
				switch (return_value)
				{
					case 1:
						return_value = 5;
						break;
					case 2:
						return_value = 7;
						break;
					default:
						return_value = 3;
						break;
				}
				break;

			default:
				break;
		}
	}

	//  check right interaction
	if (colComponent->intersectWithX(right_border_x))
	{
		switch (rightInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = owner.getPosition().x;
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = owner.getPosition().x;
				moveComponent->reverseXMovement();
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = colComponent->nearestXPosOfX(right_border_x);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(true, false);
				actor_pos.x = colComponent->nearestXPosOfX(right_border_x);
				moveComponent->reverseXMovement();
				break;

			case ScreenBorderInteractions::Return:
				switch (return_value)
				{
					case 1:
						return_value = 6;
						break;
					case 2:
						return_value = 8;
						break;
					default:
						return_value = 4;
						break;
				}
				break;

			default:
				break;
		}
	}

	owner.setPosition(actor_pos);
	return return_value;
}

void ScreenBorderInteractionComponent::update(float dt)
{
	if (autoUpdate)
	{
		checkBordersInteractions();
	}
}
