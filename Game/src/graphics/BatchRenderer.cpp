#include "BatchRenderer.h"

namespace engine { namespace rendering {

	BatchRenderer::BatchRenderer() {

	}

	void BatchRenderer::sumbit(entity::Entity* entity) {
	}

	entity::Entity* BatchRenderer::findIdentical(entity::Entity* entity) {
		using namespace entity;
		for (auto item = batch.begin(); item != batch.end(); item++) {
			Entity* ientity = item->first;
			if (ientity->material->getID() == entity->material->getID() && ientity->mesh->getVaoID() == entity->mesh->getVaoID()) return ientity;
		}
		return nullptr;
	}

}}