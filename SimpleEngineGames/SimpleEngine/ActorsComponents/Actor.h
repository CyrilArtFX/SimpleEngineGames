#pragma once
#include <vector>
#include "SDL_stdinc.h"
#include <SimpleEngine/Maths/Vector2.h>
#include <SimpleEngine/Maths/Vector3.h>
#include <SimpleEngine/Maths/Quaternion.h>
#include <SimpleEngine/Maths/Matrix4.h>
using std::vector;

class Game;
class Component;
class Renderer;

class Actor
{
public:
	enum class ActorState
	{
		Active,
		Paused,
		Dead
	};

	Actor();
	virtual ~Actor();
	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;

	Game& getGame() const { return game; }
	const ActorState getState() const { return state; }
	const Vector3 getPosition() const { return position; }
	const float getScale() const { return scale; }
	const Quaternion getRotation() const { return rotation; }
	Vector3 getForward() const;

	void setPosition(Vector3 positionP);
	void setScale(float scaleP);
	void setRotation(Quaternion rotationP);

	void update(float dt);
	void updateComponents(float dt);
	void debugComponents(Renderer& renderer);
	virtual void updateActor(float dt);
	void updateTransformMatrix();
	void addComponent(Component* component);
	void removeComponent(Component* component);

private:
	Game& game;
	ActorState state{ ActorState::Active };
	Vector3 position{ Vector3::zero };
	float scale{ 1.0f };
	Quaternion rotation{ Quaternion::identity };
	Matrix4 worldTransform;
	bool mustRecomputeWorldTransform{ true };

	vector<Component*> components;
};

