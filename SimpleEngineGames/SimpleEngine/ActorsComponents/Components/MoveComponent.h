#pragma once
#include "../Component.h"
#include <SimpleEngine/Utils/Vector2.h>

class MoveComponent : public Component
{
public:
	MoveComponent(Actor* ownerP, int updateOrderP = 10) : Component(ownerP, updateOrderP) {}
	MoveComponent() = delete;
	MoveComponent(const MoveComponent&) = delete;
	MoveComponent& operator=(const MoveComponent&) = delete;

	Vector2 getVelocity() const { return velocity; }
	void setVelocity(Vector2 velocityP);
	float getSpeed() const { return speed; }
	void setSpeed(float speedP);

	virtual void update(float dt) override;
	void revertLastMovement(bool revertOnlyX, bool revertOnlyY);

protected:
	Vector2 velocity{ Vector2::zero };
	float speed{ 0.0f };
	Vector2 actorPosBeforeMovement;
};