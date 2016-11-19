#pragma once

#include "../shaders/Shader.h"
#include "../../geometry/Mesh.h"

namespace engine { namespace graphics {

	class Material {

	 protected:
		Shader* shader;

		Material(Shader* shader);


	public:
		inline Shader* getShader() { return shader; }

		virtual void Material::prepareShader(geometry::Mesh* mesh);
		
		void enable();

		void disable();
	};

}}