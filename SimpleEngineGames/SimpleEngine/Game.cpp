#include "Game.h"
#include "Timer.h"
#include "Utils/Log.h"

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

void Game::processInput()
{
	// SDL Event
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			isRunning = false;
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.scancode == SDL_SCANCODE_K)
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
		}
	}

	// Keyboard state
	const Uint8* keyboard_state = SDL_GetKeyboardState(nullptr);
	// Escape: quit game
	if (keyboard_state[SDL_SCANCODE_ESCAPE])
	{
		isRunning = false;
	}

	int mouse_pos_x, mouse_pos_y;

	const Uint32 mouse_state = SDL_GetMouseState(&mouse_pos_x, &mouse_pos_y);

	//  actor input
	isUpdatingActors = true;
	for (auto actor : actors)
	{
		actor->processInput(keyboard_state, mouse_state, mouse_pos_x, mouse_pos_y);
	}
	isUpdatingActors = false;
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