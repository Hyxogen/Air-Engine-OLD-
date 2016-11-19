#include "SimpleRenderer.h"

namespace engine {
	namespace rendering {
		 
		SimpleRenderer::SimpleRenderer() {

		}

#ifdef OBSOLETE
		void SimpleRenderer::renderMesh(geometry::Mesh* mesh, graphics::Shader* shader) {
			glBindVertexArray(mesh->getVaoID());

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->getIboID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);
			
			glActiveTexture(GL_TEXTURE0);
			
			glBindTexture(GL_TEXTURE_2D, mesh->getTexture()->getTextureID());
			
			shader->loadUniformTexture("textureSampler", 0);
			
			glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
#else
		void SimpleRenderer::renderMesh(geometry::Mesh* mesh, graphics::Material* material) {
			glBindVertexArray(mesh->getVaoID());

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mesh->getIboID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);

			material->prepareShader(mesh);

			glDrawElements(GL_TRIANGLES, mesh->getIndicesCount(), GL_UNSIGNED_INT, 0);
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
#endif

		void SimpleRenderer::prepareRender() {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.0f, 1.0f, 1.0f, 1.0f);

		}

	}
}