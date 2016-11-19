#pragma once

#include "..\geometry\Mesh.h"
#include "materials/Material.h"

namespace engine { namespace rendering {

	class SimpleRenderer {

	public:
		SimpleRenderer();

		void renderMesh(geometry::Mesh* mesh, graphics::Material* material);
	
		void prepareRender();
	};

}}