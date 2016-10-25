#pragma once

#include "..\geometry\Mesh.h"
#include "shaders\Shader.h"

namespace engine { namespace rendering {

	class SimpleRenderer {

	public:
		SimpleRenderer();

		void renderMesh(geometry::Mesh* mesh, graphics::Shader* shader);
	
		void prepareRender();
	};

}}