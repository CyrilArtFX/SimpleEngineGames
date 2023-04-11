#pragma once
#include <Components/MoveComponents/InputMoveComponent.h>
#include <SimpleEngine/Maths/Maths.h>

//  this component is a variant of the "RotationInputMoveComponent" made exclusively for the game "SpaceBattle"
//	the objective is later to make a cleaner rotation and velocity based move component that could replace both of them
// 
//  this component inherit from MoveComponent but doesn't take care of X and Y axis disabling, and it don't uses speed
//  this component will use the actor rotation and override any changes made to it
class SpaceShipMoveComponent : public InputMoveComponent
{
public:
	SpaceShipMoveComponent(Actor* ownerP, int updateOrderP = 10);
	SpaceShipMoveComponent() = delete;
	SpaceShipMoveComponent(const SpaceShipMoveComponent&) = delete;
	SpaceShipMoveComponent& operator=(const SpaceShipMoveComponent&) = delete;

	void update(float dt) override;

	void SetInputValues(float forwardAccelerationInputValueP, float angleInputValueP);
	void SetMotionValues(float persistantSpeedLossP, float maxSpeedP);

private:
	Vector2 GetPlayerDirection();
	void ChangePlayerRotation(float rotationAdd);

	float forwardAccelerationInputValue{ 5.0f }; //  in units per second
	float angleInputValue{ Maths::pi };  //  in angle (radians) per second
	float persistantSpeedLoss{ 0.05f }; //  the fraction of speed that is loss each second
	float maxSpeed{ 20.0f };
};

