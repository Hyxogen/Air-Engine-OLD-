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

	Vector3f Vector3f::multiply(float scalar) {
		this->x *= scalar;
		this->y *= scalar;
		this->z *= scalar;
		return *this;
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
}}