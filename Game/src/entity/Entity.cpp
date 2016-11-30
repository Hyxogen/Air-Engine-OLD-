#include "Entity.h"

namespace engine { namespace entity {

	std::vector<Entity> Entity::entities;

	Entity::Entity(math::Vector3f position, math::Vector3f rotation, math::Vector3f scale, geometry::Mesh* mesh, graphics::Material* material) {
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
		this->mesh = mesh;
		this->material = material;
		entities.push_back(*this);
	}

	Entity::~Entity() {
		delete this->behaviours;
	}

	void Entity::tickEntities() {
		for (int i = 0; i < entities.size(); i++) {
			entities[i].tick();
		}
	}
	
	void Entity::tick() {
		for (int i = 0; i < this->behaviours->size(); i++) {
			behaviours->at(i)->tickBehaviour();
		}
	}

	void Entity::addBehaviour(EntityBehaviour& entityBehaviour) {
		if (hasBehaviour(entityBehaviour)) return;
		this->behaviours->push_back(&entityBehaviour);
	}

	void Entity::deleteBehaviour(EntityBehaviour entityBehaviour) {
		for (int i = 0; i < behaviours->size(); i++) {
			if (typeid(behaviours[i]) == typeid(entityBehaviour)) {
				behaviours->erase(behaviours->begin() + i);
				return;
			}
		}
	}

	bool Entity::hasBehaviour(EntityBehaviour entityBehaviour) {
		for (int i = 0; i < behaviours->size(); i++) {
			if (typeid(behaviours[i]) == typeid(entityBehaviour)) 
				return true;
		}
		return false;
	}

	math::Matrix4f Entity::getTransformation() {
		using namespace math;
		Matrix4f translation = Matrix4f::translation(position);
		Matrix4f scaleMatrix = Matrix4f::scale(scale);

		Matrix4f xRotation = Matrix4f::rotation(Vector3f(1.0f, 0.0f, 0.0f), rotation.x);
		Matrix4f xyRotation = xRotation * Matrix4f::rotation(Vector3f(0.0f, 1.0f, 0.0f), rotation.y);
		Matrix4f fullRotation = xyRotation * Matrix4f::rotation(Vector3f(0.0f, 0.0f, 1.0f), rotation.z);

		return Matrix4f::transformation(fullRotation, scaleMatrix, translation);
	}

}}