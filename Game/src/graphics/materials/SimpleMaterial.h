#pragma once

#include <GL\glew.h>
#include "Material.h"
#include "../Texture.h"

namespace engine { namespace graphics {

	class SimpleMaterial : public Material {

	public:
		Texture* texture;

		SimpleMaterial(Shader* shader);

		SimpleMaterial(Shader* shader, Texture* texture);

	public:
		virtual void prepareShader(geometry::Mesh* mesh) = 0;

	public:
		inline Texture* getTexture() { return texture; }
	};

}}