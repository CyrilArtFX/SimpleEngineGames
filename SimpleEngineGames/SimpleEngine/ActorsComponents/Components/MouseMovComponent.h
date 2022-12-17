#pragma once
#include "MoveComponent.h"

class MouseMovComponent : public MoveComponent
{
public:
	MouseMovComponent(Actor* ownerP, int updateOrderP = 10) : MoveComponent(ownerP, updateOrderP) {}
	MouseMovComponent() = delete;
	MouseMovComponent(const MouseMovComponent&) = delete;
	MouseMovComponent& operator=(const MouseMovComponent&) = delete;

	void update(float dt) override;
};

