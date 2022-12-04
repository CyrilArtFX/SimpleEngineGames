#pragma once
#include "MoveComponent.h"

//  this component does not uses speed and velocity from 'MoveComponent'
//  it derives from 'MoveComponent' only for practical reasons like the usage of 'ScreenBorderInteractionComponent'
//  i may reorganize the move components to make it better
//  i should also put the enable axis part in an interface so 'MouseMoveComponent' and 'InputMoveComponent' does not have code replication

class MouseMovComponent : public MoveComponent
{
public:
	MouseMovComponent(Actor* ownerP, int updateOrderP = 10) : MoveComponent(ownerP, updateOrderP) {}
	MouseMovComponent() = delete;
	MouseMovComponent(const MouseMovComponent&) = delete;
	MouseMovComponent& operator=(const MouseMovComponent&) = delete;

	void update(float dt) override;

	void setEnableXMovement(bool enable);
	bool getEnableXMovement() const { return enableXAxis; }
	void setEnableYMovement(bool enable);
	bool getEnableYMovement() const { return enableYAxis; }

private:
	bool enableXAxis{ true };
	bool enableYAxis{ true };
};

