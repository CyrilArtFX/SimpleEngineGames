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
	void processInput(const Uint8* keyState, const Uint32 mouseState, int mousePosX, int mousePosY) override;

private:
	int mouseX{ 0 };
	int mouseY{ 0 };
};

