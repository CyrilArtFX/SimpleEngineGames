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
	int returnValue = 0;

	//  check up interaction
	if (colComponent->intersectWithHeight(0.0f + owner.getGame().getCamera().getCamPos().y))
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

			case ScreenBorderInteractions::Return:
				returnValue = 1;
				break;

			default:
				break;
		}
	}

	//  check down interaction
	if (colComponent->intersectWithHeight(owner.getGame().getScreenHeight() + owner.getGame().getCamera().getCamPos().y))
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

			case ScreenBorderInteractions::Return:
				returnValue = 2;
				break;

			default:
				break;
		}
	}

	//  check left interaction
	if (colComponent->intersectWithWidth(0.0f + owner.getGame().getCamera().getCamPos().x))
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
	if (colComponent->intersectWithWidth(owner.getGame().getScreenWidth() + owner.getGame().getCamera().getCamPos().x))
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

	return returnValue;
}

void ScreenBorderInteractionComponent::update(float dt)
{
	if (autoUpdate)
	{
		CheckBordersInteractions();
	}
}
