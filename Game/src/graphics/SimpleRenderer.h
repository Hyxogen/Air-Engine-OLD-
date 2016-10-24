#pragma once

#include "..\geometry\Mesh.h";

namespace engine { namespace rendering {

	class SimpleRenderer {

	public:
		SimpleRenderer();

		void renderMesh(geometry::Mesh &mesh);
	
		void prepareRender();
	};

}}