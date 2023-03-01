#include "Actor.h"
#include <algorithm>
#include <SimpleEngine/Maths/Maths.h>
#include <SimpleEngine/Game.h>
#include "Component.h"

Actor::Actor() : game(Game::instance())
{
	game.addActor(this);
}

Actor::~Actor()
{
	game.removeActor(this);
	//  remove all components of the actor
	while (!components.empty())
	{
		delete components.back();
	}
}

void Actor::setPosition(Vector2 positionP)
{
	position = positionP;
}

void Actor::setScale(float scaleP)
{
	scale = scaleP;
}

void Actor::setRotation(float rotationP)
{
	rotation = rotationP;
}

void Actor::update(float dt)
{
	if (state == Actor::ActorState::Active)
	{
		updateComponents(dt);
		updateActor(dt);
	}
}

void Actor::updateComponents(float dt)
{
	for (auto component : components)
	{
		component->update(dt);
	}
}

void Actor::debugComponents(Renderer& renderer) 
{
	for (auto component : components)
	{
		component->debug(renderer);
	}
}

void Actor::updateActor(float dt)
{
}

void Actor::addComponent(Component* component)
{
	//  we must insert the component in the right place in the vector depending of the component's update order
	int my_order = component->getUpdateOrder();
	auto iter = begin(components);
	for (; iter != end(components); ++iter)
	{
		if (my_order < (*iter)->getUpdateOrder())
		{
			break;
		}
	}

	components.insert(iter, component);
}

void Actor::removeComponent(Component* component)
{
	auto iter = std::find(begin(components), end(components), component);
	if (iter != end(components))
	{
		components.erase(iter);
	}
}

Vector2 Actor::getForward() const
{
	return Vector2(Maths::cos(rotation), -Maths::sin(rotation));
}