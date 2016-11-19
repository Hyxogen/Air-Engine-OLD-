#include "SimpleMaterial.h"

namespace engine { namespace graphics {

	SimpleMaterial::SimpleMaterial(Shader* shader) : Material(shader) {

	}

	SimpleMaterial::SimpleMaterial(Shader* shader, Texture* texture) : Material(shader) {
		this->texture = texture;
	}

	void SimpleMaterial::prepareShader(geometry::Mesh* mesh) {
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, this->texture->getTextureID());

		this->shader->loadUniformTexture("textureSampler", 0);
	}

}}