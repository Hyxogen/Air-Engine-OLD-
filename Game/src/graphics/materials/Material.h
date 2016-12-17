#pragma once

#include "../shaders/Shader.h"
#include "../../geometry/Mesh.h"

namespace engine { namespace graphics {

		class Material {

		protected:
			static unsigned int count;
			const unsigned int id = 0;
			Shader* shader;

			Material(Shader* shader);
		public:
			virtual void Material::prepareShader(geometry::Mesh* mesh);

			void enable();

			void disable();

			inline int getID() const { return id; }

			inline Shader* getShader() const { return shader; }
		};

}}