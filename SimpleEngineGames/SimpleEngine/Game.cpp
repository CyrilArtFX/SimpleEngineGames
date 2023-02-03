#include "Game.h"
#include "Timer.h"
#include "Utils/Log.h"
#include <iostream>

bool Game::initialize(const char* windowName, int windowWidth, int windowHeight, Color backgroundColor)
{
	bool is_window_init = window.initialize(windowName, windowWidth, windowHeight);
	bool is_renderer_init = renderer.initialize(window, backgroundColor);
	return is_window_init && is_renderer_init;
}

void Game::loadScene(Scene* sceneP)
{
	unloadScene();
	scene = sceneP;
	scene->load(this);
}

void Game::loop()
{
	Timer timer;
	float dt = 0;

	while (isRunning) 
	{
		dt = timer.computeDeltaTime() / 1000.0f;
		processInput();
		update(dt);
		render();
		timer.delayTime();
	}
}

void Game::unloadScene()
{
	if (scene == nullptr) return;
	while (!actors.empty())
	{
		//delete actors.back();  //  not understood why but it causes an error when closing the window
		actors.pop_back();  //  so I use this instead, I think it's not the correct way to do this but it doesn't causes an error
	}
	Assets::clear();
	delete scene;
}

void Game::close()
{
	window.close();
	SDL_Quit();
}

KeyState Game::getKeyState(SDL_Scancode keyCode)
{
	if (keys.find(keyCode) == keys.end())
	{
		return KeyState::Up;
	}
	else
	{
		return keys[keyCode];
	}
}

Vector2 Game::getMousePosition()
{
	return mousePosition;
}

void Game::processInput()
{
	if (!pendingKeys.empty())
	{
		for (auto itr = pendingKeys.begin(); itr != pendingKeys.end(); itr++)
		{
			SDL_Scancode key_code = *itr;
			switch (getKeyState(key_code))
			{
				case KeyState::Pressed:
					keys[key_code] = KeyState::Down;
				break;
				case KeyState::Released:
					keys[key_code] = KeyState::Up;
				break;
			}
		}
		pendingKeys.clear();
	}

	// SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type) //  register all type of keys (keyboard and mouse buttons) in the map when they are pressed or released
		{
			case SDL_QUIT: //  quit game if the window quit button is pressed
				isRunning = false;
			break;

			case SDL_KEYDOWN: //  register the key as pressed in the map
				if (keys.find(event.key.keysym.scancode) == keys.end())
				{
					keys.emplace(event.key.keysym.scancode, KeyState::Pressed);
					pendingKeys.push_back(event.key.keysym.scancode);
				}
				else
				{
					keys[event.key.keysym.scancode] = KeyState::Pressed;
					pendingKeys.push_back(event.key.keysym.scancode);
				}
			break;
			case SDL_KEYUP: //  register the key as released in the map
				keys[event.key.keysym.scancode] = KeyState::Released;
				pendingKeys.push_back(event.key.keysym.scancode);
			break;

			default: //  part for the mouse (SDL_SCANCODE has been modified for this to be possible)
				switch (event.key.keysym.scancode)
				{
					case SDL_MOUSE_LEFT_PRESSED: //  register left mouse code as pressed
						if (keys.find(SDL_MOUSE_LEFT) == keys.end())
						{
							keys.emplace(SDL_MOUSE_LEFT, KeyState::Pressed);
							pendingKeys.push_back(SDL_MOUSE_LEFT);
						}
						else
						{
							keys[SDL_MOUSE_LEFT] = KeyState::Pressed;
							pendingKeys.push_back(SDL_MOUSE_LEFT);
						}
					break;
					case SDL_MOUSE_LEFT_RELEASED: //  register left mouse code as released
						keys[SDL_MOUSE_LEFT] = KeyState::Released;
						pendingKeys.push_back(SDL_MOUSE_LEFT);
					break;

					case SDL_MOUSE_MIDDLE_PRESSED:  //  register middle mouse code as pressed
						if (keys.find(SDL_MOUSE_MIDDLE) == keys.end())
						{
							keys.emplace(SDL_MOUSE_MIDDLE, KeyState::Pressed);
							pendingKeys.push_back(SDL_MOUSE_MIDDLE);
						}
						else
						{
							keys[SDL_MOUSE_MIDDLE] = KeyState::Pressed;
							pendingKeys.push_back(SDL_MOUSE_MIDDLE);
						}
					break;
					case SDL_MOUSE_MIDDLE_RELEASED: //  register middle mouse code as released
						keys[SDL_MOUSE_MIDDLE] = KeyState::Released;
						pendingKeys.push_back(SDL_MOUSE_MIDDLE);
					break;

					case SDL_MOUSE_RIGHT_PRESSED: //  register right mouse code as pressed
						if (keys.find(SDL_MOUSE_RIGHT) == keys.end())
						{
							keys.emplace(SDL_MOUSE_RIGHT, KeyState::Pressed);
							pendingKeys.push_back(SDL_MOUSE_RIGHT);
						}
						else
						{
							keys[SDL_MOUSE_RIGHT] = KeyState::Pressed;
							pendingKeys.push_back(SDL_MOUSE_RIGHT);
						}
					break;
					case SDL_MOUSE_RIGHT_RELEASED: //  register right mouse code as released
						keys[SDL_MOUSE_RIGHT] = KeyState::Released;
						pendingKeys.push_back(SDL_MOUSE_RIGHT);
					break;
				}
			break;
		}
	}

	if (getKeyState(SDL_SCANCODE_K) == KeyState::Pressed) //  enable or disable debug mode if K is pressed
	{
		if (debug)
		{
			Log::info("Disable debug mode");
		}
		else
		{
			Log::info("Enable debug mode");
		}
		debug = !debug;
	}

	if (getKeyState(SDL_SCANCODE_ESCAPE) == KeyState::Pressed) //  quit game if escape is pressed
	{
		isRunning = false;
	}

	int mouse_pos_x, mouse_pos_y;
	SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y); //  register mouse position
	mousePosition = Vector2{ mouse_pos_x * 1.0f, mouse_pos_y * 1.0f };
}

