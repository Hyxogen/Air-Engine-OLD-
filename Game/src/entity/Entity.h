#pragma once
#include <vector>
#include "EntityBehaviour.h"
#include "..\math\Math.h"
#include "..\geometry\Mesh.h"
#include "..\graphics\materials\Material.h"

namespace engine { namespace entity {

	class Entity {
		static std::vector<Entity> entities;
		std::vector<EntityBehaviour*>* behaviours = new std::vector<EntityBehaviour*>(0);
		

	public:
		math::Vector3f position, rotation, scale;
		geometry::Mesh* mesh;
		graphics::Material* material;
		
		~Entity();

		Entity(math::Vector3f position = math::Vector3f(), math::Vector3f rotation = math::Vector3f(), math::Vector3f scale = math::Vector3f(1.0f, 1.0f, 1.0f),
			   geometry::Mesh* mesh = nullptr, graphics::Material* material = nullptr);

		void tick();

		static void tickEntities();

		void addBehaviour(EntityBehaviour& entityBehaviour);

		void deleteBehaviour(EntityBehaviour entityBehaviour);

		math::Matrix4f getTransformation();

		bool hasBehaviour(EntityBehaviour entityBehaviour);

	};

}}