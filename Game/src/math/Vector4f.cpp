#include "Vector4f.h"

namespace engine {
	namespace math {

		Vector4f::Vector4f() {
			this->x = 0;
			this->y = 0;
			this->z = 0;
		}

		Vector4f::Vector4f(float x) {
			this->x = x;
			this->y = 0;
			this->z = 0;
		}

		Vector4f::Vector4f(float x, float y) {
			this->x = x;
			this->y = y;
			this->z = 0;
		}

		Vector4f::Vector4f(float x, float y, float z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		Vector4f::Vector4f(float x, float y, float z, float w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		Vector4f Vector4f::multiply(float scalar) const {
			Vector4f out;
			out.x *= scalar;
			out.y *= scalar;
			out.z *= scalar;
			out.w *= scalar;
			return out;
		}

		/*
		Vector4f Vector4f::multiply(const Matrix4f& matrix) const {
			Vector4f out;
			for (int y = 0; y < 4; y++) {
				float o = 0;
				for (int x = 0; x < 4; x++) {
					o += matrix.elements[x + y * 4] * this->vectors[x];
				}
				out.vectors[y] = o;
			}
			return out;
		}
		*/

		Vector4f Vector4f::add(const Vector4f& other) const {
			Vector4f out;
			out.x = this->x + other.x;
			out.y = this->y + other.y;
			out.z = this->z + other.z;
			out.w = this->w + other.w;
			return out;
		}

		Vector4f Vector4f::subtract(const Vector4f& other) const {
			//TODO change this to the correct way of substracting
			Vector4f out;
			out.x = this->x - other.x;
			out.y = this->y - other.y;
			out.z = this->z - other.z;
			out.w = this->w - other.w;
			return out;
		}
	}
}