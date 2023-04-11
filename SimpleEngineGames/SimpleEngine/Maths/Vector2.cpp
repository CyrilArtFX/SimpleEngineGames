#include "Vector2.h"
#include "Maths.h"
#include "Vector3.h"

const Vector2 Vector2::zero{ 0.0f, 0.0f };
const Vector2 Vector2::unitX{ 1.0f, 0.0f };
const Vector2 Vector2::unitY{ 0.0f, 1.0f };

Vector2::Vector2(const Vector3 vec3)
{
	x = vec3.x;
	y = vec3.y;
}

void Vector2::set(float xP, float yP)
{
	x = xP;
	y = yP;
}

float Vector2::lengthSq() const
{
	return x * x + y * y;
}

float Vector2::length() const
{
	return Maths::sqrt(lengthSq());
}

void Vector2::normalize()
{
	float len = length();
	x /= len;
	y /= len;
}

void Vector2::clampMagnitude(float magnitude)
{
	float len = length();
	if (len <= magnitude) return;
	x /= len;
	y /= len;
	x *= magnitude;
	y *= magnitude;
}
