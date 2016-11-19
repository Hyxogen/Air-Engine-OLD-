#include "Vector3f.h"

namespace engine { namespace math {

	Vector3f::Vector3f() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Vector3f::Vector3f(float x) {
		this->x = x;
		this->y = 0;
		this->z = 0;
	}

	Vector3f::Vector3f(float x, float y) {
		this->x = x;
		this->y = y;
		this->z = 0;
	}

	Vector3f::Vector3f(float x, float y, float z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3f Vector3f::multiply(float scalar) const {
		Vector3f out;
		out.x = this->x * scalar;
		out.y = this->y * scalar;
		out.z = this->z * scalar;
		return out;
	}

	Vector3f Vector3f::add(const Vector3f& other) const {
		Vector3f out;
		out.x = this->x + other.x;
		out.y = this->y + other.y;
		out.z = this->z + other.z;
		return out;
	}

	Vector3f Vector3f::subtract(const Vector3f& other) const {
		//TODO change this to the correct way of substracting
		Vector3f out;
		out.x = this->x - other.x;
		out.y = this->y - other.y;
		out.z = this->z - other.z;
		return out;
	}

	Vector3f Vector3f::clamp(float magnitude) const {
		Vector3f out;
		out.x = Clamp(this->x, -magnitude, magnitude);
		out.y = Clamp(this->y, -magnitude, magnitude);
		out.z = Clamp(this->z, -magnitude, magnitude);
		return out;
	}

	Vector3f Vector3f::normalize() const {
		return clamp(1.0f);
	}

	Vector3f Vector3f::invert() const {
		Vector3f out;
		out.x = -this->x;
		out.y = -this->y;
		out.z = -this->z;
		return out;
	}

	float Vector3f::magnitude() const {
		float length = ((pow(this->x, 2.0f) + pow(this->z, 2.0f)));
		return (sqrt(length + (pow(this->y, 2.0f))));
	}

	Vector3f Vector3f::operator-() const {
		return invert();
	}
	
	Vector3f operator+(const Vector3f& left, const Vector3f& right) {
		return left.add(right);
	}

	Vector3f operator-(const Vector3f& left, const Vector3f& right) {
		return left.subtract(right);
	}

	Vector3f operator*(const Vector3f& vector, float scalar) {
		return vector.multiply(scalar);
	}
}}