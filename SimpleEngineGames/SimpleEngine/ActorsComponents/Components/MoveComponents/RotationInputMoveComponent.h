#pragma once
#include "InputMoveComponent.h"
#include <SDL_scancode.h>

//  this component inherit from MoveComponent but doesn't take care of X and Y axis disabling
//  this component will use the actor rotation and override any changes made to it
class RotationInputMoveComponent : public InputMoveComponent
{
public:
	RotationInputMoveComponent(Actor* ownerP, float startAngleP = 0.0f, int updateOrderP = 10);
	RotationInputMoveComponent() = delete;
	RotationInputMoveComponent(const RotationInputMoveComponent&) = delete;
	RotationInputMoveComponent& operator=(const RotationInputMoveComponent&) = delete;

	void update(float dt) override;

	void setInputValues(float forwardSpeedInputValueP, float backSpeedInputValue, float angleInputValueP);
	void setMotionValues(float persistantSpeedLooseP, float minSpeedForFullControlP);

	void setArbitraryAngle(float arbitraryAngle);

private:
	void applyRotationChange();
	bool isUserInputItsDirection();

	float angle;
	float forwardSpeedInputValue{ 1.0f };
	float backSpeedInputValue{ 0.5f };
	float angleInputValue{ 0.05f };
	float persistantSpeedLoose{ 0.45f }; //  the fraction of speed that is lost each second
	float minSpeedForFullControl{ 15.0f };
};

