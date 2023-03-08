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

void Actor::setPosition(Vector3 positionP)
{
	position = positionP;
	mustRecomputeWorldTransform = true;
}

void Actor::setScale(float scaleP)
{
	scale = scaleP;
	mustRecomputeWorldTransform = true;
}

void Actor::setRotation(Quaternion rotationP)
{
	rotation = rotationP;
	mustRecomputeWorldTransform = true;
}

void Actor::update(float dt)
{
	if (state == Actor::ActorState::Active)
	{
		updateComponents(dt);
		updateActor(dt);
		updateTransformMatrix();
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

void Actor::updateTransformMatrix()
{
	if (!mustRecomputeWorldTransform) return;

	mustRecomputeWorldTransform = false;
	worldTransform = Matrix4::createScale(scale);
	worldTransform *= Matrix4::createFromQuaternion(rotation);
	worldTransform *= Matrix4::createTranslation(position);
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

Vector3 Actor::getForward() const
{
	return Vector3::transform(Vector3::unitX, rotation);
}