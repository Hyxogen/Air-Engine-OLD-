#pragma once

#include <iostream>
#include "Matrix4f.h"

namespace engine {
	namespace math {

		struct Vector4f {

			union {
				struct {
					float x, y, z, w;
				};
				float vectors[3];
			};

			Vector4f();

			Vector4f(float x);

			Vector4f(float x, float y);

			Vector4f(float x, float y, float z);

			Vector4f(float x, float y, float z, float w);

			Vector4f multiply(float scalar) const;

#ifdef USAGE_EXPERIMENTAL
			Vector4f multiply(const Matrix4f& matrix) const;
#endif
			Vector4f add(const Vector4f& other) const;

			Vector4f subtract(const Vector4f& other) const;

		};

	}
}
