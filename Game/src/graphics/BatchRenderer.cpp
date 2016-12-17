#include "BatchRenderer.h"

#define DEPRECATED_USAGE

#define MAX_BATCH_SIZE 1563

#ifndef DEPRECATED_USAGE
#pragma message ("The usage of the batchrenderer is discouraged, since it has not been tested very well. If you still want to use it define DEPRECATED_USAGE")
#else
namespace engine { namespace rendering {

	BatchRenderer::BatchRenderer() {

	}

	void BatchRenderer::sumbit(entity::Entity* entity) {
		using namespace entity;
		using namespace math;
		Entity* centity = findIdentical(entity);
		if (centity == nullptr) {
			batch[entity] = std::vector<Matrix4f>({entity->getTransformation()});
		} else {
			batch[centity].push_back(entity->getTransformation());
		}
	}

	entity::Entity* BatchRenderer::findIdentical(entity::Entity* entity) {
		using namespace entity;
		for (auto item = batch.begin(); item != batch.end(); item++) {
			Entity* centity = item->first;
			if (centity->material->getID() == entity->material->getID() && centity->mesh->getVaoID() == entity->mesh->getVaoID()) return centity;
		}
		return nullptr;
	}

	void BatchRenderer::flush() {
		using namespace entity;
		for (auto item = batch.begin(); item != batch.end(); item++) {
			Entity* entity = item->first;

			entity->material->getShader()->loadUnifromMat4fa("transformations", item->second);

			glBindVertexArray(entity->mesh->getVaoID());

			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, entity->mesh->getIboID());
			glEnableVertexAttribArray(0);
			glEnableVertexAttribArray(1);

			entity->material->prepareShader(entity->mesh);

			glDrawElementsInstanced(GL_TRIANGLES, entity->mesh->getIndicesCount(), GL_UNSIGNED_INT, 0, item->second.size());
			glDisableVertexAttribArray(1);
			glDisableVertexAttribArray(0);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
			glBindVertexArray(0);
		}
	}

}}
#endif