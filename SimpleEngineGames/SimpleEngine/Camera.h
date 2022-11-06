#pragma once
#include "Utils/Vector2.h"

class Camera
{
public:
	Camera();

	void setCamPos(Vector2 camPosP);
	Vector2 getCamPos() const{ return camPos; }

private:
	Vector2 camPos{ 0.0f, 0.0f };
};

