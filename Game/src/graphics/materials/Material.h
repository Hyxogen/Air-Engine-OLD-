#pragma once

#include "../shaders/Shader.h"
#include "../../geometry/Mesh.h"

namespace engine { namespace graphics {

	class Material {

	 protected:
		Shader* shader;

		Material(Shader* shader);


	public:
		virtual void Material::prepareShader(geometry::Mesh* mesh) = 0;
		
		void enable();

		void disable();
	};

}}