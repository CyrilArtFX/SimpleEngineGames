#pragma once
#include "VelocityMoveComponent.h"
#include <SDL_stdinc.h>
#include <SDL_scancode.h>

class InputMoveComponent : public VelocityMoveComponent
{
public:
	InputMoveComponent(Actor* ownerP, int updateOrderP = 10) : VelocityMoveComponent(ownerP, updateOrderP) {}
	InputMoveComponent() = delete;
	InputMoveComponent(const InputMoveComponent&) = delete;
	InputMoveComponent& operator=(const InputMoveComponent&) = delete;

	void update(float dt) override;

	void setForwardKey(SDL_Scancode key);
	void setBackKey(SDL_Scancode key);
	void setRightKey(SDL_Scancode key);
	void setLeftKey(SDL_Scancode key);

private:
	SDL_Scancode forwardKey{ SDL_SCANCODE_W };
	SDL_Scancode backKey{ SDL_SCANCODE_S };
	SDL_Scancode rightKey{ SDL_SCANCODE_D };
	SDL_Scancode leftKey{ SDL_SCANCODE_A };
};
