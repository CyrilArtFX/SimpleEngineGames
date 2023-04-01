#pragma once

class Game;

class IScene
{
public:
	virtual ~IScene() {}

	virtual void load(Game* game) = 0;
};

