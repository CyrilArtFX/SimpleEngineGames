#pragma once

class Game;

class Scene
{
public:
	Scene();
	virtual ~Scene();
	Scene(const Scene&) = delete;
	Scene& operator=(const Scene&) = delete;

	virtual void load(Game* game);
};

