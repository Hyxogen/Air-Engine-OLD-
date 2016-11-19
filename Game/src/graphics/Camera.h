#pragma once

#include "../math/Math.h"

namespace engine { namespace graphics {

	struct Camera {

		math::Matrix4f projection;
		math::Vector3f position, rotation;

		Camera(math::Matrix4f projection);

		inline math::Matrix4f getProjectionMat() { return projection; };

		math::Matrix4f getTransformation();
	};

}}