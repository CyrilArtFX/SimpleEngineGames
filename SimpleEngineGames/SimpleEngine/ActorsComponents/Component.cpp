#include "Component.h"
#include "Actor.h"
#include <SimpleEngine/Renderer.h>

Component::Component(Actor* ownerP, int updateOrderP) : owner(*ownerP), updateOrder(updateOrderP)
{
	owner.addComponent(this);
}

Component::~Component()
{
	owner.removeComponent(this);
}

void Component::update(float dt)
{
}

void Component::processInput(const Uint8* keyState, const Uint32 mouseState, int mousePosX, int mousePosY)
{
}

void Component::debug(Renderer& renderer)
{

}