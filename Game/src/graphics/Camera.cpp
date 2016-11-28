#include "Camera.h"

#ifdef DEPRECATED_CAMERA
#pragma message ("Warning this uses the deprecated 'entity' system!")
namespace engine { namespace graphics {

	Camera::Camera(math::Matrix4f projection) {
		this->projection = projection;
		this->position = math::Vector3f();
		this->rotation = math::Vector3f();
	}

	math::Matrix4f Camera::getTransformation() {
		math::Matrix4f rotation = math::Matrix4f::rotation(math::Vector3f(1.0f, 0.0f, 0.0f), -this->rotation.x);
		
		rotation = rotation * math::Matrix4f::rotation(math::Vector3f(0.0f, 1.0f, 0.0f), -this->rotation.y);
		rotation = rotation * math::Matrix4f::rotation(math::Vector3f(0.0f, 0.0f, 1.0f), -this->rotation.z);

		return math::Matrix4f::transformation(rotation, math::Matrix4f::identity(), math::Matrix4f::translation(-position));
	}

}}
#endif