#pragma once

#include "Math.h"

namespace engine {namespace math {

	struct Vector2f {

		union {
			float x, y;
			
			struct {
				float vectors[2];
			};
		};

		Vector2f();

		Vector2f(float x);

		Vector2f(float x, float y);

		Vector2f multiply(float scalar);

		Vector2f add(Vector2f other);

		Vector2f substract(Vector2f other);

		float magnitute();
	};

}}