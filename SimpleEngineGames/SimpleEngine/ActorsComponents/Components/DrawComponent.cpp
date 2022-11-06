#include "DrawComponent.h"
#include "../Actor.h"
#include "../../Game.h"

DrawComponent::DrawComponent(Actor* ownerP, int drawOrderP) : Component(ownerP), drawOrder(drawOrderP)
{
	owner.getGame().getRenderer().addDrawComponent(this);
}

DrawComponent::~DrawComponent()
{
	owner.getGame().getRenderer().removeDrawComponent(this);
}

void DrawComponent::draw(Renderer& renderer)
{
}