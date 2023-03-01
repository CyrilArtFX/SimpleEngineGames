#pragma once
#include <SimpleEngine/ActorsComponents/Component.h>
#include <SimpleEngine/Maths/Vector2.h>

class MoveComponent : public Component
{
public:
	MoveComponent(Actor* ownerP, int updateOrderP = 10) : Component(ownerP, updateOrderP) {}
	MoveComponent() = delete;
	MoveComponent(const MoveComponent&) = delete;
	MoveComponent& operator=(const MoveComponent&) = delete;

	void revertLastMovement(bool revertX, bool revertY);
	Vector2 getBeforeLastMovementPosition() const { return actorPosBeforeMovement; }

	void setEnableXMovement(bool enable);
	bool getEnableXMovement() const { return enableXAxis; }
	void setEnableYMovement(bool enable);
	bool getEnableYMovement() const { return enableYAxis; }

	virtual void stopXMovement();
	virtual void stopYMovement();
	virtual void reverseXMovement();
	virtual void reverseYMovement();

protected:
	bool enableXAxis{ true };
	bool enableYAxis{ true };
	Vector2 actorPosBeforeMovement{ Vector2::zero };
};