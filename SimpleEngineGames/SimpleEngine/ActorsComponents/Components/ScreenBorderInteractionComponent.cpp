#include "ScreenBorderInteractionComponent.h"
#include <SimpleEngine/Game.h>

void ScreenBorderInteractionComponent::SetInteractions(ScreenBorderInteractions upInteractionP, ScreenBorderInteractions downInteractionP, ScreenBorderInteractions leftInteractionP, ScreenBorderInteractions rightInteractionP)
{
	upInteraction = upInteractionP;
	downInteraction = downInteractionP;
	leftInteraction = leftInteractionP;
	rightInteraction = rightInteractionP;
}

int ScreenBorderInteractionComponent::CheckBordersInteractions()
{
	Vector2 velocity = Vector2::zero;
	Vector2 actorPos = owner.getPosition();
	float upBorderY = owner.getGame().getCamera().getCamPos().y;
	float downBorderY = owner.getGame().getScreenHeight() + owner.getGame().getCamera().getCamPos().y;
	float leftBorderX = owner.getGame().getCamera().getCamPos().x;
	float rightBorderX = owner.getGame().getScreenWidth() + owner.getGame().getCamera().getCamPos().x;
	int returnValue = 0;

	//  check up interaction
	if (colComponent->intersectWithY(upBorderY))
	{
		switch (upInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(false, true);
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(false, true);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ velocity.x, -velocity.y });
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(false, true);
				actorPos.y = colComponent->nearestYPosOfY(upBorderY);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(false, true);
				actorPos.y = colComponent->nearestYPosOfY(upBorderY);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ velocity.x, -velocity.y });
				break;

			case ScreenBorderInteractions::Return:
				returnValue = 1;
				break;

			default:
				break;
		}
	}

	//  check down interaction
	if (colComponent->intersectWithY(downBorderY))
	{
		switch (upInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(false, true);
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(false, true);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ velocity.x, -velocity.y });
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(false, true);
				actorPos.y = colComponent->nearestYPosOfY(downBorderY);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(false, true);
				actorPos.y = colComponent->nearestYPosOfY(downBorderY);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ velocity.x, -velocity.y });
				break;

			case ScreenBorderInteractions::Return:
				returnValue = 2;
				break;

			default:
				break;
		}
	}

	//  check left interaction
	if (colComponent->intersectWithX(leftBorderX))
	{
		switch (upInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(true, false);
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(true, false);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ -velocity.x, velocity.y });
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(true, false);
				actorPos.x = colComponent->nearestYPosOfY(leftBorderX);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(true, false);
				actorPos.x = colComponent->nearestYPosOfY(leftBorderX);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ -velocity.x, velocity.y });
				break;

			case ScreenBorderInteractions::Return:
				switch (returnValue)
				{
					case 1:
						returnValue = 5;
						break;
					case 2:
						returnValue = 7;
						break;
					default:
						returnValue = 3;
						break;
				}
				break;

			default:
				break;
		}
	}

	//  check right interaction
	if (colComponent->intersectWithX(rightBorderX))
	{
		switch (upInteraction)
		{
			case ScreenBorderInteractions::Block:
				moveComponent->revertLastMovement(true, false);
				break;

			case ScreenBorderInteractions::Bounce:
				moveComponent->revertLastMovement(true, false);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ -velocity.x, velocity.y });
				break;

			case ScreenBorderInteractions::SmoothBlock:
				moveComponent->revertLastMovement(true, false);
				actorPos.x = colComponent->nearestYPosOfY(rightBorderX);
				break;

			case ScreenBorderInteractions::SmoothBounce:
				moveComponent->revertLastMovement(true, false);
				actorPos.x = colComponent->nearestYPosOfY(rightBorderX);
				velocity = moveComponent->getVelocity();
				moveComponent->setVelocity(Vector2{ -velocity.x, velocity.y });
				break;

			case ScreenBorderInteractions::Return:
				switch (returnValue)
				{
					case 1:
						returnValue = 6;
						break;
					case 2:
						returnValue = 8;
						break;
					default:
						returnValue = 4;
						break;
				}
				break;

			default:
				break;
		}
	}

	owner.setPosition(actorPos);
	return returnValue;
}

void ScreenBorderInteractionComponent::update(float dt)
{
	if (autoUpdate)
	{
		CheckBordersInteractions();
	}
}
