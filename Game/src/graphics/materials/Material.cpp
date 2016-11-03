#include "Material.h"

namespace engine { namespace graphics {

	Material::Material(Shader* shader) {
		this->shader = shader;
	}

	void Material::enable() {
		this->shader->bind();
	}

	void Material::disable() {
		this->shader->unBind();
	}

	void Material::prepareShader(geometry::Mesh* mesh) {

	}

	void Material::enable() {
		this->shader->bind();
	}

	void Material::disable() {
		this->shader->unBind();
	}
}}