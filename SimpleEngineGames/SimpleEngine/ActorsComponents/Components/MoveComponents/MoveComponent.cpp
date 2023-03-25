#include "MoveComponent.h"
#include <SimpleEngine/Maths/Maths.h>
#include <SimpleEngine/ActorsComponents/Actor.h>

void MoveComponent::revertLastMovement(bool revertX, bool revertY)
{
	Vector2 reverted_pos = getCustomRevertedPosition(revertX, revertY);

	owner.setPosition(reverted_pos);
}

Vector2 MoveComponent::getCustomRevertedPosition(bool xReverted, bool yReverted)
{
	return Vector2{
		   xReverted ? actorPosBeforeMovement.x : owner.getPosition().x,
		   yReverted ? actorPosBeforeMovement.y : owner.getPosition().y
	};
}

void MoveComponent::setEnableXMovement(bool enable)
{
	enableXAxis = enable;
	if (!enableXAxis)
	{
		stopXMovement();
	}
}

void MoveComponent::setEnableYMovement(bool enable)
{
	enableYAxis = enable;
	if (!enableYAxis)
	{
		stopYMovement();
	}
}

void MoveComponent::stopXMovement()
{
}

void MoveComponent::stopYMovement()
{
}

void MoveComponent::reverseXMovement()
{
}

void MoveComponent::reverseYMovement()
{
}
