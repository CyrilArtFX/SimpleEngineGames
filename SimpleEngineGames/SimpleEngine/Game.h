#pragma once
#include <vector>
#include "Window.h"
#include "Renderer.h"
#include "Utils/Vector2.h"
#include "Assets.h"
#include "Camera.h"
#include "Scene.h"
#include "ActorsComponents/Actor.h"
using std::vector;

class Game
{
// Begin SINGLETON
public:
	static Game& instance()
	{
		static Game inst;
		return inst;
	}

	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(Game&&) = delete;
	Game& operator=(Game&&) = delete;

private:
	Game() = default;
// End SINGLETON

public:
	bool initialize(const char* windowName, int windowWidth, int windowHeight, Color backgroundColor);
	void loadScene(Scene* sceneP);
	void loop();
	void unloadScene();
	void close();

	void addActor(Actor* actor);
	void removeActor(Actor* actor);
	Renderer& getRenderer() { return renderer; }
	Camera& getCamera() { return camera; }

private:
	void processInput();
	void update(float dt);
	void render();

	Window window;
	Renderer renderer;
	Camera camera;
	Scene* scene{ nullptr };
	bool isRunning{ true };

	bool isUpdatingActors{ false };
	vector<Actor*> actors;
	vector<Actor*> pendingActors;
};

