#include "Entity.h"

namespace engine { namespace entity {

	std::vector<Entity> Entity::entities;

	Entity::Entity(math::Vector3f position, math::Vector3f rotation, math::Vector3f scale) {
		this->position = position;
		this->rotation = rotation;
		this->scale = scale;
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

}}