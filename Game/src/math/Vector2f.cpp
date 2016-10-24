#include "Vector2f.h"

namespace engine { namespace math {

	Vector2f::Vector2f() {
		this->x = 0;
		this->y = 0;
	}

	Vector2f::Vector2f(float x) {
		this->x = x;
		this->y = 0;
	}

	Vector2f::Vector2f(float x, float y) {
		this->x = x;
		this->y = y;
	}

	Vector2f Vector2f::multiply(float scalar) {
		Vector2f out;
		out.x = this->x * scalar;
		out.y = this->y * scalar;
		return out;
	}

	Vector2f Vector2f::add(Vector2f other) {
		Vector2f out;
		out.x = this->x + other.x;
		out.y = this->y + other.y;
		return out;
	}

	Vector2f Vector2f::substract(Vector2f other) {
		Vector2f out;
		out.x = x + (other.x * -1);
		out.y = y + (other.y * -1);
		return out;
	}

	float Vector2f::magnitute() {
		return sqrt((pow(this->x, 2) + pow(this->y, 2)));
	}
}}