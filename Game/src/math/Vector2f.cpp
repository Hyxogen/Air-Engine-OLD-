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

	Vector2f Vector2f::multiply(float scalar) const {
		Vector2f out;
		out.x = this->x * scalar;
		out.y = this->y * scalar;
		return out;
	}

	Vector2f Vector2f::add(Vector2f other) const {
		Vector2f out;
		out.x = this->x + other.x;
		out.y = this->y + other.y;
		return out;
	}

	Vector2f Vector2f::substract(Vector2f other) const {
		Vector2f out;
		out.x = x + (other.x * -1);
		out.y = y + (other.y * -1);
		return out;
	}

	float Vector2f::magnitude() const{
		return (sqrt((pow(this->x, 2.0f) + (pow(this->y, 2.0f)))));
	}

	Vector2f Vector2f::invert() const {
		Vector2f out;
		out.x = -this->x;
		out.y = -this->y;
		return out;
	}

	Vector2f Vector2f::clamp(float magnitude) const {
		Vector2f out;
		out.x = Clamp(this->x, -magnitude, magnitude);
		out.y = Clamp(this->y, -magnitude, magnitude);
		return out;
	}

	Vector2f Vector2f::normalize() const {
		return clamp(1.0f);
	}
	
	Vector2f Vector2f::operator-() const {
		return invert();
	}

	Vector2f operator+(const Vector2f& left, const Vector2f& right) {
		return left.add(right);
	}

	Vector2f operator-(const Vector2f& left, const Vector2f& right) {
		return left.substract(right);
	}

	Vector2f operator*(const Vector2f& vector, float scalar) {
		return vector.multiply(scalar);
	}
}}