void Game::update(float dt)
{
	//  update actors
	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->update(dt);
	}
	isUpdatingActors = false;

	//  move pending actors to actors
	for (auto pending_actor : pendingActors)
	{
		actors.emplace_back(pending_actor);
	}
	pendingActors.clear();

	//  delete dead actors
	vector<Actor*> dead_actors;
	for (auto actor : actors)
	{
		if (actor->getState() == Actor::ActorState::Dead)
		{
			dead_actors.emplace_back(actor);
		}
	}
	for (auto dead_actor : dead_actors)
	{
		delete dead_actor;
	}
}

void Game::addActor(Actor* actor)
{
	if (isUpdatingActors)
	{
		pendingActors.emplace_back(actor);
	}
	else
	{
		actors.emplace_back(actor);
	}
}

void Game::removeActor(Actor* actor)
{
	auto iter = std::find(begin(pendingActors), end(pendingActors), actor);
	if (iter != end(pendingActors))
	{
		std::iter_swap(iter, end(pendingActors) - 1);
		pendingActors.pop_back();
	}

	iter = std::find(begin(actors), end(actors), actor);
	if (iter != end(pendingActors))
	{
		std::iter_swap(iter, end(actors) - 1);
		actors.pop_back();
	}
}

int Game::getScreenWidth()
{
	return window.getWidth();
}

int Game::getScreenHeight()
{
	return window.getHeight();
}

void Game::render()
{
	renderer.beginDraw();
	renderer.draw();
	if (debug)
	{
		for (auto actor : actors)
		{
			actor->debugComponents(renderer);
		}
	}
	renderer.endDraw();
}