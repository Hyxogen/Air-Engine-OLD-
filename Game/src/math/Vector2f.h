#pragma once

#include "Mathf.h"

namespace engine {namespace math {

	struct Vector2f {

		union {
			struct {
				float vectors[2];
			};

			struct {
				float x, y;
			};
		};

		Vector2f();

		Vector2f(float x);

		Vector2f(float x, float y);

		Vector2f multiply(float scalar) const;

		Vector2f add(Vector2f other) const;

		Vector2f substract(Vector2f other) const;

		Vector2f clamp(float magnitude) const;

		Vector2f normalize() const;

		Vector2f invert() const;

		float magnitude() const;

		Vector2f operator-() const;

		friend Vector2f operator+(const Vector2f& left, const Vector2f& right);

		friend Vector2f operator-(const Vector2f& left, const Vector2f& right);

		friend Vector2f operator*(const Vector2f& vector, float scalar);
	};

}}