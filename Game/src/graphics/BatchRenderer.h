#pragma once

#include <vector>
#include <map>
#include "..\geometry\Mesh.h"
#include "..\entity\Entity.h"
#include "..\math\Math.h"

namespace engine { namespace rendering {

	class BatchRenderer {

		std::unordered_map<entity::Entity*, std::vector<math::Matrix4f>> batch;

	public:
		BatchRenderer();

		void sumbit(entity::Entity* entity);

		void flush();

		void clear();

	private:
		entity::Entity* findIdentical(entity::Entity* entity);
	};

}}