#pragma once

#ifdef DEPRECATED_CAMERA
#pragma message ("This is the deprecated 'entity' component system and is most likley to not be supported and to be deleted!")

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
#endif