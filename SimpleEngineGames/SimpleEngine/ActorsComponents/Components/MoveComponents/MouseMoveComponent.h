#pragma once
#include "MoveComponent.h"

class MouseMoveComponent : public MoveComponent
{
public:
	MouseMoveComponent(Actor* ownerP, int updateOrderP = 10) : MoveComponent(ownerP, updateOrderP) {}
	MouseMoveComponent() = delete;
	MouseMoveComponent(const MouseMoveComponent&) = delete;
	MouseMoveComponent& operator=(const MouseMoveComponent&) = delete;

	void update(float dt) override;
};

