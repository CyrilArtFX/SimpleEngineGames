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
using std::map;

enum KeyState
{
	Up,
	Down,
	Pressed,
	Released
};

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

	int getScreenWidth();
	int getScreenHeight();
	KeyState getKeyState(SDL_Scancode keyCode);
	bool isKeyDown(SDL_Scancode keyCode);
	bool isKeyUp(SDL_Scancode keyCode);
	bool isKeyPressed(SDL_Scancode keyCode);
	bool isKeyReleased(SDL_Scancode keyCode);
	Vector2 getMousePosition();

private:
	void processInput();
	void update(float dt);
	void render();

	Window window;
	Renderer renderer;
	Camera camera;
	Scene* scene{ nullptr };
	bool isRunning{ true };

	bool debug{ false };
	bool isUpdatingActors{ false };
	vector<Actor*> actors;
	vector<Actor*> pendingActors;

	Vector2 mousePosition{ Vector2::zero };
	map<SDL_Scancode, KeyState> keys;
	vector<SDL_Scancode> pendingKeys;
};
