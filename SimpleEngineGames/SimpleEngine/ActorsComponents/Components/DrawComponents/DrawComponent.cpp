#include "DrawComponent.h"
#include <SimpleEngine/ActorsComponents/Actor.h>
#include <SimpleEngine/Game.h>

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

void DrawComponent::setWillDraw(bool willDrawP)
{
	willDraw = willDrawP;
}
