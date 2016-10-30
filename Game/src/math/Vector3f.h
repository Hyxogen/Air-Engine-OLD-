#pragma once

#include <iostream>
#include "Mathf.h"

namespace engine { namespace math {

	struct Vector3f {

		float x, y, z;

		Vector3f();

		Vector3f(float x);

		Vector3f(float x, float y);

		Vector3f(float x, float y, float z);

		Vector3f multiply(float scalar) const;

		Vector3f add(const Vector3f& other) const;

		Vector3f subtract(const Vector3f& other) const;

		Vector3f clamp(float magnitude) const;

		Vector3f normalize() const;

		Vector3f invert() const;

		float magnitude() const;

		Vector3f operator-() const;

		friend Vector3f operator+(const Vector3f& left, const Vector3f& right);

		friend Vector3f operator-(const Vector3f& left, const Vector3f& right);

		friend Vector3f operator*(const Vector3f& vector, float scalar);
	};
}}