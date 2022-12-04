#pragma once
#include "MoveComponent.h"
#include <SimpleEngine/Utils/Vector2.h>
#include <SDL_stdinc.h>
#include <SDL_scancode.h>

class InputMoveComponent : public MoveComponent
{
public:
	InputMoveComponent(Actor* ownerP, int updateOrderP = 10) : MoveComponent(ownerP, updateOrderP) {}
	InputMoveComponent() = delete;
	InputMoveComponent(const InputMoveComponent&) = delete;
	InputMoveComponent& operator=(const InputMoveComponent&) = delete;

	void processInput(const Uint8* keyState);

	void setEnableXMovement(bool enable);
	bool getEnableXMovement() const { return enableXAxis; }
	void setEnableYMovement(bool enable);
	bool getEnableYMovement() const { return enableYAxis; }

	void setForwardKey(SDL_Scancode key);
	void setBackKey(SDL_Scancode key);
	void setRightKey(SDL_Scancode key);
	void setLeftKey(SDL_Scancode key);

private:
	bool enableXAxis{ true };
	bool enableYAxis{ true };

	SDL_Scancode forwardKey{ SDL_SCANCODE_W };
	SDL_Scancode backKey{ SDL_SCANCODE_S };
	SDL_Scancode rightKey{ SDL_SCANCODE_D };
	SDL_Scancode leftKey{ SDL_SCANCODE_A };
};
