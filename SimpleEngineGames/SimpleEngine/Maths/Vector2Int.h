#pragma once
#include <string>

enum FloatToIntType;

struct Vector2Int
{
	int x{ 0 };
	int y{ 0 };

	static const Vector2Int zero;
	static const Vector2Int unitX;
	static const Vector2Int unitY;

	Vector2Int() = default;
	Vector2Int(int xP, int yP) : x{ xP }, y{ yP } {}
	Vector2Int(const class Vector2 vec2, FloatToIntType floatToIntType);

	void set(float xP, float yP);
	float lengthSq() const;
	float length() const;
	

	friend Vector2Int operator+(const Vector2Int& left, const Vector2Int& right)
	{
		return { left.x + right.x, left.y + right.y };
	}

	friend Vector2Int operator-(const Vector2Int& left, const Vector2Int& right)
	{
		return { left.x - right.x, left.y - right.y };
	}

	friend Vector2Int operator*(const Vector2Int& vec, float scalar)
	{
		return { vec.x * scalar, vec.y * scalar };
	}

	friend Vector2Int operator*(float scalar, const Vector2Int& vec)
	{
		return { vec.x * scalar, vec.y * scalar };
	}

	Vector2Int& operator+=(const Vector2Int& right)
	{
		x += right.x;
		y += right.y;
		return *this;
	}

	Vector2Int& operator-=(const Vector2Int& right)
	{
		x -= right.x;
		y -= right.y;
		return *this;
	}

	Vector2Int& operator*=(const float scalar)
	{
		x *= scalar;
		y *= scalar;
		return *this;
	}

	Vector2Int operator-() const
	{
		return Vector2Int(-x, -y);
	}

	std::string toString() const
	{
		return std::to_string(x) + "  " + std::to_string(y) + " \n";
	}
};



enum FloatToIntType
{
	Round,
	Floor,
	Ceil
};