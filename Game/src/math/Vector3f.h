#pragma once

#include <iostream>

namespace engine { namespace math {

	struct Vector3f {

		float x, y, z;

		Vector3f();

		Vector3f(float x);

		Vector3f(float x, float y);

		Vector3f(float x, float y, float z);

		Vector3f multiply(float scalar);

		Vector3f add(const Vector3f& other) const;

		Vector3f subtract(const Vector3f& other) const;

		float magnitude();
	};
}}